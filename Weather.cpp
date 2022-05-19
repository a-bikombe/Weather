/*
Student Name: Arianna Bikombe
Date: April 15, 2021
Course: CSCI175N
Lab Assignment: Lab09-02Weather
Project Name: Weather
File Name: Lab09-02Weather.cpp
Description: Displays numbers from the text file RainOrShine.txt.
Limitations: Doesn't do very much.
Credits: Not Applicable
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Function prototypes
void myName();

int main()
{

    myName();

    // Constant for the number of months
    const int NUM_MONTHS = 3;

    // Constant for the days in a month
    const int DAYS_IN_MONTH = 30;

    // Array of month names
    string name[NUM_MONTHS] = {"June", "July", "August"};

    // Array of rainy days
    int rainyDays[NUM_MONTHS];

    // File stream object to read data from a file
    ifstream weatherData;

    int month;                  // Month counter
    int day;                    // Day counter
    int rainyTotal = 0;         // Total number of rainy days
    int cloudyTotal = 0;        // Total number of cloudy days
    int sunnyTotal = 0;         // Total number of sunny dauys
    int wettestMonthIndex;           // Index of rainiest month

    //Open data file
    weatherData.open("RainOrShine.txt");

    // Test for error.
    if (!weatherData) {
        cout << "Error opening data file.\n" << endl;
        system("pause");
        return 0;
    }

    // Print report heading
    cout << "   Summer Weather Report\n\n";
    cout << "Month  Rainy   Cloudy  Sunny\n";
    cout << "_____________________________\n";

    // Read weather data into the array
    for (month = 0; month < NUM_MONTHS; month++) {

        // local variables
        char type;          // Character in the file
        int rainy = 0;      // Rainy days in a particular month
        int cloudy = 0;     // Cloudy days in a particular month
        int sunny = 0;      // Sunny days in a particular month

        // Accumulate and display weather statistics
        wettestMonthIndex = 0;

        for (day = 0; day < DAYS_IN_MONTH; day++) {

            weatherData >> type;

            if (type == 'R')
                rainy++;
            else if (type == 'C')
                cloudy++;
            else if (type == 'S')
                sunny++;
            else
                cout << "Not a valid forecast";
        }

        // Display this month's results
        cout << left << setw(6) << name[month];
        cout << right << setw(6) << rainy << setw(8);
        cout << cloudy << setw(7) << sunny << endl;

        // Totals
        rainyTotal += rainy;
        cloudyTotal += cloudy;
        sunnyTotal += sunny;

        // Get wettest month
        if (month > wettestMonthIndex)
            wettestMonthIndex = month;

    }

    // Display summary data
    cout << "_____________________________\n";
    cout << "Totals" << setw(6) << rainyTotal << setw(8);
    cout << cloudyTotal << setw(7) << sunnyTotal << endl << endl;
    cout << name[wettestMonthIndex] << " had the most rainy days.\n" << endl;

    system("pause");

    return 0;

}

//*************************************************
// The myName function outputs my name, course, & *
// Program #, and a blank line as typical for all *
// programs.                                      *
//*************************************************

void myName() {

    // Print out your name and course
    cout << "Arianna Bikombe\n";
    cout << "CSCI175N\n";
    cout << "Lab09-02Weather\n" << endl;

}

/*

test 1

Arianna Bikombe
CSCI175N
Lab09-02Weather

   Summer Weather Report

Month  Rainy   Cloudy  Sunny
_____________________________
June      11       8     11
July      11      14      5
August    16       7      7
_____________________________
Totals    38      29     23

August had the most rainy days.

Press any key to continue . . .

*/

/*

test 2

Arianna Bikombe
CSCI175N
Lab09-02Weather

Error opening data file.

Press any key to continue . . .

*/