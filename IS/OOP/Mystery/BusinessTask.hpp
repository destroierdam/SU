#ifndef BUSINESSTASK_HPP_INCLUDED
#define BUSINESSTASK_HPP_INCLUDED

class BusinessTask : public Task
{
    vector<Person> pplInMeeting;
    string location;
    Person host;

    time_t duration();
public:
    BusinessTask(time_t _startTime,time_t _endTime, vector<Person> _pplInMeeting, Person _host,
                  string _location="#UNKNOWN", string _nameOfEvent="#UNKNOWN",
                  string _description = "#UNKNOWN", string _type="business");

    void fprint(ostream& out) const;
    void print() const;

    friend ostream& operator << (ostream& out,const BusinessTask& task)
    {
        // Not in .cpp on purpose; else throws error: friend declaration outside of class

        task.fprint(out);

        return out;
    }

};

#endif // BUSINESSTASK_HPP_INCLUDED
