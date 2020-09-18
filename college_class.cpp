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

//function to print out a specific student
void college_class::display_student(student s) {
    cout << endl << "Name: " << s.get_name() << endl << " USF ID: " << s.get_usfid() << endl
    << " Email: " << s.get_email() << endl << " Presentation Grade: " << s.get_presentation_grade() << endl
    << " Essay Grade: " << s.get_essay_grade() << endl << " Project Grade: " << s.get_term_proj_grade() << endl << endl;
}

//General function to search for a record of the student.
student college_class::search_student() {
    int search_option;
    student stud = student("","","",0,0,0);
        
    cout << endl << "Select the number for search option: " << endl
    << "1. Search by name." << endl << "2. Search by USF ID." << endl << "3. Search by email." << endl;
    cin.clear();
    cin >> search_option;
    
    switch(search_option) {
        case 1:
            stud = search_option_name();
            break;
        case 2:
            stud = search_option_ID();
            break;
        case 3:
            stud = search_option_email();
            break;
    }
    return stud;
}

//search student's by name
student college_class::search_option_name() {
    string student_name; 
    cout << endl << "Enter the student's name: " << endl;
    cin.ignore();
    getline(cin, student_name);
    

    for (student s : students) {
        if (s.get_name() == student_name) {
            cout << endl << "Success! Record Found. Here is the student's information! " << endl;
            return s;
        } //else {
        //}
    }
    cout << endl << "Unable to find " + student_name << ". Please try again!" << endl << endl;
    //since the student was not found, I am returning a blank record of a student. Please be careful and create check in the future,
    //accounting for the writing into csv file and all.
    return student("","","", 0, 0, 0);
}

//search student by USF ID
student college_class::search_option_ID() {
    string student_ID; 
    cout << endl << "Enter the student's USF ID: " << endl;
    cin.ignore();
    getline(cin, student_ID);
    

    for (student s : students) {
        if (s.get_usfid() == student_ID) {
            cout << endl << "Success! Record Found. Here is the student's information! " << endl;
            return s;
        } //else {
        //}
    }
    cout << endl << "Unable to find " + student_ID << ". Please try again!" << endl << endl;
    //since the student was not found, I am returning a blank record of a student. Please be careful and create check in the future,
    //accounting for the writing into csv file and all.
    return student("","","", 0, 0, 0);
}

//search student by email.
student college_class::search_option_email() {
    string student_email; 
    cout << endl << "Enter the student's email: " << endl;
    cin.ignore();
    getline(cin, student_email);
    

    for (student s : students) {
        if (s.get_email() == student_email) {
            cout << endl << "Success! Record Found. Here is the student's information! " << endl;
            return s;
        }
    }
    cout << endl << "Unable to find " + student_email << ". Please try again!" << endl << endl;
    //since the student was not found, I am returning a blank record of a student. Please be careful and create check in the future,
    //accounting for the writing into csv file and all.
    return student("","","", 0, 0, 0);
}