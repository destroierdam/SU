#include<BusinessTask.hpp>

time_t BusinessTask::duration()
{
    return difftime(endTime,startTime);
}

BusinessTask::BusinessTask
(time_t _startTime,time_t _endTime, vector<Person> _pplInMeeting, Person _host,
 string _location, string _nameOfEvent,
 string _description, string _type)
:Task(_startTime,_endTime,_nameOfEvent,_description,_type)
{
    this->pplInMeeting = _pplInMeeting;
    this->location = _location;
    this->host = _host;
}

void BusinessTask::fprint(ostream& out) const
{
    // I want to call Task::fprint(out); and add a few things
    // Will this work?
    Task::fprint(out);

    out<<"People in meeting: ";
    for(size_t i=0,sz=pplInMeeting.size();i<sz;i++)
    {
        out<<this->pplInMeeting[i]<<endl;
    }

    out<<"Location: "<<this->location<<endl;

    out<<"Host: "<<this->host<<endl;
}

void BusinessTask::print() const
{
    this->fprint(cout);
}



