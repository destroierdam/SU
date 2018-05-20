#ifndef RECREATIONALTASK_HPP_INCLUDED
#define RECREATIONALTASK_HPP_INCLUDED

class RecreationalTask : public Task
{
    string activity;
    string location;
public:
    RecreationalTask(time_t _startTime,time_t _endTime,string _activity="#UNKNOWN",string _location="#UNKNOWN",
                    string _nameOfEvent="#UNKNOWN", string _description = "#UNKNOWN", string _type="recreational");

    void checkWeather() const;

    friend ostream& operator << (ostream& out,const RecreationalTask& task)
    {
        // Not in .cpp on purpose; else throws error: friend declaration outside of class

        task.fprint(out);

        return out;
    }
};

#endif // RECREATIONALTASK_HPP_INCLUDED
