#include"Task.hpp"

size_t Task::numberOfTasks=0; // set to 0 the counter of instances of Task

Task::Task(time_t _startTime, time_t _endTime,string _nameOfEvent,
      string _description, string _type)
{
    this->nameOfEvent = _nameOfEvent;
    this->description = _description;
    this->type        = _type;
    this->startTime   = _startTime;
    this->endTime     = _endTime;

    this->currentInstance = Task::numberOfTasks;

    numberOfTasks++; // or this->numberOfTask++; ??? both compile
}

void Task::fprint(ostream& out) const
{
    out<<"Name of event: "<<this->nameOfEvent<<endl;
    out<<"Description: "<<this->description<<endl;
    out<<"Type: "<<this->type<<endl;
}

void Task::print() const
{
    fprint(cout);
}



