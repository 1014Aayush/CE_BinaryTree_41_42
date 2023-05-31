#ifndef student_h
#define student_h

class Student
{
public:
    int roll_no;
    char name;
    int age;
    Student(int roll_no = 0, char name = 'x', int age = 0)
    {
        roll_no = this->roll_no;
        name = this->name;
        age = this->age;
    }
};
#endif