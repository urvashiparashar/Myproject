#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;
class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void student::menu()
{
menustart:
    int choice; //for entering the choices
    char x;     //asking for continuation
    system("cls");
    cout << "\t\t\t-------------------------------------" << endl;
    cout << "\t\t\t    | STUDENT MANAGEMENT SYSTEM |    " << endl;
    cout << "\t\t\t-------------------------------------" << endl;
    cout << "\t\t\t 1.Enter New record" << endl;
    cout << "\t\t\t 2.Display record" << endl;
    cout << "\t\t\t 3.Modify record" << endl;
    cout << "\t\t\t 4.Search record" << endl;
    cout << "\t\t\t 5.Delete record" << endl;
    cout << "\t\t\t 6.Exit" << endl;

    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t Choose option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    cout << "Enter your choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add another student record (Y/N):";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;

    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);

    default:
        cout << "\n\t\t\t Invalid choice...Please try again..";
    }
    getch();
    goto menustart;
}
void student::insert() //adding student details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------" << endl;
    cout << "\n------------------------------------------Add Student Details----------------------------" << endl;
    cout << "\t\t\t Enter name:";
    cin >> name;
    cout << "\t\t\t Enter roll no.:";
    cin >> roll_no;
    cout << "\t\t\t Enter course:";
    cin >> course;
    cout << "\t\t\t Enter email id:";
    cin >> email_id;
    cout << "\t\t\t Enter contact no:";
    cin >> contact_no;
    cout << "\t\t\t Enter address:";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " "
         << " " << contact_no << " " << address << "\n";
    file.close();
}
void student::display()
{

    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-----------------------------------------------------------------------------------------" << endl;
    cout << "\n------------------------------------------Student Details--------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No data is present..";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student no. " << total++ << endl;
            cout << "\t\t\t Student Name. " << name << endl;
            cout << "\t\t\t Student Roll No. " << roll_no << endl;
            cout << "\t\t\t Student Course " << course << endl;
            cout << "\t\t\t Student email. " << email_id << endl;
            cout << "\t\t\t Student address " << address << endl;
            cout << "\t\t\t Student contact no. " << contact_no << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t No data is present...";
        }
    }
    file.close();
}
void student::modify()
{
    system("cls"); //clears screen
    fstream file, file1;
    int found = 0;
    string rollno;
    cout << "\n-----------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------Student Modify Details--------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No data is present";
        file.close();
    }
    else
    {
        cout << "\n enter roll no. of student whose details you want to modify:";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " "
                      << " " << contact_no << " " << address << "\n";
            }
            else
            {
                cout << "\t\t\t Enter name:";
                cin >> name;
                cout << "\t\t\t Enter roll no.:";
                cin >> roll_no;
                cout << "\t\t\t Enter course:";
                cin >> course;
                cout << "\t\t\t Enter email id:";
                cin >> email_id;
                cout << "\t\t\t Enter contact no:";
                cin >> contact_no;
                cout << "\t\t\t Enter address:";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " "
                      << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\t\t\t Student Roll No. not found..";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}
void student::search()
{
    system("cls");
    fstream file;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-----------------------------------------------------------------------------------------" << endl;
        cout << "\n-------------------------------------Student Search Data-------------------------------" << endl;
        cout << "\n\t\t\t No data is present...";
    }
    else
    {
        int found = 0;
        string rollno;
        cout << "\n-----------------------------------------------------------------------------------------" << endl;
        cout << "\n-------------------------------------Student Search Data-------------------------------" << endl;
        cout << "\n Enter roll no.of student which you want to search:";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\t\t\t Student Name. " << name << endl;
                cout << "\t\t\t Student Roll No. " << roll_no << endl;
                cout << "\t\t\t Student Course " << course << endl;
                cout << "\t\t\t Student email. " << email_id << endl;
                cout << "\t\t\t Student address " << address << endl;
                cout << "\t\t\t Student contact no. " << contact_no << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student roll no. not found" << endl;
        }
        file.close();
    }
}
void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found=0;
    string rollno;
    cout << "\n-----------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------Delete Student Details-------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No data is present...";
    }
    else
    {
        cout << "Enter roll no. of student whose details you want to delete:";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " "
                     << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout<<"\n\t\t\t Data deleted successfully!!!"<<endl;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if(found==0)
        {
            cout<<"\n\t\t\t Student Roll no. not found...";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}
int main()
{
    student project;
    project.menu();

    return 0;
}