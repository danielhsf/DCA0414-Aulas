#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawText(Mat & image);

int main()
{
    Mat image;
    VideoCapture capture;
    Mat bgr[3];
    capture.open(0);
    if(capture.isOpened())
    {
        for(;;)
        {
            capture >> image;
	    split(image,bgr);
            if(image.empty())
                break;
            drawText(image);
            imshow("blue", bgr[0]);
	    imshow("green", bgr[1]);
	    imshow("red",bgr[2]);
            if(waitKey(10) >= 0)
                break;
        }
    }
    else
    {
        cout << "No capture" << endl;
        image = Mat::zeros(480, 640, CV_8UC1);
        drawText(image);
        imshow("Sample", image);
        waitKey(0);
    }
    return 0;
}

void drawText(Mat & image)
{
    putText(image, "Hello OpenCV",
            Point(20, 50),
            FONT_HERSHEY_COMPLEX, 1, // font face and scale
            Scalar(255, 255, 255), // white
            1, LINE_AA); // line thickness and type
}
