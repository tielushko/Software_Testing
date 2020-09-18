//possible implementation of the college_course class with the linked list of students.
#include "college_class.h"
#include <vector>
#include <iostream>
using namespace std; 

// Display student details to console 
void college_class::display()  {
    for(student s: students)
    {
        cout << "Name: " << s.get_name() << " USF ID: " << s.get_usfid() 
        << " Email: " << s.get_email() << " Presentation Grade: " << s.get_presentation_grade()
        << " Essay Grade: " << s.get_essay_grade() << " Project Grade: " << s.get_term_proj_grade() << endl;
    }
}

void college_class::remove_student(string full_name)
{

	int index = 0;
	for (student s : students)
	{
		if (full_name == s.get_name())
		{
			//delete from vector
			cout << "Student Succesfully Removed";
			students.erase(students.begin() + index);
			break;
		
		}

		index++;

	}


}