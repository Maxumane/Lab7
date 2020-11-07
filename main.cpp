#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> a)
{
    int counter = 1;
    for(auto i = a.begin(); i != a.end(); ++i) {
        for (auto b = i; b != a.end(); ++b) {
            if (i->Collision(*(b))) {
                cout << "CONFLICT:" << endl;
                cout << *i;
                cout << *b;
                cout << endl;
            }

        }
    }


    copy(a.begin(), //istream_iterator points to 0.1
         a.end(), //end-of-stream iterator, similar to vector.end()
         ostream_iterator<Course>(cout, ""));


}

int main () {

    //TODO read from courses.txt
    //TODO store data in an STL container
    //TODO sort your STL container with the sort algorithm
    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule
    string wholetext;
    stringstream courseLine;
    string t;
    string d;
    vector<Course> courseList;
    int s;
    int f;
    int count = 0;
    ifstream courseText;
    courseText.open("../courses.txt");

    if(!courseText.is_open()) {
        cerr << "Unable" << endl;
        return 1;
    }

    while (getline(courseText, wholetext)) {
            courseText.clear();
            courseLine.str(wholetext);
            Course j;
            string title;
            string day;
            unsigned int startTime;
            unsigned int finishTime;
            courseLine >> title >> day >> startTime >> finishTime;
            j.title = title;
            j.start_time = startTime;
            j.finish_time = finishTime;
            Course::dayOfWeek TrueDay;
            if(day == "M") {
                j.day = Course::dayOfWeek::MON;
            }
            if(day == "T") {
                j.day = Course::dayOfWeek::TUE;
            }
            if(day == "W") {
                j.day = Course::dayOfWeek::WED;
            }
            if(day == "R") {
                j.day = Course::dayOfWeek::THUR;
            }
            if(day == "F") {
                j.day = Course::dayOfWeek::FRI;
            }
        courseList.push_back(j);
    }
    courseText.close();

    vector <Course>::iterator itBegin = courseList.begin();
    vector<Course>::iterator itEnd = courseList.end();
    sort(courseList.begin(), courseList.end());

//    int counter = 1;
//    for(auto i = courseList.begin(); i != courseList.end(); ++i) {
//        for (auto b = i; b != courseList.end(); ++b) {
//            if (i->Collision(*(b))) {
//                cout << "Collision Here:" << endl;
//                cout << *i;
//                cout << *(i + counter);
//                cout << endl;
//            }
//
//        }
//    }


    printSchedule(courseList);

    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}