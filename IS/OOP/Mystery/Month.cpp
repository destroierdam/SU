#include"Month.hpp"

size_t Month::monthDays(size_t month)
{
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        return 31;
    }
    else if(month==4 || month==6 || month==9 || month==11)
    {
        return 30;
    }
    else if(month==2)
    {
        return 28;
    }
    else
    {
        cerr<<"Invalid month"<<endl;
        return 0;
    }
}
Month::Month(Months monthOfYear)
{
    // No need to check for correct input

    this->numberOfDays = monthDays(monthOfYear);
}
Month::Month(size_t monthOfYear)
{
    if(1<=monthOfYear&&monthOfYear<=12)
    {

        this->numberOfDays = monthDays(monthOfYear);
    }
    else
    {
        //cerr<<monthOfYear<<" is not a valid month"<<endl;
        this->numberOfDays = 0;
    }
}

void Month::showTasksFromDay(size_t day)
{
    saveTasksFromDay(day,cout);
}

void Month::saveTasksFromDay(size_t day, ostream& out)
{
    if(day<=this->numberOfDays)
    {
        (this->days[day]).fprintTasks(out);
    }
}

size_t Month::getNumberOfDays() const
{
    return this->numberOfDays;
}

void Month::addTaskInDay(size_t day,Task* t)
{
    days[day].addTask(t);
}
