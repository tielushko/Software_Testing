#include <iostream>

using namespace std;

int main() {
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

        //switch statement to run the necessary functions on the student class.
        switch (selection) {

            //add the student to the class
            case 1:
                
                break;

            //remove the student from the class
            case 2:
                
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
                course.update_record();
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
