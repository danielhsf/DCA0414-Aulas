#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat src, erosion_dst, dilation_dst;
int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;
int main( int argc, char** argv )
{
  src = imread("abrir.png",0);
  Mat element = getStructuringElement( MORPH_RECT,
                       Size( 9, 9 ),
                       Point( 4, 4 ) );
  Mat dilatado;
  dilate( src, dilatado, element );
  Mat erodido;
  erode(dilatado, erodido, element);
  imshow( "Original", src );
  imshow( "Dilatado", dilatado );
  imshow( "Erodido", erodido );
  waitKey(0);
  return 0;
}


