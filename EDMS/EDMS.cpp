#include <iostream>
#include"Employee.h"

using namespace std;

int main() 
{
    EmployeeList list;
    int choice;
    do 
    {
        system("cls");
        cout << endl;
        cout << "EMPLOYEE DATABASE MANAGEMENT SYSTEM" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Display Employees" << endl;
        cout << "5. Edit Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            system("cls");
            list.addEmployee();
            break;
        }
        case 2: 
        {
            system("cls");
            list.deleteEmployee();
            break;
        }

        case 3: 
        {
            system("cls");
            string id;
            cout << "Enter the employee ID to search: ";
            cin >> id;

            Employee* employee = list.searchEmployee(id);
            if (employee != NULL) 
            {
                system("cls");
                cout << "Employee found" << endl;
                cout << "ID: " << employee->id << endl;
                cout << "Name: " << employee->name << endl;
                cout << "Address: " << employee->address << endl;
                cout << "Position: " << employee->position << endl;
                cout << "Working hours (Per month): " << employee->working_hours << endl;
                system("pause");
            }
            else 
            {
                cout << "The id number doesn't exist";
            }
            break;
        }

        case 4:
        {
            system("cls");
            list.displayEmployees();
            system("pause");
            break;
        }

        case 5:
        {
            system("cls");
            string id;
            cout << "Enter the employee ID to edit: ";
            cin >> id;
            Employee* employee = list.searchEmployee(id);
            if (employee != NULL)
            {
                system("cls");
                cout << "Employee found" << endl;
                cout << "ID: " << employee->id << endl;
                cout << "Name: " << employee->name << endl;
                cout << "Address: " << employee->address << endl;
                cout << "Position: " << employee->position << endl;
                cout << "Working hours (Per month): " << employee->working_hours << endl;
             
                do
                {
                    cout << endl;
                    cout << "EDITING OF THE \"" << id << "\" EMPLOYEE" << endl;
                    cout << "-----------------------------------------" << endl;
                    cout << "1. Change Name" << endl;
                    cout << "2. Change Address" << endl;
                    cout << "3. Change Position" << endl;
                    cout << "4. Change Working hours" << endl;
                    cout << "5. Mainmenu" << endl;
                    cout << "\nEnter your choice: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                    {
                        cout << "Employee name: ";
                        cin >> employee->name;
                        break;
                    }
                    case 2:
                    {
                        cout << "Employee address: ";
                        cin >> employee->address;
                        break;
                    }
                    case 3:
                    {
                        cout << "Employee position: ";
                        cin >> employee->position;
                        break;
                    }
                    case 4:
                    {
                        cout << "Working hours (Per Month): ";
                        cin >> employee->working_hours;
                        break;
                    }
                    case 5:
                    {
                        break;
                    }
                    default:
                    {
                        cout << "!!! Invalid choice. Please try again." << endl;
                        system("pause");
                        break;
                    }
                    }
                } while (choice != 5);

            }
            else
            {
                cout << "The id number doesn't exist";
            }
            break;
        }

        case 6:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t*****Exiting*****\n" << endl;
            break;
        }
        default:
        {
            cout << "!!! Invalid choice. Please try again." << endl;
            system("pause");
            break;
        }
        }
    } while (choice != 6);

    // Free the memory used by the linked list
    Employee* head = list.Gethead();
    Employee* currentEmployee = head;
    while (currentEmployee != nullptr)
    {
        Employee* nextEmployee = currentEmployee->next;
        delete currentEmployee;
        currentEmployee = nextEmployee;
    }

}
