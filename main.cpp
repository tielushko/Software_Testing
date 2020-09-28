#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

/**** STUDENT CLASS ****************/
// Contains the information about the student: 
/* ▪ Name (up to 40 characters)
▪ USF ID (10 characters)
▪ Email (up to 40 characters)
▪ Grade of the presentation (numerical value from 0 (F) to 4 (A))
▪ Grade of essay (numerical value from 0 (F) to 4 (A))
▪ Grade of the term project (numerical value from 0 (F) to 4 (A)) 
*/
class student {
    private:
        float presentation_grade;
        float essay_grade;
        float term_proj_grade;

    public:
        string Name;
        string USFID;
        string Email;
    
    student(string name, string id, string email, float pres_grade, float ess_grade, float proj_grade)
    {
        Name = name;
        USFID = id;
        Email = email;
        presentation_grade = pres_grade;
        essay_grade = ess_grade;
        term_proj_grade = proj_grade;
    }
        
    // Setter and getter methods 
    string get_name()
    {
        return Name;
    }

    void set_name(string name)
    {
        Name = name;
    }

    string get_usfid()
    {
        return USFID;
    }

    void set_usfid(string id)
    {
        USFID = id;
    }

    string get_email()
    {
        return Email;
    }

    void set_email(string email)
    {
        Email = email;
    }

    float get_presentation_grade()
    {
        return presentation_grade;
    }

    void set_presentation_grade(float grade)
    {
        presentation_grade = grade;
    }

    float get_essay_grade(){
        return essay_grade;
    }

    void set_essay_grade(float grade)
    {
        essay_grade = grade;
    }

    float get_term_proj_grade() 
    {
        return term_proj_grade;
    }

    void set_term_proj_grade(float grade)
    {
        term_proj_grade = grade;
    }
};

/**** COLLEGE_CLASS CLASS ****************/
// HEADER 
ofstream student_files("students.csv");
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
    void remove_student();

    //display functions
    void display();
    void display_student(student s);

    //search functions
    student search_student();
    student search_option_name();
    student search_option_ID();
    student search_option_email();
    void update_record();
};

// FUNCTIONALITY 
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
    //cin.clear();
    cin >> search_option;

    switch (search_option)
    {
    case 1:
        stud = search_option_ID();
        break;
    case 2:
        stud = search_option_email();
        break;
    case 3:
        stud = search_option_name();
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
    cin >> student_name; // will mess up when user enters space for the name. Only picks up one word.
    //cin.ignore(); //missing the cin to gather input from the user.
    //getline(cin, student_name);

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
    cin >> student_ID;
    //cin.ignore(); //bug seeded
    //getline(cin, student_ID);  //bug seeded to mess up input.

    for (student s : students)
        if (s.get_usfid() != student_ID) //seeded bug to find the wrong record.
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
            return student("", "", "", 0, 0, 0); //returns empty student element instead of the one found.

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
    cin >> studentName;

    // Get student's ID
    cout << "USF ID: ";
    string studentId;
    cin >> studentId;

    // Get student's Email
    cout << "Email: ";
    string studentEmail;
    cin  >> studentEmail;

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

        break;
    }

    student stu = student(studentName, studentId, studentEmail, presGrade, essayGrade, projectGrade);
}

void college_class::save_students_vector_to_csv()
{
    ofstream out;
    out.open("students.csv");

    for (student s : students)
    {
        //bug with adding commas with spaces
        out << s.get_name() << "," << s.get_usfid() << "," << s.get_email() << "," << s.get_presentation_grade() << "," << s.get_essay_grade() << "," << s.get_term_proj_grade();
    }

    //hohoho bug to not close the fileeee hehehe
    //out.close();
}

void college_class::add_new_student()
{
    student stu = get_new_student_from_user();
    students.push_back(stu);
    save_students_vector_to_csv();

    cout << endl
         << "Successfully added student to the class." << endl
         << endl;
}

void college_class::remove_student()
{
    student stu = search_option_ID();

    if (stu.get_name() == "")
        return;

    cout << stu.get_name() << endl;
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

    // Open students file to read/write
    ifstream student_file("students.csv");

    if(student_file.good()) 
    {
        student_files << "Success (Code 20): File Exists!" << endl; // malloc bug 
        student_file.clear();
    }

    // Read in csv to create student
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
    student_file.clear(); 
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

/**** END OF COLLEGE_CLASS *********/

/**** MAIN FUNCTIONALITY ***********/
namespace h {
    void print_menu() {
                cout << endl << "Select the operation you would like to perform" << endl;
                cout << "1. Add new Student to the Class." << endl 
                << "2. Remove the Student from the class." << endl 
                << "3. View Student's record (Search for the Student)." << endl 
                << "4. Update Student's record." << endl 
                << "5. View Class Roster." << endl 
                << "6. Exit application" << endl;         
    }
}

int main() {
    student blank = student("","","",0,0,0); //i made this for easy comparison in my search functions.
    student stud = student("","","",0,0,0); //i made this for return of the student_search

    college_class course;

    //initialize operation selector, class linked-list, student object, etc.
    int selection;

    //welcome message to the user
    cout << "Welcome to CEN 4072: Software Testing Class Roll System!" << endl;

    
    while (true) {
        int selection;
        //ask the user to select the function to run
        //menu to display first.
        h::print_menu();
        
        //input validation for the selection string
        /*while (!(cin >> selection)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Bad data entered. Try again." << endl;
            h::print_menu();
        }*/ //no input valudation will create more bugs
       
        cin >> selection;
        
        //switch statement to run the necessary functions on the student class.
        switch (selection) {

            //add the student to the class
            case 1:
                course.add_new_student();
                break;

            //remove the student from the class
            case 2:
                course.remove_student();
                break;

            //view the student's record
            case 3:
                // search by name
                // search by UID
                // search by email
                stud = course.search_student();
                if (stud.get_name() != blank.get_name()) 
                    course.display_student(stud);
                break;

            //update student's information    
            case 4:
                // perform search of the student.

                //run update of the field for the student.
                course.update_record();
                break;
            //display current roster.
            case 5:
                course.display();
                break;
            //exit the application
            case 6:
                cout << endl << endl << "Thank you for using the CEN4072 Class Roll System! Good bye now! Have a wonderful day!" << endl << endl;
                return 0;
                break;
            default:
                //silly bug for while loop
                while(true) { 
                cout << endl << endl << "Incorrect selection. Please choose a valid selection 1-6." << endl << endl;
                //continue; will just continually loop instead of
                }
                break;
            
            }
    }
    return 0;
}
