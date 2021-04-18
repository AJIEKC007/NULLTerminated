#include<iostream>
#include<Windows.h>
using namespace std;

void ASCII();
int StringLenght(char str[]);
void to_upper(char str[]); //переводит строку в верхний регистр
void to_lower(char str[]); //переводит в нижний регистр
void cpitalize(char str[]); //первую букву каждого слова в приложении делает заглавной

//#define STRING_DECLARATION

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef STRING_DECLARATION 
	/*char str[] = { 'h','e', 'l', 'l', 'o' ,0};
for(int i=0;i<sizeof(str);i++)cout<<str[i];cout<<endl;*/
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof("Hello") << endl;

	
#endif // STRING_DECLARATION 

	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n); //cp1251
	cout << str << endl; //cp866  

	cout << StringLenght(str) << endl;
	to_upper(str);
	cpitalize(str);
	cout << str << endl;

}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}

int StringLenght(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
			str[i] -= ' ';
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
			str[i] += 32;
	}

}

void cpitalize(char str[])
{
	to_lower(str);
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;

	for (int i = 0; str[i]; i++)
	{
		if (str[i - 1] == ' ')
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
				str[i] -= 32;
		}
	}
}
