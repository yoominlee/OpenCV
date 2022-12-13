#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
void draw(cv::Mat imsh, cv::Mat blur, int blur_size, int x_offset, int y_offset, bool b);
int main(int argc, char const *argv[])
{
    // 1. Get image
    // 1-0) image (original)
    cv::Mat image = cv::imread("/home/cona/git/OpenCV/src/grass.jpg");

    // 1-1) img_small (small)
    cv::Mat img_small;
    resize(image, img_small, cv::Size(300, 200));

    // 1-2) output_blur (blur)
    int blur_size = 3;
    cv::Mat output_blur;
    cv::blur(img_small, output_blur, cv::Size(blur_size,blur_size));

    // 1-3) output_blur_2 (blur)
    int blur_size_2 = 6;
    cv::Mat output_blur_2;
    cv::blur(img_small, output_blur_2, cv::Size(blur_size_2,blur_size_2));

    // 1-4) output_GaussianBlur (GaussianBlur)
    int G_blur_size = 1;
    cv::Mat output_GaussianBlur;
    cv::GaussianBlur(img_small, output_GaussianBlur, cv::Size(G_blur_size,G_blur_size), 0);
    
    // 1-5) output_GaussianBlur_2 (GaussianBlur)img_blur, Size(7, 7)
    int G_blur_size_2 = 3 ;
    cv::Mat output_GaussianBlur_2;
    cv::GaussianBlur(img_small, output_GaussianBlur_2, cv::Size(G_blur_size_2,G_blur_size_2), 0);

    // 1-6) output_GaussianBlur_3 (GaussianBlur)
    int G_blur_size_3 = 5;
    cv::Mat output_GaussianBlur_3;
    cv::GaussianBlur(img_small, output_GaussianBlur_3, cv::Size(G_blur_size_3,G_blur_size_3), 0);

    // 1-7) imsh (imshow mat)
    cv::Mat imsh = cv::Mat(img_small.size().height*3, img_small.size().width*2, CV_8UC3, cv::Scalar(255,255,255)); //800*600 <- img_small.size().width, img_small.size().height*2


    printf("[[ image (original) ]]\nrows: %d / cols: %d\n", image.rows, image.cols);
    printf("width: %d / height: %d / type: %d \n\n", image.size().width, image.size().height, image.type());

    printf("[[ img_small (size change) ]]\nrows: %d / cols: %d\n", img_small.rows, img_small.cols);
    printf("width: %d / height: %d / type: %d \n\n", img_small.size().width, img_small.size().height, img_small.type());

    printf("[[ output_blur (blur) ]]\nrows: %d / cols: %d\n", output_blur.rows, output_blur.cols);
    printf("width: %d / height: %d / type: %d \n\n", output_blur.size().width, output_blur.size().height, output_blur.type());

    printf("[[ output_GaussianBlur (blur) ]]\nrows: %d / cols: %d\n", output_GaussianBlur.rows, output_GaussianBlur.cols);
    printf("width: %d / height: %d / type: %d \n\n", output_GaussianBlur.size().width, output_GaussianBlur.size().height, output_GaussianBlur.type());


    printf("[[ imsh (imshow size) ]]\nrows: %d / cols: %d\n", imsh.rows, imsh.cols);
    printf("width: %d / height: %d / type: %d \n\n", imsh.size().width, imsh.size().height, imsh.type());

    int x_offset = 0;
    int y_offset = 0;

    // 2. imshow
    // 2-1) original img
    for(int i=0; i<img_small.size().height; i++){
        for (int j = 0; j < img_small.size().width; j++)
        {
            imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[0] = img_small.at<cv::Vec3b>(i,j)[0];
            imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[1] = img_small.at<cv::Vec3b>(i,j)[1];
            imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[2] = img_small.at<cv::Vec3b>(i,j)[2];
        }
    }
    cv::putText(imsh, "original", cv::Point(10, 20),cv::FONT_HERSHEY_PLAIN, 0.8, (255,0,0),0.5,cv::LINE_AA);

    // 2-2) blur img
    x_offset = 0;
    y_offset = img_small.size().height;
    // for(int i=0; i<output_blur.size().height; i++){
    //     for (int j = 0; j < output_blur.size().width; j++)
    //     {
    //         imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[0] = output_blur.at<cv::Vec3b>(i,j)[0];
    //         imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[1] = output_blur.at<cv::Vec3b>(i,j)[1];
    //         imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[2] = output_blur.at<cv::Vec3b>(i,j)[2];
    //     }
    // }
    // cv::putText(imsh, "blur [" + std::to_string(blur_size) + "]", cv::Point(10 + x_offset, 20 + y_offset),cv::FONT_HERSHEY_PLAIN, 0.8, (255,0,0),0.5,cv::LINE_AA);

    draw(imsh, output_blur, blur_size, x_offset, y_offset, true);

    // 2-3) blur img 2
    x_offset = 0;
    y_offset = img_small.size().height*2;
    
    draw(imsh, output_blur_2, blur_size_2, x_offset, y_offset, true);

    // 2-4) GaussianBlur img
    x_offset = img_small.size().width;
    y_offset = 0;
    
    draw(imsh, output_GaussianBlur, G_blur_size, x_offset, y_offset, false);

    // 2-4) GaussianBlur img
    x_offset = img_small.size().width;
    y_offset = img_small.size().height;

    draw(imsh, output_GaussianBlur_2, G_blur_size_2, x_offset, y_offset, false);

    // 2-4) GaussianBlur img
    x_offset = img_small.size().width;
    y_offset = img_small.size().height*2;

    draw(imsh, output_GaussianBlur_3, G_blur_size_3, x_offset, y_offset, false);


    // for(int i=0; i<image.size().height; i++){
    //     uchar* p1 = image.ptr<uchar>(i);
    //     for (int j = 0; j < image.size().width; j++)
    //     {
    //         imsh.ptr<uchar>(i)[j] = p1[j];
    //     }
    // }

    // for(int i=0; i<image.size().height; i++){
    //     uchar* p1 = image.ptr<uchar>(i);
    //     for (int j = 0; j < image.size().width; j++)
    //     {
    //         imsh.ptr<uchar>(i+image.size().height)[j] = p1[j];
    //     }
    // }

    cv::imshow("image", imsh);

    cv::waitKey(0);

    return 0;
}
void draw(cv::Mat imsh, cv::Mat blur, int blur_size, int x_offset, int y_offset, bool notGau){

    for(int i=0; i<blur.size().height; i++){
        for (int j = 0; j < blur.size().width; j++)
        {
            imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[0] = blur.at<cv::Vec3b>(i,j)[0];
            imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[1] = blur.at<cv::Vec3b>(i,j)[1];
            imsh.at<cv::Vec3b>(i+y_offset,j+x_offset)[2] = blur.at<cv::Vec3b>(i,j)[2];
        }
    }
    if(notGau==true){
        cv::putText(imsh, "blurv [" + std::to_string(blur_size) + "]", cv::Point(10 + x_offset, 20 + y_offset),cv::FONT_HERSHEY_PLAIN, 0.8, (255,0,0),0.5,cv::LINE_AA);
    }else{
        cv::putText(imsh, "GaussianBlur [" + std::to_string(blur_size) + "]", cv::Point(10 + x_offset, 20 + y_offset),cv::FONT_HERSHEY_PLAIN, 0.8, (255,0,0),0.5,cv::LINE_AA);
    }

}