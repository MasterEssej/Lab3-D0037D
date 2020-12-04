#include <iostream>
using namespace std;

int find_length(char *arr)
{
	int strSize = 0;
	for (*arr; *arr != '\0'; arr++)
	{
		strSize++;
	}
	return strSize;
}

int main()
{

	char arr[] = "computer";
	char *ptr = arr;

	cout << "String length: " << find_length(ptr) << endl;
}