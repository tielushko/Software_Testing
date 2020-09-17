//possible implementation of the college_course class with the linked list of students.
#include "college_class.h"
#include <vector>
#include <iostream>
using namespace std; 

// void college_class::add_student(student s) {
    
//     node* tmp = (node *)malloc(sizeof(node));
//     tmp->s = s;
//     tmp->next = NULL;

//     // Inserting first node
//     if(head == NULL)
//     {
//         head = tmp;
//         tail = tmp;
//     }
//     else
//     {
//         tail->next = tmp;
//         tail = tail->next;
//     }
// }

// Display student details to console 
void college_class::display()  {
    for(student s: students)
    {
        cout << "Name: " << s.get_name() << " USF ID: " << s.get_usfid() 
        << " Email: " << s.get_email() << " Presentation Grade: " << s.get_presentation_grade()
        << " Essay Grade: " << s.get_essay_grade() << " Project Grade: " << s.get_term_proj_grade() << endl;
    }
}