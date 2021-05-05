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
void remove_symbol(char str[], char symbol);
bool is_bin_number(char str[]);
char* dec_to_bin(int decimal);
int bin_to_dec(char str[]);
bool is_hex_number(char str[]);
int hex_to_dec(char hex[]);


void Hardcore(char str[]);

//#define STRING_DECLARATION
//#define CHECK1

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

	const int n = 256;
	char str[n] = {};
	//cout << "Введите строку: ";
	//cin >> str1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//cin.getline(str, n); //cp1251 
#ifdef CHECK1 
//ASCII();
	cout << endl << "количество элементов: " << endl << StringLenght(str) << endl << endl;
	to_upper(str);	cout << "строка в верхнем регистре: " << endl << str << endl << endl;
	to_lower(str);	cout << "Строка в нижнем регистре: " << endl << str << endl << endl;
	cpitalize(str);	cout << "Первая буква каждого слова заглавная: " << endl << str << endl << endl;
	shrink(str);	cout << "Удаление лишних пробелов: " << endl << str << endl << endl;
	//if (is_palindrome(str)) cout << "Это палиндром!"<<endl << endl; else cout<<"Это не палиндром!" << endl << endl;
	cout << "Строка " << (is_palindrome(str) ? "является полиндром" : "НЕ является полиндромом") << endl << endl;
	//if (is_int_number(str)) cout << "Это целое число!"<<endl << endl; else cout<<"Это не целое число!" << endl << endl;  
#endif // CHECK1 

	//cout << "Строка " << str << (is_int_number(str) ? "" : " НЕ") << " явлется целым числом" << endl << endl;
	//if (is_int_number(str) == true) cout <<"Числовое значение: "<< to_int_number(str) << endl << endl; else;
	//cout << to_int_number(str) *2<< endl << endl;
	//Hardcore(str);

	//cout << is_bin_number(str) << endl;
	/*int decimal;
	cout << "Введите десятичное число: "; cin >> decimal;
	cout << dec_to_bin(decimal) << endl;
	cout << str << "(bin) = " << bin_to_dec(str) << "(dec)\n";*/
	cout << "Введите шестнадцатиричное число: "; cin >> str;
	cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является шестнадцетиричным числом! \n";
	cout << str << "(hex) = " << hex_to_dec(str) << "(dec)\n";

	
	
	
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
	int lenght = StringLenght(str);
	char* buffer = new char[lenght+1] {};
	for (int i = 0; i < lenght; i++)
	{
		buffer[i] = str[i];
	}

	to_lower(buffer);
	remove_symbol(buffer, ' ');
	lenght = StringLenght(buffer);
	bool is_palindrome = true;
	for (int i = 0; i < lenght/2; i++)
	{
		if (buffer[i] != buffer[lenght - 1 - i])
			is_palindrome = false;
		break;
	}
	delete[] buffer;
	return is_palindrome;

	//int s = StringLenght(str)-1;
//int check=0;
//	for (int i = 0, j =s; i<s, j > 0; i++, j--)
//	{
//		if (str[i] != str[j])
//		{
//			check++;
//		}		
//	}
//	if (check == 0)return true; else return false;
}

bool is_int_number(char str[])
{

	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9')&& str[i] != ' ') return false;	
		if (str[i] == ' ' && str[i + 1]== ' ')return false;
	}
return true;
	/*int check = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')check; else check++;			
	}
	if (check == 0)return true; else return false;*/
}

int  to_int_number(char str[])
{	
	if (!is_int_number(str))return 0;
	int decimal = 0; //десятичное значение числа
	for (int i = 0; str[i]; i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			decimal *= 10;// сдвигаем число на один разряд влево
			decimal += str[i] - '0';
		}
	}
	return decimal;

	/*int sum = 0;	
		for (int i = 0; str[i]; i++)
		{
			int num = (str[i] - 48);
			sum = sum * 10 + num;
		}
		return sum;	*/
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i ; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
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

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i]!=' ')
			return false;
		if (str[i] == ' ' && str[i - 1] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

char* dec_to_bin(int decimal)
{
	//1)Определим кол-во двоичных разрядов
	int capacity = 0;
	int buffer = decimal;
	for (; buffer; capacity++)
	{
		buffer /= 2;
		if (capacity % 4 == 0)capacity++;
	}

	//2)Выделяем память под двоичное число
	char* bin = new char[capacity + 1]{};
	//3) Получаем разаряды двоичного числа, и сохраняем их в строку
	for (int i = 0,digit=0; decimal; i++,digit++)
	{
		//
		//if (digit % 4 == 0)
		//{
		//	//bin[i] = ' ';
		//}
		//else
		{
			bin[i] = decimal % 2 + '0';   //получаем младший разряд числа
			decimal /= 2;                 // убираем младший разряд из числа
		}
	}
	return bin;
}

int bin_to_dec(char str[])
{
if (!is_bin_number(str))return 0;
#ifdef DEBUG
	
	int decimal = 0; //конечное десятично число
	int weight = 1;  // весовой коэффициент разряда 2^n
	int capacity = strlen(str); // разрядность двоичного числа
	for (int i = capacity - 1; i >= 0; i--)
	{
		decimal +=
	}
#endif // DEBUG

	int decimal = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i]!=' ')
		{
			decimal *= 2;
			decimal += str[i] - '0';
		}
	}
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = str[0] == '0' && (str[1]=='x' || str[1] == 'X')?2 :0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f')
			)
			return false;
	}
	return true;
}

int hex_to_dec(char hex[])
{
	if (!is_hex_number(hex))return 0;
	int decimal = 0;
	for (int i = 0; hex[i]; i++)
	{
		decimal *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')decimal += hex[i] - '0';
		if (hex[i] >= 'A' && hex[i] <= 'F')decimal += hex[i] - 'A' + 10;
		if (hex[i] >= 'a' && hex[i] <= 'f')decimal += hex[i] - 'a' + 10;
	}
	return decimal;
}
