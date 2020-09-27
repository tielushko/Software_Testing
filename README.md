# Software_Testing

# A class roll system implemented in C++, created for CEN 4072 Software Testing Course.

*** Created by Oleg Tielushko, Igor Amidzic, Yakira Quemba, John Dew, Thinh Phung ***

## Design and implementation of a small class-roll maintenance system. 

### For each student, the following data is needed:
* Name (up to 40 characters)
* USF ID (10 characters)
* Email (up to 40 characters)
* Grade of the presentation (numerical value from 0 to 100)
* Grade of essay (numerical value from 0 to 100)
* Grade of the term project (numerical value from 0 to 100)

### The capabilities the system must support are:
* Create student class data from reading students.csv file of format: Name,UID,Email,Presentation_grade,Essay_grade,Project_grade
* Retrieve student data (search) from the existing students.csv information based on Name/UID/Email.
* Add students to college class and write to csv file students.csv
* Update any or all data fields for a particular student and write to students.csv

### Main routine
* System contains of the main routine and the functions that support capabilities. 
* Main routine parses the csv file upon running, creating a vector of student objects, containing all of the data for each student.
* The supporting functions write data to the vector of students, then write that vector to a students.csv file.
* Simple console-based interface helps user navigate through all of the options available to user. 
* User can access class data by opening students.csv, modifying it directly from there using format, and later that data can be processed by application as usual.
