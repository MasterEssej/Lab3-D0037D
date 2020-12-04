#include <iostream>
using namespace std;

void replace_chars(char *str, char srch, char re)
{
	for (*str; *str != '\0'; str++)
	{
		if (*str == srch)
		{
			*str = re;
		}
	}
}

int main()
{
	char text[] = "accuse";
	char* p = text;

	char src = 'c';
	char rep = 'b';

	cout << text << endl;
	replace_chars(p, src, rep);
	cout << text << endl;

	return 0;
}