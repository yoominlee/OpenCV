#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{

    int row = 800;
    int col = 800;
    cv::Mat t1 = cv::Mat(row, col, CV_8UC3, cv::Scalar(255,255,255));

    ///// CIRCLE ///// 
    // cv::circle(cv::Mat src, cv::Point(x, y), radius, cv::Scalar(b, g, r), thickness, lineType, shift)

    // one circle
    cv::circle(t1, cv::Point(400, 400), 80, cv::Scalar(100, 100, 100), 5);

    // filled circle
    cv::circle(t1, cv::Point(400, 400), 10, cv::Scalar(0, 0, 0), -1);


    // circle to line
    for(int i=0; i<400; i++){
        cv::circle(t1, cv::Point(i*2, 400), 2, cv::Scalar(0, 0, 0), 3);
    }

    ///// LINE /////
    // cv::line(cv::Mat src, cv::Point(x, y), cv::Point(x2, y2), cv::Scalar(b, g, r), thickness, lineType, shift)

    // blue hori
    cv::line(t1, cv::Point(0,400), cv::Point(800,400), cv::Scalar(255, 0, 0), 1);

    // red vertical
    cv::line(t1, cv::Point(400,0), cv::Point(400,800), cv::Scalar(0, 0, 200), 1);



    cv::imshow("t1", t1);
    cv::waitKey(0);

    return 0;
}
