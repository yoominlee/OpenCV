#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <array>
int main(int argc, char const *argv[])
{
    cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/lenna.png",0);

    cv::imshow("image", image);

    printf("type: %d \n",  image.type());

    printf("channels: %d \n\n",  image.channels());


    printf("width: %d / height: %d \n\n", image.size().width, image.size().height);


    // printf("0,0: %d \n",  image.at<uchar>(0,0));
    // printf("30,20: %d \n",  image.at<uchar>(30,20));

    // cv::Mat count = cv::Mat::zeros(15, 17, 0);
    std::array<int, 255> count;
    int max = 0;
    for (int i = 0; i < count.size(); i++)
    {
        count.at(i) = 0;
    }

    printf("count.size(): %d \n",  count.size());
    printf("count 0: %d \n",  count[0]);
    printf("count 254: %d \n\n",  count[254]);

    for(int i=0; i<image.size().height; i++){
        for (int j = 0; j < image.size().width; j++){
            int data = image.at<uchar>(i,j);
            // printf("data: %d \n",  data);

            // count.at<uchar>(data,0) = count.at<uchar>(data,0) + 1;
            count.at(data) = count.at(data) + 1;
            // printf("count.at(data): %d \n",  count.at(data));

            // CHECK MAX
            if (max<count.at(data))
            {
                max = count.at(data);

            }
            
        }
    }
    
    printf("max: %d \n\n", max);


    printf("count 0-9: %d %d %d %d %d %d \n", count.at(100), count[130], count[50], count[56], count[19], count[200]);

    cv::Mat hi = cv::Mat(650, 255*2, image.type());

    for (int i = 0; i < count.size(); i++)
    {
        cv::line(hi, cv::Point(i*2,hi.size().height), cv::Point(i*2,650-count.at(i)/10), 255, 1);
    }
    


    cv::imshow("hi", hi);

    cv::waitKey(0);

    return 0;
}