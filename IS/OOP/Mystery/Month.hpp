#ifndef MONTH_HPP_INCLUDED
#define MONTH_HPP_INCLUDED

class Month
{
    Day days[32];
    size_t numberOfDays;

    size_t monthDays(size_t month);
public:
    Month(Months monthOfYear);

    Month(size_t monthOfYear);


    void showTasksFromDay(size_t day);


    void saveTasksFromDay(size_t day, ostream& out);


    size_t getNumberOfDays() const;


    void addTaskInDay(size_t day,Task* t);

};

//#include"Month.cpp" // Codeblocks gives linker error if this isn't included.

#endif // MONTH_HPP_INCLUDED
