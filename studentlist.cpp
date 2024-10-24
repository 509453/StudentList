/*Name: Aleena Shaik 
Date: 10/23/24
Project: Student List. Takes in input from the user on student info
and stores it into the vector. User can print all the data and 
delete certain student's data. 
Sources used:
https://www.youtube.com/watch?v=9E8XJ9sDJJc 
https://www.youtube.com/watch?v=qXYMB871TSA 
https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-setprecision#:~:text=How%20to%20set%20precision%20in,from%20the%20header.
My sister
Parth 

*/



#include <iostream>
#include <cstring>
#include <vector> //new library to use vectors and store data 
#include<iomanip>// this library is used to set float to only two decimals 
using namespace std;

struct Student { //struct student pointer 
    char firstname[20];
    char lastname[20];
    int id;
    float gpa; 
}; 

void addStudent(vector<Student*> &studentlist) { // function to add student. star is used to refer to the student pointer. & is used for reference and add/change values. 
  Student* student = new Student(); // creating a new student 

    cout << "Enter Student's first name: ";
    cin >> student->firstname; // storing student data using ->
    cout << "Enter Student's last name: ";
    cin >> student->lastname; 
    cout << "Enter Student's ID: ";
    cin >> student->id; 
    cout << "Enter Student's GPA: ";
    cin >> student->gpa; 

    studentlist.push_back(student); // add student to the vector 
}
void printStudent(vector<Student*>  studentlist){ // & is not used because we are not changing anything and only printing 
  for (vector<Student*>:: iterator it = studentlist.begin(); //NEW ITERATOR FOR VECTORS. goes through the list and prints out the data stored in the vector
         it !=studentlist.end(); it++){
             cout<< (*it)-> firstname <<endl; 
             cout<< (*it)-> lastname <<endl; 
             cout<< (*it)-> id <<endl; 
             cout<< fixed<<setprecision(2)<<(*it)-> gpa <<endl; //setprecisison is used for two decimal places when printing out the gpa to the user 
        
    }
}

void deleteStudent(vector<Student*> & studentlist){ // & used because we are deleting/changing data
    cout<<"Enter ID number of student you want to delete"<<endl;
    int idDel; // we need some information to match and delete student data 
    cin>>idDel;
    
    
    for (auto it = studentlist.begin(); it != studentlist.end(); ++it){ // Iterator. goes through the vector to find same student ID and erases data. 
        if ((*it) -> id ==idDel){
            delete *it; 
            studentlist.erase(it);
            break;
        }
    }
    
    
}
int main() {
  vector<Student*> studentlist; // mentioning studentlist fuction in main
  // declaring variables 
    char input[50];
    char add[]="ADD";
    char print[]= "PRINT";
    char del[]= "DELETE";
    char quit[]= "QUIT";
    bool stillPlaying = true; 
    
    cout<<"Type the command words: ADD, PRINT, DELETE, QUIT to store Student data"<<endl; 

    int j; 
    while (stillPlaying==true){ // while quit is not typed 
    cin.getline(input, 50, '\n');
   
    
    if (strcmp(input, add)==0){ // if input is ADD. add student 
          addStudent(studentlist); 
    }else if (strcmp(input, del)==0){
      deleteStudent(studentlist); // if input is DELETE. delete student
    }else if(strcmp(input, print)==0){
      printStudent(studentlist); //if input is PRINT. print all students
    }else if(strcmp(input, quit)==0){
      stillPlaying =false; // if input is QUIT, end program. 
    }
    
    }
    j++;
     
   

    return 0;
}
