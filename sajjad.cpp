#include <iostream>
#include <time.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "sajjad.h"

using namespace std;
using namespace cv;


Sajjad::Sajjad()
{
    cout << "This is Sajjad constructor" << endl;
}

int Sajjad::testMethod()
{
    cout << "This is Sajjad test method" << endl;
    return 0;
}

/*  
    extern "C" required when using C++ compiler
    the extern "C" line ensures that your functions can be called from “C”. 
    Because Python is written in C, your external function must be C callable.
*/
extern "C"
{
    float add(int num1, float num2) 
    {
        cout << "This is Sajjad add" << endl;
        return num1 + num2;
    }

    char* number2Word(int num)
    {
        char* word = new char[10];
        if(num == 1)
        {
            strcpy(word, "one");
        }
        else if(num == 2)
        {
            strcpy(word, "two");
        }
        else
        {
            strcpy(word, "error");
        }
        return word;
    }

    int word2Number(char word[])
    {
        int num;
        if(strcmp(word, "one") == 0)
        {
            num = 1;
        }
        else if(strcmp(word, "two") == 0)
        {
            num = 2;
        }
        else
        {
            num = -1;
        }
        return num;
    }

    int testOpenCV(char input_image_path[], char output_image_path[])
    {
        clock_t start_time, end_time;
        start_time = clock();
        cv::Mat image_a, image_b, image_c;

        image_a = cv::imread(input_image_path, 1);
        if ( !image_a.data )
        {
            cout << "No image data" << endl;
            return -1;
        }

        cv::resize(image_a, image_b, cv::Size(), 0.5, 0.5);
        cv::cvtColor(image_b, image_c, cv::COLOR_BGR2GRAY);

        cv::imwrite(output_image_path, image_c);
        // cv::namedWindow("Display Image", WINDOW_AUTOSIZE );
        // cv::imshow("Display Image", image);
        // cv::waitKey(0);

        end_time = clock();
        cout << "Result image saved in " << output_image_path << endl;
        cout << float(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
        return 0;
    }
}
