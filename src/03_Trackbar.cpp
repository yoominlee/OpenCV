#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
cv::Mat image;
cv::Mat new_image;
void on_level_change(int pos, void* userdata);
int main(int argc, char const *argv[])
{

    image = cv::imread("/home/cona/git/OpenCV/src/bird.jpeg",1);

    printf("image.size().width: %d \n", image.size().width);
    printf("image.size().height: %d \n", image.size().height);
    printf("image.type(): %d \n", image.type());

    // cv::Mat new_image = cv::Mat::zeros( image.size(), image.type() );


    cv::imshow("image", image);

    cv::createTrackbar("level", "image", 0, 100, on_level_change, (void*)&image);
    // cv::createTrackbar("level", "image", 0, 200, on_level_change);

    cv::waitKey(0);


    return 0;
}

void on_level_change(int pos, void * userdata)
{
    cv::Mat result;
    printf("%d \n",pos);

    printf("image.size().width: %d \n", image.size().width);
    printf("image.size().height: %d \n", image.size().height);
    printf("image.type(): %d \n", image.type());


    new_image = cv::Mat(image.size().width, image.size().height, CV_8UC3, cv::Scalar(1, 1, 1));
    float percent = pos/100 + 0.01;

    printf("percent: %f \n1-percent: %f", percent, 1-percent);


    cv::addWeighted(image, 1-percent, new_image, percent, 0.0, result);


    // image = image*pos;
    // cv::Mat img = *(cv::Mat*)userdata * image;
    
    // img.setTo(pos);
    cv::imshow("result", result);
}