//possible header of the college_course class with the linked list of students.
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;

struct node 
{
    student s = student("","","",0.0,0.0,0.0);
    node* next = NULL;
};

class college_class
{
    private:
        vector<student> students = vector<student>();
    public:

        void add_student(student s)
        {
            students.push_back(s);
        };
        void display();
};

