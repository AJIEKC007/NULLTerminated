#include<iostream>
#include<Windows.h>
using namespace std;
#define tab "\t"
void ASCII();
int StringLenght(char str[]);
void to_upper(char str[]);   //переводит строку в верхний регистр
void to_lower(char str[]);   //переводит в нижний регистр
void cpitalize(char str[]);  //первую букву каждого слова в приложении делает заглавной
void shrink(char str[]);     //Удаляет из строки лишние пробелы
bool is_palindrome(char str[]); //Опредиляет, является ли строка палиндромом
bool is_int_number(char str[]);	//Определяет, является ли строка целым числом
int  to_int_number(char str[]);	//Если строка - целое число, функция вернет его числовое значение.
void Hardcore(char str[]);

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

	const int n = 30;
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n); //cp1251 
	
	//ASCII();
	cout << endl <<"количество элементов: "<<endl<< StringLenght(str) << endl<<endl;
	to_upper(str);	cout <<"строка в верхнем регистре: "<<endl<< str << endl<<endl;
	to_lower(str);	cout << "Строка в нижнем регистре: " <<endl<< str << endl << endl;
	cpitalize(str);	cout <<"Первая буква каждого слова заглавная: "<< endl<<str << endl << endl;
	shrink(str);	cout << "Удаление лишних пробелов: " << endl << str << endl << endl;
	if (is_palindrome(str)) cout << "Это палиндром!"<<endl << endl; else cout<<"Это не палиндром!" << endl << endl;
	if (is_int_number(str)) cout << "Это целое число!"<<endl << endl; else cout<<"Это не целое число!" << endl << endl;
	if (is_int_number(str) == true) cout <<"Числовое значение: "<< to_int_number(str) << endl << endl; else;
	Hardcore(str);

	
	
	
}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << tab << (char)i << endl;
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
			str[i] -= 32;
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

void shrink(char str[])
{
	for (int i = 0; str[i];i++)
	{
		if (str[0]==' ' || str[i] == ' ' && str[i] == str[i + 1])
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}	
			i--;
		}
	}
}

bool is_palindrome(char str[])
{
	to_lower(str);
int s = StringLenght(str)-1;
int check=0;
	for (int i = 0, j =s; i<s, j > 0; i++, j--)
	{
		if (str[i] != str[j])
		{
			check++;
		}		
	}
	if (check == 0)return true; else return false;
}

bool is_int_number(char str[])
{
	int check = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')check; else check++;			
	}
	if (check == 0)return true; else return false;
}

int  to_int_number(char str[])
{	
	int sum = 0;	
		for (int i = 0; str[i]; i++)
		{
			int num = (str[i] - 48);
			sum = sum * 10 + num;
		}
		return sum;	
}

void Hardcore(char str[])
{
	const int n = 30;
	string text[n] = {};

	int sum=0;
	int a = 0;
	int s = StringLenght(str) - 1;
	for (int i = s; i>=0; i--)
	{
		
		int num = (str[i] - 48);

		if(a==0)
		switch (num)
		{
		case 1: text[i]= "один"; break;
		case 2: text[i] = "два"; break;
		case 3: text[i] = "три"; break;
		case 4: text[i] = "четыре"; break;
		case 5: text[i] = "пять"; break;
		case 6: text[i] = "шесть"; break;
		case 7: text[i] = "семь"; break;
		case 8: text[i] = "восемь"; break;
		case 9: text[i] = "девять"; break;
	}
		if (a == 1)
			switch (num)
			{
			case 1: text[i] = "десять"; break;
			case 2: text[i] = "двадцать"; break;
			case 3: text[i] = "тридцать"; break;
			case 4: text[i] = "сорок"; break;
			case 5: text[i] = "пятьдесят"; break;
			case 6: text[i] = "шестьдесят"; break;
			case 7: text[i] = "семьдесят"; break;
			case 8: text[i] = "восемьдесят"; break;
			case 9: text[i] = "девяносто"; break;
			}
		if (a == 2)
			switch (num)
			{
			case 1: text[i] = "сто"; break;
			case 2: text[i] = "двести"; break;
			case 3: text[i] = "триста"; break;
			case 4: text[i] = "четыреста"; break;
			case 5: text[i] = "пятьсот"; break;
			case 6: text[i] = "шестьсот"; break;
			case 7: text[i] = "семьсот"; break;
			case 8: text[i] = "восемьсот"; break;
			case 9: text[i] = "девятьсот"; break;
			}
		if (a == 3)
			switch (num)
			{
			case 1: text[i] = "одна тысяча"; break;
			case 2: text[i] = "две тысячи"; break;
			case 3: text[i] = "три тысячи"; break;
			case 4: text[i] = "четыре тысячи"; break;
			case 5: text[i] = "пять тысяч"; break;
			case 6: text[i] = "шесть тысяч"; break;
			case 7: text[i] = "семь тысяч"; break;
			case 8: text[i] = "восемь тысяч"; break;
			case 9: text[i] = "девять тысяч"; break;
			}
		
		a++;
		
			
	}
	for (int i = 0; i<a;i++)
	{
		cout << text[i] <<" ";
	}
	cout << endl << endl;
}