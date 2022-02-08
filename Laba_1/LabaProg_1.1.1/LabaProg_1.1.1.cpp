// LabaProg_1.1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;
const int N = 100;

struct Data
{
	char Str[N+1];
	char mrk;
	bool cnt = false;
};

void Input(Data& text, Data& marker, Data& count)

{
	ifstream f("Inp.txt");
	bool err = false; int i;

	if (!f.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		exit(-1);
	}

	f >> marker.mrk;
	cout << "Маркер конца строки : " << marker.mrk << endl;
	if (f.fail()) err = true;

	if (f.peek() != '\n' && !f.eof()) { while (f.peek() != '\n') { f.get(); f.clear(); } }

	cout << "Задаваемый текст : " << endl;
	for (i = 0; i < N; i++)
	{
		f.get(text.Str[i]);
        cout << text.Str[i];
		if (f.peek() == '\n' || f.eof())
		{
			count.cnt = true;
			cout << "\nМаркер так и не был найден." << endl;
			marker.mrk = text.Str[1];
			cout << "Маркером взят первый символ текста: " << marker.mrk << endl;
			text.Str[i+1] = marker.mrk;
			break;
		}

		if (text.Str[i] == marker.mrk)
		{
			break;
		}

		if (f.fail() && !i)
		{
			err = true;
			break;
		}

		
	}
	if (err || !i)
	{
		cout << "Ошибка. Строка пуста." << endl;
		exit(-1);
	}

}

void Output(Data& text, Data& marker, Data& log)

{
	ofstream f("Otp.txt"); int i = 0, count = 0; bool c = false;
	cout << endl;
	cout << "Повторный вывод текста: " << endl;
	f << "Повторный вывод текста: " << endl;
	if (log.cnt == true) { i = 2; }
	while (marker.mrk != text.Str[i])
	{
		if (text.Str[i] == '(')
		{
			c = true;
			count++;
		}
		if (text.Str[i] == ')' && c==true) count--;
		if (count == 0) c = false;
		cout << text.Str[i];
		f << text.Str[i];
		i = i + 1;
	}
	
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
f.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Data text;
	Data marker;
	Data count;
	Input(text, marker, count);
	Output(text, marker, count);
}


