#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
using namespace  cv;
using namespace std;

// forward declaration for our functions;
void captureWebcamp();
void faceDetection(Mat img);


int main(  )
{
   captureWebcamp();
}


// function to 
void captureWebcamp(){
    VideoCapture cap(0);
    Mat img;
    while(true){
        cap.read(img);
        faceDetection(img);
    }
}



// function to detect face using opencv;
void faceDetection(Mat img){

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "XML file not loaded" << endl;}

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	waitKey(1);
}