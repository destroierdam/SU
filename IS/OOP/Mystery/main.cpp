// Basic calendar; OOP HW2; Damian Boytchev
// Compiled on Windows 10 1803.17134.48 64 bit
// with mingw32-g++.exe -std=c++11;IDE - CodeBlocks 17.12

#include<iostream>
#include<fstream>
#include<windows.h>
#include<ctime> // ---------------------- should be deleted after class Time implementation
#include<vector>
#include<string>

using namespace std;


#include"Person.hpp"

#include"Task.hpp"
#include"BusinessTask.hpp"
#include"EducationalTask.hpp"
#include"RecreationalTask.hpp"


/// <FORWARD DECLARATION  OF CLASSES> --- should be deleted after class Time implementation
// Misc
class Time; /// !!! TO BE ADDED !!!

/// </FORWARD DECLARATION  OF CLASSES>




/// <GLOBAL DECLARATIONS>

enum Months {January=1, February, March, April, May, June, July, August, September, October, November, December};

Months intToMonth(int n)
{
    switch(n)
    {
    case 1:
        return January;
    case 2:
        return February;
    case 3:
        return March;
    case 4:
        return April;
    case 5:
        return May;
    case 6:
        return June;
    case 7:
        return July;
    case 8:
        return August;
    case 9:
        return September;
    case 10:
        return October;
    case 11:
        return November;
    case 12:
        return December;
    }
}

/// </GLOBAL DECLARATIONS>




/// <CLASS IMPLEMENTATION>

#include"Day.hpp"
#include"Month.hpp"


class Year
{
    vector<Month> months;
public:
    Year(int _year)
    {
        for(int i=January;i!=December;i++)
        {
            Months m = intToMonth(i);

            months.push_back(Month(m));
        }
    }
};


class Calendar
{
    string description;
    size_t year;
    vector<Month> months;
public:
    Calendar(size_t _year)
    {
        this->year = _year;

        months.push_back(Month(0));
        for(size_t i=1;i<=12;i++)
        {
            months.push_back(Month(i));

        }
    }

    void addTask(Months month,size_t day,Task* task)
    {
        addTask(month,day,task);
    }

    void addTask(size_t month,size_t day,Task* task)
    {
        months[month].addTaskInDay(day,task);
    }

};
int main()
{
    Calendar cal(2018);

    return 0;
}
/*


Задачата пред вас е да създадете приложение за водене на задачи в календар.
Обобщено трябва да имате информация за ден, месец година,събития (tasks),
масив(списък, множество) от задачи които има човек през съответния ден

трябва да предоставите функционалност за добавяне на задача, също и за премахване

Подробно описание:
Календарът трябва да съдържа следната информация :

кратко описание на календара

масив(списък) от месеци

Месецът трябва да съдържа "минимум":

брой дни в месеца

"поредица" от дни - като всеки ден има информация за:

задачите които имате през този ден

Реализирайте абстракция на задачите, като -> Задачата ви представлява най - горното ниво на абстракция ;
 пример - бизнес задачата представлява имплементация на задачата като добавяте необходимите полета и функционалност

Задача - в нея да се пази информация за:

наименование на събитието (последователност от символи)

пояснение (description)

часови диапазон (пример на формат на чч::мм::сс - чч::мм::сс)

тип (по подразбиране - default, На всяко ниво да се сменя автоматично)

номер на събитието - статична променлива (да посочва колко общо имате създадени) и номер на текущо създадената инстанция

Бизнес:

Всичко от задача плюс:

Хора на срещата - представлява поредица от име и фамилия (можете да го изнесете в отделен клас)

местоположение

пресмятане на продължителността

наименование на домакина

Учебна:

наименование на предмет

материал, който трябва да се изчете

Развлечение:

вид на развлечението (това е различно от тип, тук може и енъм пример: семейно, разходка в парка или да е стринг)

местоположение

да може да проверявате времето на това местоположение (пример системна команда system("start chrome  https://www.sinoptik.bg/search?q={карлово}");)

Приложението да предоставя допълнителна функционалност, за отпечатване на всичките задачи през подаден от потребителя месец и ден, да може да добавяте на даден ден (през конкретен месец) - задача, както и да премахвате задача.

Заб: предавайте домашните си в .zip формат, по шаблона фн_гр_2.zip (71999_1_2.zip), в решението на задачата да присъства поне един списък
*/
