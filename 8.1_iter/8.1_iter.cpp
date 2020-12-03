// Дано літерний рядок, який містить послідовність символів s0, …, sn, … .
//1. Вияснити, чи є в цій послідовності такі елементи s[i], s[i + 1] що s[i] – це кома(“, ”), 
//а s[i + 1] – тире(“–”), та обчислити їх кількість.
//2. Замінити кожну групу символів “, –” зірочкою “* ”.
#include <iostream>
using namespace std;
int Count(char* str)
{
	if (strlen(str) < 2)
		return 0;
	int k = 0;
	for (int i = 1; str[i + 1] != 0; i++)
		if (str[i] == ',' && str[i + 1] == '–')
			k++;
	return k;
}
char* Change(char* str)
{
	if (strlen(str) < 2)
		return str;
	char* tmp = new char[strlen(str) * 1 / 2 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	int i = 0;
	while (str[i + 1] != 0)
	{
		if (str[i] == ',' && str[i + 1] == '-')
		{
				strcat_s(t, 101, "*");
			t += 1;
			i += 2;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy_s(str, 101, tmp);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of ', -'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}