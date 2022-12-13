#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
void onMouse(int event, int x, int y, int flags, void* userdata);
int main(int argc, char const *argv[])
{
    cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/skyline.jpg");
    cv::Mat img_big;
    resize(image, img_big, cv::Size(220*5, 88*5));


    cv::imshow("image", img_big);

    cv::setMouseCallback("image", onMouse);

    cv::waitKey(0);

    return 0;
}
void onMouse(int event, int x, int y, int flags, void*){
    if (event==cv::EVENT_FLAG_LBUTTON)
    {
    printf("[x: %d / y: %d]\n", x, y);
    }
    
}