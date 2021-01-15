/*
Simon Game
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// #include <Windows.h>
// #include <DAQlib.h>
#include <time.h>
#include <math.h>


#define ON 1
#define OFF 0


#define Green 0
#define Red 1
#define Yellow 2
#define Blue 3


#define GreenLED 0
#define RedLED 1
#define YellowLED 2
#define BlueLED 3


#define GreenButton 0
#define RedButton 1
#define YellowButton 2
#define BlueButton 3


#define second 1000


#define TRUE 1
#define FALSE 0


void game(void);
void zzz(int index);
int press(void);


int main(void)
{
    int setupNum;
    printf("Please enter 0 for the Hardware, 6 for the Simulator: ");
    scanf("%d", &setupNum);
    if (setupDAQ(setupNum) == TRUE)
    {
        /* Stopped for one second to allow everything to load and user to get ready*/
        Sleep(second);
        game();
    }
    else
    {
        printf("Error intializing DAQ...");
    }
    system("PAUSE");
    return 0;


}


void game(void)
{


    while (continueSuperLoop() == TRUE)
    {
        int index;
        int count;
        index = 0;
        int NumNum = 5;


        /* Test that it does enter the Super Loop, and turns each light on, and then off after 1 second, one by one. */
        for (count = 0; count <= 3; count++)
        {
            digitalWrite(count, ON);
            Sleep(second);
            digitalWrite(count, OFF);
        }


        while (index < NumNum)
        {
            static int randArray[5];
            srand((unsigned)time(NULL));
            randArray[index] = rand() % 4;




            for (count = 0; count <= index; count++)
            {
                digitalWrite(randArray[count], ON);
                zzz(index);
                digitalWrite(randArray[count], OFF);
            }


            for (count = 0; count <= index; count++)
            {
                int pressed;
                pressed = press();


                if (press != randArray[count])
                {
                    index = 0;
                }
                else
                {


                }
            }
            index++;


        }




    }
    return;
}


void zzz(int count)
{
    int time, time_decrease_percentage, degree;
    time = second;
    time_decrease_percentage = 0.75;
    degree = count + 1;


    if (count = 0)
    {
        Sleep(time * pow(time_decrease_percentage, degree));
    }
    else if (count = 1)
    {
        Sleep(time * pow(time_decrease_percentage, degree));
    }
    else if (count = 2)
    {
        Sleep(time * pow(time_decrease_percentage, degree));
    }
    else
    {
        Sleep(time * pow(time_decrease_percentage, degree));
    }
    return;
}




int press(void)
{
    int colornum;


    if (digitalRead(GreenButton) == ON)
    {
        colornum = Green;
    }


    if (digitalRead(RedButton) == ON)
    {
        colornum = Red;
    }


    if (digitalRead(YellowButton) == ON)
    {
        colornum = Yellow;
    }


    if (digitalRead(BlueButton) == ON)
    {
        colornum = Blue;
    }


    return colornum;
}