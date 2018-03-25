#include <iostream>
using namespace std;
class Time
{
    int hours;
    int minutes;
public:

    /// This function will return the "hours" field of a created object
    /// It is accessed with the '.' operator
    /// Example: object.getHours()
    /// Result: an integer that is the value recorded in the "hours" field of the object
    int getHours()
    {
        return this->hours;
    }

    /// This function will return the "minutes" field of a created object
    /// It is accessed with the '.' operator
    /// Example: object.getMinutes()
    /// Result: an integer that is the value recorded in the "minutes" field of the object
    int getMinutes()
    {
        return this->minutes;
    }

    /// This method changes the "hours" field of an object
    /// The function doesn't return anything
    void setHours(int newHours)
    {

    }
};
int main()
{
    return 0;
}
/*

FROM:
https://github.com/stranxter/lecture-notes/blob/master/homeworks/02_oop/03%20classes%20I/classes%20I.pdf

TO BE CONTINUED
*/
