#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
int main(int argc, char const *argv[])
{
    cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/lenna.png");

    cv::imshow("image", image);

    // cv::Rect img_all_rect = cv::Rect(0,0,image.size().width,image.size().height);
    cv::Rect roi = cv::Rect(0,image.size().height/2,image.size().width,image.size().height/2);


    printf("[[ image (original) ]]\nrows: %d / cols: %d\n", image.rows, image.cols);
    printf("width: %d / height: %d / type: %d \n\n", image.size().width, image.size().height, image.type());


    cv::Mat roi_imshow = cv::Mat(roi.height, roi.width, image.type(), cv::Scalar(0,0,0));


    printf("[[ roi_imshow (roi) ]]\nrows: %d / cols: %d\n", roi_imshow.rows, roi_imshow.cols);
    printf("width: %d / height: %d / type: %d \n\n", roi_imshow.size().width, roi_imshow.size().height, roi_imshow.type());
    
    printf("roi.x: %d / roi.y: %d \n\n", roi.x, roi.y);


    for(int i=0; i<roi.size().height; i++){
        for (int j = 0; j < roi.size().width; j++)
        {
            roi_imshow.at<cv::Vec3b>(i,j)[0] = image.at<cv::Vec3b>(i+roi.y,j+roi.x)[0];
            roi_imshow.at<cv::Vec3b>(i,j)[1] = image.at<cv::Vec3b>(i+roi.y,j+roi.x)[1];
            roi_imshow.at<cv::Vec3b>(i,j)[2] = image.at<cv::Vec3b>(i+roi.y,j+roi.x)[2];
        }
    }

    cv::imshow("roi", roi_imshow);

    cv::waitKey(0);

    return 0;
}