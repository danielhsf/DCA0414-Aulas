#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image,media1,media2,media3,media4;
  image = imread(argv[1],0);
  blur(image, media1, Size( 3, 3 ),Point(-1,-1));
  blur(image, media2, Size( 11, 11 ),Point(-1,-1));
  GaussianBlur(image, media3, Size( 3, 3 ),0);
  GaussianBlur(image, media4, Size( 5, 5 ),0);
  imshow("Original",image);
  imshow("Media 3x3",media1);
  imshow("Media 5x5",media2);
  imshow("Media Gaussiana 3x3",media3);
  imshow("Media Gaussiana 5x5",media4);
  waitKey();
  return 0;
}