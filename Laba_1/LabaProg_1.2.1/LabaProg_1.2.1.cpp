// LabaProg_1.2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;
const int N = 100;

struct Data
{
	char Str[N+1];
	char mrk;
	char a = '*';
	bool y = 0;
};
ofstream fout("Otp.txt");
void In2(Data& sData)
{
	ifstream fin("Inp.txt");
	fout << "Задаваемый текст : " << endl;
	bool err = false;
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		exit(-1);
	}
	fin >> sData.mrk; cout << "Маркер конца строки: " << sData.mrk << endl;
	if (fin.fail()) err = true;
	if (fin.peek() != '\n' && !fin.eof())
	{
		while (fin.peek() != '\n' && !fin.eof())
		{
			fin.get(); fin.clear();
		}
	};
	cout << "Задаваемый текст : " << endl;
	bool key = false;
	char tmp;
	int i = 0;
	while (fin.get(tmp))
		if (tmp == sData.a)
		{
			key = true;
			break;
		}
	for (i = 0; i < N && key; i++)
	{
		fin.get(sData.Str[i]);
		if (fin.peek() == '\n' || fin.eof() || sData.Str[i] == sData.a)
		{
			sData.Str[i + 1] = sData.mrk;
			break;
		}
		if (sData.Str[i] == sData.mrk)
			break;
		if (fin.fail() && !i)
		{
			err = true;
			break;
		}
		cout << sData.Str[i];
		fout << sData.Str[i];
	}
	if (err || !key || !i)
	{
		cout << err << " " << key << " " << i;
		cout << "Ошибка. Строка пуста." << endl;
		exit(-1);
	}
}
void In1(Data& sData)
{
	ifstream fin("Inp.txt");
	fout << "Задаваемый текст : " << endl;
	bool err = false;
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		exit(-1);
	}
	cout << "Задаваемый текст : " << endl;
	bool key = false;
	char tmp;
	int i = 0;
	while (fin.get(tmp))
		if (tmp == sData.a)
		{
			key = true;
			break;
		}
	for (i = 0; i < N && key; i++)
	{
		fin.get(sData.Str[i]);
		if (fin.peek() == '\n' || fin.eof() || sData.Str[i] == sData.a)
		{
			sData.Str[i] = sData.a;
			break;
		}
		if (fin.fail() && !i)
		{
			err = true;
			break;
		}
		cout << sData.Str[i];
		fout << sData.Str[i];
	}
	if (err || !key || !i)
	{
		cout << "Ошибка. Строка пуста." << endl;
		exit(-1);
	}
}

void OutPut(Data& sData)
{
	int count = 0; bool c = false;
	cout << endl;
	cout << "\nПовторный вывод текста: " << endl;
	fout << "\nПовторный вывод текста: " << endl;
	if (sData.y == 0)
		for (int i = 0; sData.Str[i] != sData.mrk; i++)
		{
			
			if (sData.Str[i] == '(')
			{
				
				c = true;
				count++;
			}
			if (sData.Str[i] == ')' && c == true) count--;
			if (count == 0) c = false;
			cout << sData.Str[i];
			fout << sData.Str[i];
		}
	if (sData.y == 1)
		for (int i = 0; sData.Str[i] != sData.a; i++)
		{
					if (sData.Str[i] == '(')
					{
						c = true;
						count++;
						
					}
					if (sData.Str[i] == ')' && c == true) count--;
					if (count == 0) c = false;
					cout << sData.Str[i];
					fout << sData.Str[i];
		}
	if (c == true)
	{
		cout << "\nНе каждая '(' соответствует ')': " << endl;
		fout << "\nНе каждая '(' соответствует ')': " << endl;
	}
	else
	{
		cout << "\nКаждая '(' соответствует ')': " << endl;
		fout << "\nКаждая '(' соответствует ')': " << endl;
	}
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Data sData;
	cout << "Выберите 0 или 1 : (0 - с маркером, 1 - без маркера)" << endl;
	cin >> sData.y;
	switch (sData.y)
	{
	case 0: In2(sData);
		break;
	case 1: In1(sData);
		break;
	default: exit(0);
	}
	OutPut(sData);
	return 0;
}