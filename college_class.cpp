//possible implementation of the college_course class with the linked list of students.
#include "college_class.h"
#include <iostream>
using namespace std; 

void college_class::add_node(student s) {
        node* tmp = (node *)malloc(sizeof(node));
        tmp->s = s;
        tmp->next = NULL;

        // Inserting first node
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }

        
}

// Display student details to console 
void college_class::display()  {
    node *tmp;
    tmp = head;
    while (tmp != NULL)
    {
        cout << "Name: " << tmp->s.get_name() << " USF ID: " << tmp->s.get_usfid() 
        << " Email: " << tmp->s.get_email() << " Presentation Grade: " << tmp->s.get_presentation_grade()
        << " Essay Grade: " << tmp->s.get_essay_grade() << " Project Grade: " << tmp->s.get_term_proj_grade() << endl;
        tmp = tmp->next;
    }
}