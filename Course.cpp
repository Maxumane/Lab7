#include "Course.hpp"

using namespace std;


Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}

Course::Course() {
    title = "Blank Course";
    day = MON;
    start_time = 0;
    finish_time = 0;
}


Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(Course m) {
    mySwap(*this, m);
    return *this;
}
bool Course::operator == (const Course & m) const {
    if (title == m.title && day == m.day && start_time == m.start_time && finish_time == m.finish_time) {
        return true;
    }
    return false;
}


bool Course::Collision(Course m) const {

    if (*this == m) {
        return false;
    }

    if (day != m.day) {
        return false;
    }

    if((start_time >= m.start_time && start_time <= m.finish_time) || (m.start_time >= start_time && m.start_time <= finish_time)) {
        return true;
    }

    return false;
}

bool Course::operator < (const Course & m) const
{
    if (day < m.day) {
        return true;
    }

    if (day == m.day) {
        if (start_time < m.start_time) {
            return true;
        }
        if (start_time == m.start_time && finish_time < m.finish_time) {
            return true;
        }
    }
    //TODO implement the operator
    return false;
}

ostream & operator << (ostream &os, const Course & m)
{
    string dayString;
    switch (m.day) {
        case Course::MON:
            dayString = "M";
            break;
        case Course::TUE:
            dayString = "T";
            break;
        case Course::WED:
            dayString = "W";
            break;
        case Course::THUR:
            dayString = "R";
            break;
        case Course::FRI:
            dayString = "F";
            break;
    }
    os << m.title << " " << dayString << " " << m.start_time << "-" << m.finish_time << endl;
    return os;
}