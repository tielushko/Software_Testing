//possible header of the college_course class with the linked list of students.
#include <iostream>
#include "student.h"
using namespace std;

struct node 
{
    student s = student(NULL,NULL,NULL,0.0,0.0,0.0);
    node* next;
};

class college_class
{
    private:
        node *head, *tail;

    public:
        college_class() 
        {
            head = NULL;
            tail = NULL;
        }

        void add_node(student s);
        void display();
};

