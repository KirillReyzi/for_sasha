// LabaProg_1.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;
const int N = 100;
struct Data
{
	char Str[N];
	int mrk;
};

void InPut(Data& text, Data& marker)
{
	ifstream f("Inp.txt");
	bool err = false;
	if (!f.is_open())
	{
		cout << "Ошибка открытия файла " << endl;
		exit(-1);
	}

	f >> marker.mrk;
	cout << "Будет считано " << marker.mrk << " сиволов в строке " << endl;
	if (f.fail()) err = true;
	if (f.peek() != '\n' && !f.eof()) { while (f.peek() != '\n') { f.get(); f.clear(); } }

	cout << "Задаваемый текст : " << endl;
	int i;
	for (i = 0; i < marker.mrk; i++)
	{
		f.get(text.Str[i]);
		cout << text.Str[i];
		if (f.peek() == '\n' || f.eof())
		{
			marker.mrk = i+1;
			cout << "\nКоличество символов, указанное пользователем, превысило размер строки " << endl;
			break;
		}
		if (f.fail() && !i)
		{
			err = true;
			break;
		}
		
		if (i == N)
		{
			marker.mrk = i;
			cout << "Место в строке закончилось " << endl;
			break;
		}
	}
	if (err || !i)
	{
		cout << "Ошибка. Строка пуста." << endl;
		exit(-1);
	}
}

void OutPut(Data& text, Data& marker)
{
	ofstream f("Otp.txt");
	int count = 0; bool c = false;
	cout << "\nПовторный вывод текста: " << endl;
	f << "\nПовторный вывод текста: " << endl;
	for (int i = 0; i < marker.mrk; i++)
	{
		if (text.Str[i] == '(')
		{
			c = true;
			count++;
		}
		if (text.Str[i] == ')' && c == true) count--;
		if (count == 0) c = false;
		cout << text.Str[i];
		f << text.Str[i];
	}
	f.close();

	if (c == true)
	{
		cout << "\nНе каждая '(' соответствует ')': " << endl;
		f << "\nНе каждая '(' соответствует ')': " << endl;
	}
	else
	{
		cout << "\nКаждая '(' соответствует ')': " << endl;
		f << "\nКаждая '(' соответствует ')': " << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Data text;
	Data marker;
	InPut(text, marker);
	OutPut(text, marker);
	return 0;
}