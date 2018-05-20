#ifndef DAY_HPP_INCLUDED
#define DAY_HPP_INCLUDED

class Day
{
    vector<Task*> tasks;
public:
    void addTask(Task* newTask);
    /*
    {
        tasks.push_back(newTask);
    }
    */

    void fprintTasks(ostream& out) const;
    /*
    {
        /// c++11 only
        for(auto &i : tasks )
        {
            out<<*i<<endl;
        }
    }
    */
    void printTasks() const;
    /*
    {
        fprintTasks(cout);
    }
    */
};

#include"Day.cpp" // Codeblocks gives linker error if this isn't included. I know it's wrong

#endif // DAY_HPP_INCLUDED
