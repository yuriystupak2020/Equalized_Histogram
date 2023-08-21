#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <vector>

using namespace cv;
using namespace std;


int main()
{
    /*
    string image_path1 = "night_shore.jpg";

    Mat image1 = imread(image_path1, IMREAD_COLOR);
    resize(image1, image1, { 500,500 }, 0, 0, cv::INTER_NEAREST);
*/
  VideoCapture cap("VID_20230623.mp4");
  if(!cap.isOpened()){
    std::cout << "Error opening video stream or file" << endl;
    return -1;
  }

/*
    MatND histogram;
    int histSize = 256;
    const int* channel_numbers = {0};
    float channel_range[] = {0.0, 256.0};
    const float* channel_ranges = channel_range;
    int number_bins = histSize;

    calcHist(&image3, 1, 0, Mat(), histogram, 1, &number_bins, &channel_ranges);
*/
    Mat image1;
    while(1){
        cap >> image1;
        if (image1.empty()) break;

        resize(image1, image1, { 500,500 }, 0, 0, cv::INTER_NEAREST);
        cvtColor( image1, image1, COLOR_BGR2GRAY );
        Mat histEqualized;
        equalizeHist(image1, histEqualized);

        imshow("Source_image", image1);
        imshow("calcHist_Demo", histEqualized);
        waitKey(25);
    }
    cap.release();
    destroyAllWindows();

}
