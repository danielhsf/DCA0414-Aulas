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
    capture.open(0);
    if(capture.isOpened())
    {
        capture >> image;
        imwrite("saida.png",image);
    }
    else
    {
        cout << "Não Foi possivel Salvar a imagem" << endl;
    }
    return 0;
}

