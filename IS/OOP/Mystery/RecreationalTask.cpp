#include"RecreationalTask.hpp"

RecreationalTask::RecreationalTask(time_t _startTime,time_t _endTime,string _activity,string _location,
                string _nameOfEvent, string _description, string _type)
:Task(_startTime,_endTime,_nameOfEvent,_description,_type)
{
    this->activity = _activity;
    this->location = _location;
}

void RecreationalTask::checkWeather() const
{
    string systemCall = "start chrome https://www.sinoptik.bg/search?q={";

    systemCall+=location;

    systemCall+="}";
    system(systemCall.c_str()); /// System specific and slow
}
