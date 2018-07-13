#include "pos_compensation.h"
#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

#define TEST_FILE_NAME "log_video_file.avi"
#define TEST_LOG_FILE_NAME "log_video_sensor_file.txt"

int main()
{
    // 1. open test video 
    string videofile = TEST_FILE_NAME;
    VideoCapture vin(videofile);
    if(!vin.isOpened()){
        std::cerr << "Cannot open " << videofile << std::endl;
        return -1;
    }

    std::ifstream login(TEST_LOG_FILE_NAME);

    // 2. open roll, pitch, altitude file 

    Mat frame;
    int numFrame = 100;
    double roll = 0.2, pitch = 0.1, altitude = 1.0; // radian, meter
    int fn  = 0;
    int key = 0 ;
    int mode = 1; // runnig mode 

    while(true){

        // 3. read a frame
        vin >> frame;
        if(frame.empty())
            break;

        // 4. roll, pitch, yaw
        login >> roll;
        login >> pitch;
        login >> altitude;

        //5. calcuate the real center postion 
        Point2i center = find_position_in_image(frame,  roll,  pitch,  altitude);

        // 6. draw the center on the image
        circle(frame, center, 5, Scalar(0,0,255), CV_FILLED, 1, 0);
       
skip:
        // 7. display and wait 25 msec 
        imshow("drone", frame);

        key = waitKey(25);
        if((char)key == 27){
            break;
        }else if ((char)key == 's'){
           mode = 0;
           goto skip;
        }else if (key == -1 && mode == 0){
           goto skip;
        }else if((char)key == 'r'){
            mode = 1;
        }
                
    }

    login.close();
    vin.release();
}
