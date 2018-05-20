#include"Day.hpp"

void Day::addTask(Task* newTask)
{
    tasks.push_back(newTask);
}

void Day::fprintTasks(ostream& out) const
{
    /// c++11 only
    for(auto &i : tasks )
    {
        out<<*i<<endl;
    }
}

void Day::printTasks() const
{
    fprintTasks(cout);
}

