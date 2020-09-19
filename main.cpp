#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "college_class.h"
using namespace std;

int main()
{
    string item, line;
    student blank = student("", "", "", 0, 0, 0); //i made this for easy comparison in my search functions.
    student stud = student("", "", "", 0, 0, 0);  //i made this for return of the student_search

    // Open students file
    ifstream student_file("students.csv");

    college_class course;

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

        course.add_student(s);
    }

    // List students
    course.display();

    // Close input file
    student_file.close();

    //initialize operation selector, class linked-list, student object, etc.
    int selection;

    //welcome message to the user
    cout << "Welcome to CEN 4072: Software Testing Class Roll System!" << endl;

    while (true)
    {

        while (true)
        {
            //ask the user to select the function to run
            cout << "Select the operation you would like to perform" << endl;
            cout << "1. Add new Student to the Class." << endl
                 << "2. Remove the Student from the class." << endl
                 << "3. View Student's record (Search for the Student)." << endl
                 << "4. Update Student's record." << endl
                 << "5. Exit application" << endl;

            cin >> selection;
            if (cin.fail())
            {
                cout << "Try again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else
            {
                break;
            }
        }

        //switch statement to run the necessary functions on the student class.
        switch (selection)
        {

        //add the student to the class
        case 1:

            break;

        //remove the student from the class
        case 2:

            break;

        //view the student's record
        case 3:
            // search by name
            stud = course.search_student();

            if (stud.get_name() != blank.get_name())
                course.display_student(stud);
            // search by UID
            // search by email
            break;

        //update student's information
        case 4:
            // perform search of the student.

            //run update of the field for the student.
            course.update_record();
            break;

        //exit the application
        case 5:
            cout << endl
                 << endl
                 << "Thank you for using the CEN4072 Class Roll System! Good bye now! Have a wonderful day!" << endl
                 << endl;
            return 0;
            break;
        default:
            cout << endl
                 << endl
                 << "Incorrect selection. Please choose a valid selection 1-5." << endl
                 << endl;
            continue;
            break;
        }
    }
    return 0;
}
