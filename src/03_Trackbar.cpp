#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
cv::Mat image;
cv::Mat new_image;
void on_level_change(int pos, void* userdata);
int main(int argc, char const *argv[])
{

    image = cv::imread("/home/cona/git/OpenCV/src/bird.jpeg");

    // cv::Mat new_image = cv::Mat::zeros( image.size(), image.type() );


    cv::imshow("image", image);

    cv::createTrackbar("level", "image", 0, 200, on_level_change, (void*)&image);
    // cv::createTrackbar("level", "image", 0, 200, on_level_change);

    cv::waitKey(0);


    return 0;
}

void on_level_change(int pos, void * userdata)
{
    cv::Mat result;

    new_image = cv::Mat(image.size().width, image.size().height, image.type(), cv::Scalar(pos, pos, pos));
    cv::addWeighted(image, 0.5, new_image, 0.5, 0.0, result);


    image = image*pos;
    // cv::Mat img = *(cv::Mat*)userdata * image;
    
    // img.setTo(pos);
    cv::imshow("result", result);
}