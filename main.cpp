#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule()
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
}

int main () {
    //TODO read from courses.txt

//    while (getline(courseText, wholetext)) {
//        string title;
//        string day;
//        int start;
//        int end;
//        istringstream lineText (wholetext);
//        lineText >> title >> day >> start >> end;
//        cout << wholetext;
//    }

    //TODO store data in an STL container
    //TODO sort your STL container with the sort algorithm
    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule
    string wholetext;
    stringstream courseLine;
    int n;
    int d;
    int count = 0;
    ifstream courseText;
    courseText.open("../courses.txt");

    if(!courseText.is_open()) {
        cerr << "Unable" << endl;
    }
    while (getline(courseText, wholetext)) {

        stringstream ss;

        /* Storing the whole string into string stream */
        ss << wholetext;

        /* Running loop till the end of the stream */
        string temp;
        int time;
        int numCount = 0;
        while (!ss.eof()) {

            /* extracting word by word from stream */
            ss >> temp;

            /* Checking the given word is integer or not */
            if (stringstream(temp) >> time) {
                if (numCount == 0) {
                    cout << time << " ";
                    numCount++;
                }
                if (numCount == 0) {
                    cout << time << " ";
                    numCount++;
                }
            }

            /* To save from space at the end of string */
            temp = "";
        }
        cout << endl;
    }
    courseText.close();
    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}