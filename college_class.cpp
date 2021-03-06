//possible implementation of the college_course class with the linked list of students.
#include "college_class.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

college_class::college_class()
{
    fill_students_vector_from_csv();
    //display(); //do we really need this at the beginning of the program?
}

// Display student details to console
void college_class::display()
{
    cout << endl << "Here is information of the students in your class!" << endl << endl;
    for (student s : students)
    {
        cout << "Name: " << s.get_name() << " USF ID: " << s.get_usfid()
             << " Email: " << s.get_email() << " Presentation Grade: " << s.get_presentation_grade()
             << " Essay Grade: " << s.get_essay_grade() << " Project Grade: " << s.get_term_proj_grade() << endl;
    }
}

//function to print out a specific student
void college_class::display_student(student s)
{
    cout << endl
         << "Name: " << s.get_name() << endl
         << " USF ID: " << s.get_usfid() << endl
         << " Email: " << s.get_email() << endl
         << " Presentation Grade: " << s.get_presentation_grade() << endl
         << " Essay Grade: " << s.get_essay_grade() << endl
         << " Project Grade: " << s.get_term_proj_grade() << endl
         << endl;
}

//General function to search for a record of the student.
student college_class::search_student()
{
    int search_option;
    student stud = student("", "", "", 0, 0, 0);

    cout << endl
         << "Select the number for search option: " << endl
         << "1. Search by name." << endl
         << "2. Search by USF ID." << endl
         << "3. Search by email." << endl;
    cin.clear();
    cin >> search_option;

    switch (search_option)
    {
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

    if (stud.get_name() != "")
        cout << endl
             << "Success! Record Found. Here is the student's information! " << endl;

    return stud;
}

//search student's by name
student college_class::search_option_name()
{
    string student_name;
    cout << endl
         << "Enter the student's name: ";
    cin.ignore();
    getline(cin, student_name);

    for (student s : students)
        if (s.get_name() == student_name)
            return s;

    cout << endl
         << "Unable to find " + student_name << endl;
    //since the student was not found, I am returning a blank record of a student. Please be careful and create check in the future,
    //accounting for the writing into csv file and all.
    return student("", "", "", 0, 0, 0);
}

//search student by USF ID
student college_class::search_option_ID()
{
    string student_ID;
    cout << endl
         << "Enter the student's USF ID: ";
    cin.ignore();
    getline(cin, student_ID);

    for (student s : students)
        if (s.get_usfid() == student_ID)
            return s;

    cout << endl
         << "Unable to find " + student_ID << endl;
    //since the student was not found, I am returning a blank record of a student. Please be careful and create check in the future,
    //accounting for the writing into csv file and all.
    return student("", "", "", 0, 0, 0);
}

//search student by email.
student college_class::search_option_email()
{
    string student_email;
    cout << endl
         << "Enter the student's email: ";
    cin.ignore();
    getline(cin, student_email);

    for (student s : students)
        if (s.get_email() == student_email)
            return s;

    cout << endl
         << "Unable to find " + student_email << endl;
    //since the student was not found, I am returning a blank record of a student. Please be careful and create check in the future,
    //accounting for the writing into csv file and all.
    return student("", "", "", 0, 0, 0);
}

student college_class::get_new_student_from_user()
{
    cout << endl
         << "ADD STUDENT" << endl
         << endl;

    cout << "Enter Student details" << endl
         << endl;

    cin.ignore();

    // Get student's name
    cout << "Name: ";
    string studentName;
    getline(cin, studentName);

    // Get student's ID
    cout << "USF ID: ";
    string studentId;
    getline(cin, studentId);

    // Get student's Email
    cout << "Email: ";
    string studentEmail;
    getline(cin, studentEmail);

    /* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        Potential to introduce bug by not converting string to float
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

    float presGrade;
    float essayGrade;
    float projectGrade;

    while (true)
    {
        // Get student's Grade 1
        cout << "Presentation grade: ";
        string studentPresentationGrade;
        getline(cin, studentPresentationGrade);

        // Get student's Grade 2
        cout << "Essay grade: ";
        string studentEssayGrade;
        getline(cin, studentEssayGrade);

        // Get student's Grade 3
        cout << "Project grade: ";
        string studentProjectGrade;
        getline(cin, studentProjectGrade);

        try
        {
            presGrade = stof(studentPresentationGrade);
            essayGrade = stof(studentEssayGrade);
            projectGrade = stof(studentProjectGrade);
        }
        catch (exception e)
        {
            cout << endl
                 << "You've entered an invalid value for grades. Enter (0.0 - 100.0)" << endl
                 << endl;
            continue;
        }

        break;
    }

    student stu = student(studentName, studentId, studentEmail, presGrade, essayGrade, projectGrade);

    cout << endl
         << "Successfully added student to the class." << endl
         << endl;
    return stu;
}

void college_class::save_students_vector_to_csv()
{
    ofstream out;
    out.open("students.csv");

    for (student s : students)
    {
        out << s.get_name() << "," << s.get_usfid() << "," << s.get_email() << "," << s.get_presentation_grade() << "," << s.get_essay_grade() << "," << s.get_term_proj_grade() << endl;
    }

    out.close();
}

void college_class::add_new_student()
{
    students.push_back(get_new_student_from_user());
    save_students_vector_to_csv();
}

void college_class::remove_student()
{
    student stu = search_option_ID();

    if (stu.get_name() == "")
        return;

    for (int i = 0; i < students.size(); i++)
        if (students[i].get_usfid() == stu.get_usfid())
        {
            students.erase(students.begin() + i);
            cout << endl
                 << "The student has been successfully removed from the course." << endl
                 << endl;
            save_students_vector_to_csv();
            return;
        }
}

void college_class::fill_students_vector_from_csv()
{
    string item, line;

    // Open students file
    ifstream student_file("students.csv");

    // Read in csv to create student
    // Possible introduction of bug, assumes input is correctly formatted and translates from str
    while (getline(student_file, line))
    {
        istringstream temp(line);
        vector<string> items;
        while (getline(temp, item, ','))
        {
            items.push_back(item);
        }

        student s = student(
            items[0],
            items[1],
            items[2],
            stof(items[3]),
            stof(items[4]),
            stof(items[5]));

        students.push_back(s);
    }

    // Close input file
    student_file.close();
}

void college_class::update_record()
{
    student stud = search_student();
    display_student(stud);
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

