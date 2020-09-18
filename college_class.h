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

        //display functions
        void display();
        void display_student(student s);

        //search functions
        student search_student();
        student search_option_name();
        student search_option_ID();
        student search_option_email();
};
   /*
    void print_menu() {
        cout << endl << "Bad data entered. Try again." << endl << endl;
                cout << "Select the operation you would like to perform" << endl;
                cout << "1. Add new Student to the Class." << endl << "2. Remove the Student from the class." << endl 
                << "3. View Student's record (Search for the Student)." << endl << "4. Update Student's record." << endl << "5. Exit application" << endl;
            
    }
*/