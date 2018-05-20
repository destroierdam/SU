#ifndef EDUCATIONALTASK_HPP_INCLUDED
#define EDUCATIONALTASK_HPP_INCLUDED

class EducationalTask : public Task
{
    string subject;
    string material;
public:
    EducationalTask(time_t _startTime,time_t _endTime,string _nameOfEvent="#UNKNOWN",
                    string _description = "#UNKNOWN", string _type="educational",
                    string _subject="#UNKNOWN", string _material="#UNKNOWN");

    void fprint(ostream& out) const;
    void print() const;

    friend ostream& operator << (ostream& out,const EducationalTask& task)
    {
        // Not in .cpp on purpose; else throws error: friend declaration outside of class

        task.fprint(out);

        return out;
    }
};

#endif // EDUCATIONALTASK_HPP_INCLUDED
