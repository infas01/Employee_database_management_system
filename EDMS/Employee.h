#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee 
{
public:
    string id;
    string name;
    string address;
    int position;
    int working_hours;
    int joined_year;
    Employee* next;
    Employee(string Id,string Name, string Address, int Position, int Working_hours, int Joined_year)
    {
        id = Id;
        name = Name;
        address = Address;
        position = Position;
        working_hours = Working_hours;
        joined_year = Joined_year;
        next = NULL;
    }
};

class EmployeeList 
{
private:
    Employee* head;
    Employee* tail;
    int size;
public:
    EmployeeList() 
    {
        head = NULL;
        tail = NULL;
        size = 10;
    }
    Employee* Gethead() 
    {
        return head;
    }

    bool isIdexist(string id) 
    {
        Employee* currentEmployee = head;

        while (currentEmployee != NULL) 
        {
            if (currentEmployee->id == id) 
            {
                return true;
            }
            currentEmployee = currentEmployee->next;

        }
        return false;

    }
    
    void addEmployee() 
    {
        string id;
        string name;
        string address;
        int position;
        int working_hours;
        int joined_year;
        string other = "Y";
        while (other == "Y")
        {
            bool x = false;
            while (x == false) 
            {
                system("cls");
                cout << "Enter the employee ID: ";
                cin >> id;
                x = isIdexist(id);
                if (x == true) 
                {
                    cout << "The Id already exists" << endl;
                    x = false;
                    system("pause");
                }
                else 
                {
                    x = true;
                }
            }

            cout << "Enter the employee name: ";
            cin >> name;

            cout << "Enter the employee address: ";
            cin >> address;

            do
            {
                cout << "Enter the employee position: " << endl;;
                cout << "1. Level 1" << endl;
                cout << "2. Level 2" << endl;
                cout << "3. Level 3" << endl;
                cout << "4. Level 4" << endl;
                cout << "5. Level 5" << endl;
                cout << "Enter the position: ";
                cin >> position;

                if (position < 1 || position > 5)
                {
                    cout << "!!! Invalid position. Please try again." << endl;
                    system("pause");
                }
                                          

            } 
            while (position < 1 ||position > 5);

           

            cout << "Working hours of the employee (Per month): ";
            cin >> working_hours;

            cout << "Employee joined year: ";
            cin >> joined_year;

            Employee* newEmployee = new Employee(id, name, address, position, working_hours, joined_year);
            // If the linked list is empty, set the head to the new employee
            if (head == NULL) 
            {
                head = newEmployee;
            }
            // Otherwise, add the new employee to the end of the linked list
            else 
            {
                Employee* currentEmployee = head;
                while (currentEmployee->next != NULL) 
                {
                    currentEmployee = currentEmployee->next;
                }
                currentEmployee->next = newEmployee;
            }

            cout << "\nEmployee added successfully" << endl;

            cout << "\nEnter Y to add another Employee\nEnter N to return to Mainmenu" << endl;
            cout << "Y / N: ";
            cin >> other;
        }
    }
    void deleteEmployee() 
    {
        string id;

        if (head == NULL) 
        {
            cout << "Employee list is empty" << endl;
            return;
        }
        cout << "Enter the employee ID to delete: ";
        cin >> id;
        Employee* currentEmployee = head;
        Employee* prevEmployee = NULL;

        while (currentEmployee != NULL && currentEmployee->id != id) 
        {
            prevEmployee = currentEmployee;
            currentEmployee = currentEmployee->next;
        }

        if (currentEmployee == NULL) 
        {
            cout << "Employee not found" << endl;
            return;
        }

        if (prevEmployee == NULL) 
        {
            head = head->next;
        }
        else {
            prevEmployee->next = currentEmployee->next;
        }

        delete currentEmployee;
        cout << "Employee deleted successfully" << endl;
        system("pause");
    }

    void displayEmployees() 
    {

        if (head == NULL) 
        {
            cout << "Employee list is empty" << endl;
            return;
        }
        int cy;
        cout << "Enter the current year: ";
        cin >> cy;

        system("cls");
        cout << "List of Employees" << endl;
        cout << "-----------------" << endl;
        Employee* currentEmployee = head;
        while (currentEmployee != nullptr) 
        {
            cout << "ID: " << currentEmployee->id << endl;
            cout << "Name: " << currentEmployee->name << endl;
            cout << "Address: " << currentEmployee->address << endl;
            cout << "Position: " << currentEmployee->position << endl;
            cout << "Working hours (Per month): " << currentEmployee->working_hours<< endl;
            cout << "Salary: " << calcSalary(currentEmployee->working_hours, currentEmployee->position) << endl;
            cout << "Experience: " << calcExperience(currentEmployee->joined_year,cy) << endl;
            cout << endl;
            currentEmployee = currentEmployee->next;
        }
    }

    Employee* searchEmployee(string id) 
    {
        Employee* currentEmployee = head;

        while (currentEmployee != NULL && currentEmployee->id != id) 
        {
            currentEmployee = currentEmployee->next;
        }

        if (currentEmployee == NULL) 
        {
            cout << "Employee not found" << endl;
            return NULL;
        }

        return currentEmployee;
    }

    int calcSalary(int wh, int p)
    {
        if (p == 1)
        {
            int salary = 1500 * wh;
            return salary;
        }
        else if (p == 2)
        {
            int salary = 1200 * wh;
            return salary;
        }
        else if (p == 3)
        {
            int salary = 1000 * wh;
            return salary;
        }
        else if (p == 4)
        {
            int salary = 800 * wh;
            return salary;
        }
        else
        {
            int salary = 500 * wh;
            return salary;
        }
             
    }

    int calcExperience(int jy,int cy)
    {
        int experience = cy - jy;
        return experience;
    }

    
};





