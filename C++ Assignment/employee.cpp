/*
Write a program by creating an Employee class having the following functions and print the
final salary.
1 getInfo() which takes the salary, number of hours of work per day of employee as parameters
2 AddSal() which adds $10 to the salary of the employee if it is less than $500.
3 AddWork() which adds $5 to the salary of the employee if the number of hours of work per
day is more than 6 hours.
*/

#include<iostream>
using namespace std;

class Employee{
    int salary, hours;
    public:
        void getInfo(int a, int b){
            salary = a;
            hours = b;
        }

        void AddSal(){
            if (salary<500){ salary+=10; }
        }

        void AddWork(){
            if(hours>6){ salary+=5; }
        }

        void display(){
            cout<<"Salary:"<< salary << endl;
            cout<<"Number of hours:"<< hours << endl;
        }
};

int main(){
    Employee emp1;
    int a, b;

    cout << "Enter the salary:";
    cin >> a;

    cout<< endl << "Enter the number of hours of work per day:";
    cin>>b;

    emp1.getInfo(a, b);
    emp1.AddSal();
    emp1.AddWork();
    emp1.display();

    return 0;
}
