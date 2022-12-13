#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
void on_level_change(int pos, void* userdata);
int main(int argc, char const *argv[])
{
    // Color
    // cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/grass.jpg");
    
    // Grayscale
    // cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/grass.jpg", 0);
    

    // // Grayscale and image size 1/2
    // cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/grass.jpg", 16);

    // // 이미지 크기 데이터 가져오기
	// cv::Size size = image.size();

	// std::cout << size.height << std::endl;
	// std::cout << size.width << std::endl;

    // cv::imshow("image", image);

    // cv::waitKey(0);

    /////////////////////////////////////////////////////////////////////////////////

    cv::Mat result;
    cv::Mat mask_image = cv::imread("/home/cona/git/OpenCV/src/mask.jpg");

	cv::Size size = mask_image.size();

	std::cout << size.height << std::endl;
	std::cout << size.width << std::endl;


    cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/bird.jpeg");


	size = image.size();

	std::cout << size.height << std::endl;
	std::cout << size.width << std::endl;

    cv::addWeighted(image, 0.5, mask_image, 0.5, 0.0, result);

    cv::imshow("result", result);

    cv::waitKey(0);


    return 0;
}

