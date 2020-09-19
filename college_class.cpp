//possible implementation of the college_course class with the linked list of students.
#include "college_class.h"
#include <vector>
#include <iostream>
#include <fstream>
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
        }
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
        } 
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

//update() --> update the grade and email of the student after using search()
void college_class::update_record()
{
    student stud = search_student();
    int option;
    float grade;
    string str;

    if (stud.get_name() != "")
    {

        ofstream out;
        out.open("students.csv");

        while (true)
        {
            cout << endl
                 << "Select the number for update option: " << endl
                 << "1. Presentation Grade" << endl
                 << "2. Essay Grade." << endl
                 << "3. Project Grade." << endl
                 << "4. Email." << endl;
            cin >> option;
            if (cin.fail())
            {
                cout << "Try again for update option!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (option < 1 || option > 4)
            {
                cout << "The number for update option is between 1 and 4!" << endl;
            }
            else
            {
                break;
            }
        }

        switch (option)
        {
        case 1:

            while (true)
            {
                cout << "Enter the grade for Presentation:" << endl;
                cin >> grade;
                if (cin.fail())
                {
                    cout << "That is not a valid number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else
                {
                    break;
                }
            }
            for (student &s : students)
            {
                if (s.get_name() == stud.get_name())
                {
                    s.set_presentation_grade(grade);
                    break;
                }
            }

            break;
        case 2:

            while (true)
            {
                cout << "Enter the grade for Essay:" << endl;
                cin >> grade;
                if (cin.fail())
                {
                    cout << "That is not a valid number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else
                {
                    break;
                }
            }
            for (student &s : students)
            {
                if (s.get_name() == stud.get_name())
                {
                    s.set_essay_grade(grade);
                    break;
                }
            }

            break;
        case 3:

            while (true)
            {
                cout << "Enter the grade for Project:" << endl;
                cin >> grade;
                if (cin.fail())
                {
                    cout << "That is not a valid number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else
                {
                    break;
                }
            }
            for (student &s : students)
            {
                if (s.get_name() == stud.get_name())
                {
                    s.set_term_proj_grade(grade);
                    break;
                }
            }

            break;
        case 4:
            while (true)
            {
                cout << "Enter the new email:" << endl;
                cin >> str;
                if (cin.fail())
                {

                    cout << "That is not a valid string" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else
                {
                    break;
                }
            }

            for (student &s : students)
            {
                if (s.get_name() == stud.get_name())
                {
                    s.set_email(str);
                    break;
                }
            }

            break;
        }
        // update the information for student.csv
        for (student s : students)
        {
            out << s.get_name() << "," << s.get_usfid() << "," << s.get_email() << "," << s.get_presentation_grade() << "," << s.get_essay_grade() << "," << s.get_term_proj_grade() << endl;
        }
        out.close();
       
    }
}
