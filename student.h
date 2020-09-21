//Header file for the class of student
// Contains the information about the student: 
/* ▪ Name (up to 40 characters)
▪ USF ID (10 characters)
▪ Email (up to 40 characters)
▪ Grade of the presentation (numerical value from 0 (F) to 4 (A))
▪ Grade of essay (numerical value from 0 (F) to 4 (A))
▪ Grade of the term project (numerical value from 0 (F) to 4 (A)) 
*/
#include <iostream>
using namespace std;

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

