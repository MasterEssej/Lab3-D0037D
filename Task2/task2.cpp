#include <iostream>
using namespace std;

int average_salary(int num, const int *arr)
{
	int totSalary = 0;

	for (int i = 0; i < num; i++)
	{
		totSalary += arr[i];
	}

	totSalary = totSalary / num;

	return totSalary;
}

int main()
{

	int employees;
	cout << "Number of employees: ";
	cin >> employees;

	int *arr = new int[employees];
	int salary;

	for (int i = 0; i < employees; i++)
	{
		cout << "Salary: " << i+1;
		cin >> salary;
		arr[i] = salary;
	}

	cout << "Average salary: " << average_salary(employees, arr) << endl;

	return 0;
}