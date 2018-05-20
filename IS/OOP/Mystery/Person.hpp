#ifndef PERSON_HPP_INCLUDED
#define PERSON_HPP_INCLUDED

class Person
{
    string firstName,lastName;
public:
    Person(string _firstName="#UNKNOWN", string _lastName="#UNKNOWN")
    {
        this->firstName = _firstName;
        this->lastName = _lastName;
    }

    string getFirstName() const
    {
        return this->firstName;
    }
    string getLastName() const
    {
        return this->lastName;
    }

    friend ostream& operator << (ostream& out,const Person& person)
    {
        out<<person.firstName<<" "<<person.lastName<<" ";

        return out;
    }
};

#endif // PERSON_HPP_INCLUDED
