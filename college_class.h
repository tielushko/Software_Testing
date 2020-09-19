//possible header of the college_course class with the linked list of students.
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;

struct node
{
    student s = student("", "", "", 0.0, 0.0, 0.0);
    node *next = NULL;
};

class college_class
{
private:
    vector<student> students = vector<student>();
    student get_new_student_from_user();
    void save_students_vector_to_csv();
    void fill_students_vector_from_csv();

public:
    college_class();

    void add_new_student();
    void add_student(student s);

    //display functions
    void display();
    void display_student(student s);

    //search functions
    student search_student();
    student search_option_name();
    student search_option_ID();
    student search_option_email();
};