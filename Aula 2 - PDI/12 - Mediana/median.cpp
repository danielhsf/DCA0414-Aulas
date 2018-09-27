#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image,media,mediana;
  image = imread(argv[1],0);
  blur(image, media, Size(3,3),Point(-1,-1));
  medianBlur(image,mediana,3);
  imshow("Original",image);
  imshow("Media",media);
  imshow("Mediana",mediana);
  waitKey();
  return 0;
}