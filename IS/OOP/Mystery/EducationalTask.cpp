#include"EducationalTask.hpp"

EducationalTask:EducationalTask
(time_t _startTime,time_t _endTime,string _nameOfEvent,
 string _description, string _type,
 string _subject, string _material)
:Task(_startTime,_endTime,_nameOfEvent,_description,_type)
{
    this->subject  = _subject;
    this->material = _material;
}

void EducationalTask::fprint(ostream& out) const
{
    Task::fprint(out);

    out<<"Subject: "<<this->subject<<endl;
    out<<"Material: "<<this->material<<endl;
}

void EducationalTask::print() const
{
    fprint(cout);
}
