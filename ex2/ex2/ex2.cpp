#include <iostream>
#include <windows.h>
using namespace std;

#include "mobile_phone.h"
#include "human.h"
#include "weights.h"
#include "door.h"
#include "room.h"

// документация это практика за 9 октября

/// <summary>
/// class Student
/// </summary>
class Student {
private:
    string name;
    string surname;
    string fathname;
    string homeadress;
    string phone_number;

    // практика за 11 октября
    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    int* practask_rates = nullptr;
    int practask_rates_count = 0;

    int* examtask_rates = nullptr;
    int examtask_rates_count = 0;

public:
    /// <summary>
    /// а method that allows you to change a student's name
    /// </summary>
    /// <param name="name">some new value for student name</param>
    void SetName(string name)
    {
        this->name = name;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetName() const
    {
        return name;
    }
    /// <summary>
    /// а method that allows you to change a student's surname
    /// </summary>
    /// <param name="surname">some new value for student surname</param>
    void SetSurname(string surname)
    {
        this->surname = surname;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetSurname() const
    {
        return surname;
    }
    /// <summary>
    /// а method that allows you to change a student's father`s name
    /// </summary>
    /// <param name="fathname">some new value for student father`s name</param>
    void SetFathname(string fathname)
    {
        this->fathname = fathname;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetFathname() const
    {
        return fathname;
    }
    /// <summary>
    /// а method that allows you to change a student`s home adress
    /// </summary>
    /// <param name="homeadress">some new value for student home adress</param>
    void SetHomeAdress(string homeadress)
    {
        this->homeadress = homeadress;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GethomeAdress() const
    {
        return homeadress;
    }
    /// <summary>
    /// а method that allows you to change a student`s phone number
    /// </summary>
    /// <param name="phone_number">some new value for student phone number</param>
    void SetPhoneNumber(string phone_number)
    {
        this->phone_number = phone_number;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetPhoneNumber() const
    {
        return phone_number;
    }

    Student()
    {
        // Практика за 2 октября
        SetName("Alexey");
        SetSurname("Kosmolenko");
        SetFathname("Denisovich");
        SetHomeAdress("Blicker street 325a");  
        SetPhoneNumber("+1439430493049");
    } 
    
    Student(string name) : Student("Alexey", "Kosmolenko","Denisovich","Blicker street 325a","+1 439 4930 49"){}

    Student(string name, string surname, string fathname, string home_adress, string phone_number) {
        SetName(name);
        SetSurname(surname);
        SetFathname(fathname);
        SetHomeAdress(home_adress);
        SetPhoneNumber(phone_number);
    }
    /// <summary>
    /// Defines a destructor for the class Student
    /// </summary>
    ~Student() {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (practask_rates != nullptr)
        {
            delete[] practask_rates;
            practask_rates = nullptr;
        }
        if (examtask_rates != nullptr)
        {
            delete[] examtask_rates;
            examtask_rates = nullptr;
        }

    }
    /// <summary>
    /// This method involves adding a grade to the student's homework grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddHometaskRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "No\n";
            throw "error";
        }
        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++) {
                temp[i] = hometask_rates[i];
                temp[i + 1] = rate;
            }
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }
    int* GetHometaskRates() const
    {
        return hometask_rates;
    }
    int GetHometaskRatesCount() const
    {
        return hometask_rates_count;
    }
    /// <summary>
    /// show grades for the student`s hometask
    /// </summary>
    void PrintHometaskRates()
    {
        for (int i = 0; i < hometask_rates_count; i++) {
            cout << i + 1 << hometask_rates[i] << "\n";
        }
    }
    /// <summary>
    /// This method involves adding a grade to the student's practice grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddPractaskRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "No\n";
            throw "error";
        }
        if (practask_rates_count == 0)
        {
            practask_rates = new int[1];
            practask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[practask_rates_count + 1];
            for (int i = 0; i < practask_rates_count; i++) {
                temp[i] = practask_rates[i];
                temp[i + 1] = rate;
            }
            delete[] practask_rates;
            practask_rates = temp;
        }
        practask_rates_count++;
    }
    int* GetPractaskRates() const
    {
        return practask_rates;
    }
    int GetPractaskRatesCount() const
    {
        return practask_rates_count;
    }
    /// <summary>
    /// show grades for the student`s practice
    /// </summary>
    void PrintPractaskRates()
    {
        for (int i = 0; i < practask_rates_count; i++) {
            cout << i + 1 << practask_rates[i] << "\n";
        }
    }
    /// <summary>
    /// This method involves adding a grade to the student's exam grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddExamtaskRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "No\n";
            throw "error";
        }
        if (examtask_rates_count == 0)
        {
            examtask_rates = new int[1];
            examtask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[examtask_rates_count + 1];
            for (int i = 0; i < examtask_rates_count; i++) {
                temp[i] = examtask_rates[i];
                temp[i + 1] = rate;
            }
            delete[] examtask_rates;
            examtask_rates = temp;
        }
        examtask_rates_count++;
    }
    int* GetExamtaskRates() const
    {
        return examtask_rates;
    }
    int GetExamtaskRatesCount() const
    {
        return examtask_rates_count;
    }
    /// <summary>
    /// show grades for the student`s exam`s
    /// </summary>
    void PrintExamtaskRates()
    {
        for (int i = 0; i < examtask_rates_count; i++) {
            cout << i + 1 << examtask_rates[i] << "\n";
        }
    }
};
/// <summary>
/// class name DateTime
/// </summary>
class DateTime
{
private:
    int day;
    int month;

public:
    /// <summary>
    /// а method that allows you to set day 
    /// </summary>
    /// <param name="day">value from 1 to 31</param> 
    void SetDay(int day)
    {
        if (day >= 1 && day <= 31)
        {
            this->day = day;
        }
        else
        {
            cout << "No\n";
        }
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    int GetDay() const
    {
        return day;
    }
    /// <summary>
    /// a method that allows you to set month
    /// </summary>
    /// <param name="month">value from 1 to 12</param>
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "No\n";
        }
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    int GetMonth() const
    {
        return month;
    }

    DateTime(int day) : DateTime(day, month){}

    DateTime(int day, int month) {
        SetDay(day);
        SetMonth(month);
    }
    
};
class Group
{
    Student** students = nullptr;
    int student_count = 0;
    string group_name;
    string specializ;
    int course;

public:
    Group()
    {
        SetGroupName(group_name);
        SetSpecializ(specializ);
        SetCourseNumber(course);
    }

    Group(const Group& field)
    {
        this->student_count = field.student_count;
        this->group_name = field.group_name;
        this->specializ = field.specializ;
        this->course = field.course;
        this->students = new Student * [this->student_count];
        for(int i = 0; i < this->student_count; i++)
        {
            this->students[i] = field.students[i];
        }
    }

    ~Group()
    {
        if (students != nullptr)
        {
            for (int i = 0; i < student_count; i++)
            {
                delete students[i];
            }
            delete[] students;
        }
    }

    void SetStudentCount(int student_count)
    {
        if (student_count > 0)
        {
            this->student_count = student_count;
        }
        else
        {
            cout << "No\n";
        }
    }
    int GetStudentCount() const
    {
        return student_count;
    }
    
    void SetGroupName(string group_name)
    {
        this->group_name = group_name;
    }
    string GetGroupName() const
    {
        return group_name;
    }

    void SetSpecializ(string specializ)
    {
        this->specializ = specializ;
    }
    string GetSpecializ() const
    {
        return specializ;
    }

    void SetCourseNumber(int course)
    {
        this->course = course;
    }
    int GetCourseNumber() const
    {
        return course;
    }

    void AddStudent(const Student& new_student)
    {
        Student** temp = new Student * [student_count + 1];
        for (int i = 0; i < student_count; i++)
        {
            temp[i] = new Student(*students[i]);
        }
        temp[student_count] = new Student(new_student);
        delete[] students;
        students = temp;
        student_count++;
    }

    /*void GroupSort(Group& other_group)
    {
        for (int i = 0; i < other_group.student_count; i++)
        {
            this->AddStudent(other_group.student_count(i));
        }
        // не знаю как правильно сделать слияние
        
    }*/
        
    void GoStudent(Group& another, int index)
    {
        if (index >= 0 && index < student_count)
        {
            another.AddStudent(*students[index]);
            for (int i = index; i < student_count - 1; i++)
            {
                students[i] = students[i + 1];
            }
            student_count--;
        }
    }
};

int main()
{
    Human a;
    Human b(192, 2);
}




