/**
 * @file filter2D_demo.cpp
 * @brief Sample code that shows how to implement your own linear filters by using filter2D function
 * @author OpenCV team
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

/**
 * @function main
 */
int main ( int argc, char** argv )
{
    // Declare variables
    Mat src, dst;

    Mat kernel = (Mat_<char>(3,3) << 0, -1,  0,
                                    -1, 4, -1,
                                    0, -1,  0);
    Point anchor;
    double delta;
    int ddepth;
    const char* window_name = "filter2D Demo";

    //![load]
    const char* imageName = argc >=2 ? argv[1] : "../data/lena.jpg";

    // Loads an image
    src = imread( imageName, 0 ); // Load an image

    if( src.empty() )
    {
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default ../data/lena.jpg] \n");
        return -1;
    }
    //![load]

    //![init_arguments]
    // Initialize arguments for the filter
    anchor = Point( -1, -1 );
    delta = 0;
    ddepth = -1;
    //![init_arguments]

    // Loop - Will filter the image with different kernel sizes each 0.5 seconds
    int ind = 0;
    for(;;)
    {

        //![apply_filter]
        // Apply filter
        filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
        //![apply_filter]
        imshow( window_name, dst );

        char c = (char)waitKey(500);
        // Press 'ESC' to exit the program
        if( c == 27 )
        { break; }

        ind++;
    }

    return 0;
}
