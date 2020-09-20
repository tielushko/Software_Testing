#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cstdio>
#include "college_class.h"
using namespace std;



//This function removes the line with the students name to be removed from the students.csv file
void remove_line(string remove_name)
{
	string line1;
	string item1;
	string delete_line;
	int found_line = 0;
	ifstream fin("students.csv");
	ofstream temp;
	temp.open("temp.csv");
	int one = 0;
	

	while (getline(fin, line1))
	{
		istringstream temp1(line1);
		vector<string> items1;
		
		while (getline(temp1, item1, ','))
		{
			items1.push_back(item1);
			one = 1;
		}

		if (one == 1)
		{
			if (items1[0] == remove_name)
			{
				delete_line = line1;
				found_line = 1;
				line1.replace(line1.find(delete_line), delete_line.length(), "");
			}
			else
			{
				if (line1 != delete_line)
				{
					temp << line1 << endl;
				}
				
			}
		}

	}


	temp.close();
	fin.close();
	remove("students.csv");
	rename("temp.csv", "students.csv");


}








int main() {
    string item, line;

    // Open students file
    ifstream student_file("students.csv");

    college_class course;

    // Read in csv to create student
    // Possible introduction of bug, assumes input is correctly formatted and translates from str
    while(getline(student_file, line))
    {
        istringstream temp(line);
        vector<string> items;
        while(getline(temp, item, ','))
        {
            items.push_back(item);
        }

        student s = student(
            items[0],
            items[1],
            items[2],
            stof(items[3]),
            stof(items[4]),
            stof(items[5])
        );

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

    
    while (true) {
        
        //ask the user to select the function to run
        cout << "Select the operation you would like to perform" << endl;
        cout << "1. Add new Student to the Class." << endl << "2. Remove the Student from the class." << endl 
        << "3. View Student's record (Search for the Student)." << endl << "4. Update Student's record." << endl << "5. Exit application" << endl;
        
        cin >> selection;
		string remove_name;
		string first_remove;
		string last_remove;
	
		//char remove_name[100] = { 0 };
        //switch statement to run the necessary functions on the student class.
        switch (selection) {

            //add the student to the class
            case 1:
                
                break;

            //remove the student from the class
            case 2:
				//First removes from vector
				cout << "Enter first name of person you want to remove from class:";
				cin >> first_remove;
				cout << "Enter the last name of the person you want to remove:";
				cin >> last_remove;
				remove_name = first_remove + " " + last_remove;
				course.remove_student(remove_name);
				//Secondly removes from .csv file
				remove_line(remove_name);
				
                break;

            //view the student's record
            case 3:
                // search by name

                // search by UID

                // search by email
                break;

            //update student's information    
            case 4:
                // perform search of the student.

                //run update of the field for the student.
                break;
            
            //exit the application
            case 5:
                cout << endl << endl << "Thank you for using the CEN4072 Class Roll System! Good bye now! Have a wonderful day!" << endl << endl;
                return 0;
                break;
            default:
                cout << endl << endl << "Incorrect selection. Please choose a valid selection 1-5." << endl << endl;
                continue;
                break;

				
        }
    }
    return 0;
}

