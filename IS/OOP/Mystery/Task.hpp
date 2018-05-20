#ifndef TASK_HPP_INCLUDED
#define TASK_HPP_INCLUDED

class Task
{
protected:
    string nameOfEvent;
    string description;
    string type;        /// Should change at every level

    time_t startTime,endTime;

    size_t currentInstance;

public:
    static size_t numberOfTasks; // counts the number of objects of class Task created

    Task(time_t _startTime, time_t _endTime,string _nameOfEvent="#UNKNOWN",
          string _description = "#UNKNOWN", string _type="default");

    virtual void fprint(ostream& out) const;

    virtual void print() const;

    friend ostream& operator << (ostream& out,const Task& task)
    {
        // Best thing I found on StackOverflow
        // Not in .cpp on purpose; else throws error: friend declaration outside of class

        task.fprint(out);

        return out;
    }
};

#endif // TASK_HPP_INCLUDED
