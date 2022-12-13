#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
void onMouse(int event, int x, int y, int flags, void* userdata);
int d_x, d_y, u_x, u_y;
    cv::Mat image, img_big;
int main(int argc, char const *argv[])
{
    image = cv::imread("/home/cona/git/OpenCV/src/skyline.jpg");
    resize(image, img_big, cv::Size(220*5, 88*5));

    cv::imshow("image", img_big);

    cv::setMouseCallback("image", onMouse);

    cv::waitKey(0);

    return 0;
}
void onMouse(int event, int x, int y, int flags, void*){
    if (event==cv::EVENT_LBUTTONDOWN)
    {
        d_x = x;
        d_y = y;
        printf("d[x: %d / y: %d]\n", d_x, d_y);
    }
    if (event==cv::EVENT_LBUTTONUP)
    {
        if (u_x<0)
        {
            u_x=0;
        }
        if (u_y<0)
        {
            u_y=0;
        }
        
        u_x = x;
        u_y = y;
        printf("u[x: %d / y: %d]\n", u_x, u_y);
        
        if(d_x>u_x){
            int temp = u_x;
            u_x = d_x;
            d_x = temp;
        }
        if(d_y>u_y){
            int temp1 = u_y;
            u_y = d_y;
            d_y = temp1;
        }
        printf("u_y-d_y: %d / u_x-d_x: %d]\n", u_y-d_y, u_x-d_x);

        cv::Mat roi_imshow = cv::Mat(u_y-d_y, u_x-d_x, img_big.type(), cv::Scalar(0,0,0));
        printf("roi_imshow.size().width: %d / roi_imshow.size().height: %d]\n", roi_imshow.size().width, roi_imshow.size().height);

    for(int i=0; i<roi_imshow.size().height; i++){
        for (int j = 0; j < roi_imshow.size().width; j++)
        {
            roi_imshow.at<cv::Vec3b>(i,j)[0] = img_big.at<cv::Vec3b>(i+d_y,j+d_x)[0];
            roi_imshow.at<cv::Vec3b>(i,j)[1] = img_big.at<cv::Vec3b>(i+d_y,j+d_x)[1];
            roi_imshow.at<cv::Vec3b>(i,j)[2] = img_big.at<cv::Vec3b>(i+d_y,j+d_x)[2];
        }
    }
        // cv::destroyWindow("image");

        cv::imshow("roi_image", roi_imshow);
    }
    // if (event==cv::EVENT_RBUTTONDOWN)
    // {
    //     cv::imshow("image", img_big);

    // }
}