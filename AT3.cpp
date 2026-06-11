#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name;
    int marks;
public:
    static int totalStudents;
    void input()
    {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        totalStudents++;
    }
    string getName()
    {
        return name;
    }
    int getMarks()
    {
        return marks;
    }
    void display()
    {
        cout << "Name: " << name
             << "\tMarks: " << marks << endl;
    }
};
int Student::totalStudents = 0;
class Department
{
private:
    string deptName;
    Student students[100];
    int numStudents;
public:
    void inputDepartment()
    {
        cout << "\nEnter Department Name: ";
        cin >> deptName;
        cout << "Enter Number of Students: ";
        cin >> numStudents;
        if(numStudents < 0)
            numStudents = 0;
        for(int i = 0; i < numStudents; i++)
        {
            cout << "\nStudent " << i + 1 << endl;
            students[i].input();
        }
    }
    string getDeptName()
    {
        return deptName;
    }
    int getNumStudents()
    {
        return numStudents;
    }
    void displayDepartment()
    {
        cout << "\nDepartment: " << deptName << endl;
        if(numStudents == 0)
        {
            cout << "No students in this department.\n";
            return;
        }
        for(int i = 0; i < numStudents; i++)
        {
            students[i].display();
        }
    }
    void findTopper()
    {
        if(numStudents == 0)
        {
            cout << "\nDepartment: " << deptName
                 << "\nNo students available.\n";
            return;
        }
        int maxMarks = students[0].getMarks();
        int pos = 0;
        for(int i = 1; i < numStudents; i++)
        {
            if(students[i].getMarks() > maxMarks)
            {
                maxMarks = students[i].getMarks();
                pos = i;
            }
        }
        cout << "\nDepartment Topper (" << deptName << ")\n";
        cout << "Name : " << students[pos].getName() << endl;
        cout << "Marks: " << students[pos].getMarks() << endl;
    }
    void passPercentage()
    {
        if(numStudents == 0)
        {
            cout << "Pass Percentage in "
                 << deptName
                 << " = 0%\n";
            return;
        }
        int passCount = 0;
        for(int i = 0; i < numStudents; i++)
        {
            if(students[i].getMarks() >= 50)
            {
                passCount++;
            }
        }
        float percentage =
            (float)passCount * 100 / numStudents;
        cout << "Pass Percentage in "
             << deptName
             << " = "
             << percentage
             << "%\n";
    }
    Student getDepartmentTopper()
    {
        int pos = 0;
        for(int i = 1; i < numStudents; i++)
        {
            if(students[i].getMarks() >
               students[pos].getMarks())
            {
                pos = i;
            }
        }
        return students[pos];
    }
};
int main()
{
    int numDepartments;
    cout << "Enter Number of Departments: ";
    cin >> numDepartments;
    Department dept[50];
    for(int i = 0; i < numDepartments; i++)
    {
        cout << "\nDepartment "
             << i + 1;

        dept[i].inputDepartment();
    }
    cout << "\n\n DEPARTMENT REPORT\n";
    for(int i = 0; i < numDepartments; i++)
    {
        dept[i].displayDepartment();
        dept[i].findTopper();
        dept[i].passPercentage();
        cout << endl;
    }
    bool found = false;
    Student overallTopper;
    int highestMarks = -1;
    for(int i = 0; i < numDepartments; i++)
    {
        if(dept[i].getNumStudents() == 0)
            continue;
        Student topper =
            dept[i].getDepartmentTopper();
        if(topper.getMarks() > highestMarks)
        {
            highestMarks = topper.getMarks();
            overallTopper = topper;
            found = true;
        }
    }
    cout << "\nUNIVERSITY TOPPER\n";
    if(found)
    {
        cout << "Name : "
             << overallTopper.getName()
             << endl;

        cout << "Marks: "
             << overallTopper.getMarks()
             << endl;
    }
    else
    {
        cout << "No students in university.\n";
    }
    cout << "\nTotal Students in University: "
         << Student::totalStudents
         << endl;

    return 0;
}*/

