#include <iostream>
#include <fstream>
using namespace std;
const int MaxLen = 60;
struct line
{
	int amount_strok;
	char massiv_slov[MaxLen * 10];//строки
	int kol_slov;
	char massiv_change_strok[MaxLen * 10];
	int J = 0;
	
};
struct Text
{
	line line;
	int mrk;
	char slova_stroki[MaxLen * 5];
	int lengs;
};
//Считывание из файла условия
void InPutch(Text& text)
{
	char s; int i=0, j=0;
	ifstream f("Inpch.txt");
	if (!f.is_open())
	{
		cout << "Ошибка открытия файла " << endl;
		exit(-1);
	}

	f >> text.mrk;
	cout << text.mrk << endl;
	if (f.peek() != '\n' && !f.eof()) { while (f.peek() != '\n') { f.get(); f.clear(); } }

	cout << "Задаваемый текст : " << endl;
	while (i < MaxLen * 10)
	{
		f >> s;
		if (f.eof()) break;
		if (s != '\n')
		{
			text.slova_stroki[i] = s; j++;
			cout << text.slova_stroki[i];
		}
		i++;
	}
	cout << '\n' << "Длина строки: " << j << endl;
	text.lengs = j;
	f.close();
}
//Считывание из файла с текстомы и вывод в файл
void GeneralIn(Text& text)
{
	bool key = false;
	int kol, j = 0, i;
	char s;
	ifstream f_inn("input.txt");
	if (f_inn.bad()) cout << "Указанный файл не найден." << endl;
	else
	{
		if (f_inn.eof()) { cout << "Файл пуст." << endl; f_inn.close(); }
		else
		{
			cout << "Результаты будут выведены в файл." << endl;
			ofstream f_out("out.txt", ios::out | ios::app);
			if (f_out.bad())
			{
				cout << "Нет возможности сформировать файл с результатом." << endl;
				f_inn.close();
			}
			else
			{
				f_inn.unsetf(ios::skipws);
				kol = 0;

				cout << " Исходные данные: \n";
				f_out << " Исходные данные: \n";
				while (f_inn.eof() != 1)
				{
					j++;
					i = 0;
					while (i < MaxLen * 10)
					{
						f_inn >> s;
						if (f_inn.eof()) break;
						if (s != '\n')
						{
							text.line.massiv_slov[i] = s;
							i++; text.line.kol_slov = i;
							if (j == text.mrk) {
								key = true;
								text.line.massiv_change_strok[i] = s;
								text.line.amount_strok = i;
							}
							if (key == false)
							{
								text.line.massiv_change_strok[i] = s;
								text.line.amount_strok = text.line.kol_slov;
							}
						}
						else break;
					}

					i = 0;
					//      Вывод инфы на экран и в файл// 
					while (i < text.line.kol_slov)
					{
						cout << text.line.massiv_slov[i];
						f_out << text.line.massiv_slov[i];
						i++;
					}
					cout << '\n';
					f_out << '\n';
				}
				text.line.J = j;
				cout << text.line.J << " Кол-во строк";
				
				f_inn.close();
			}
		}
	}
}
//изменение выбранной строки
void change(Text& text)
{
	int g = 0;
	cout << '\n' << "Кол-во символов в выбранной строке " << text.line.amount_strok;
	for (int i = 0; i < text.lengs; i++)
	{
		for (int j = 0; j < text.line.amount_strok; j++)
		{
			int k = j;
			if (text.slova_stroki[i] == text.line.massiv_change_strok[j])
			{
				while (k <= text.line.amount_strok) 
				{
					text.line.massiv_change_strok[k] = text.line.massiv_change_strok[k + 1]; k++;
				}
				text.line.amount_strok--;
				j = 0;
			}
		}
	}
	cout << '\n' << "Строка после изменения: " << endl;;
	for (int j = 1; j < (text.line.amount_strok); j++)
		cout << text.line.massiv_change_strok[j];
}
//итоговый вывод в фаил
void out(Text& text)
{
	ofstream f_out("out.txt", ios::out | ios::app);
	f_out << "\nЗаданная строка для изменений: " << text.mrk << endl;
	if (text.mrk > text.line.J) f_out << "Заданная строка больше, чем строк на самом деле, поэтому изменяться будет последняя строка." << endl;
	f_out << "Задаваемый набор символов: ";
	for (int i = 0; i < text.lengs; i++)
		f_out << text.slova_stroki[i];
	f_out << "\nКол-во символов в строке-условии: " << text.lengs;

	f_out << '\n' << "Строка после изменения: ";
	for (int j = 1; j < text.line.amount_strok; j++)
		f_out << text.line.massiv_change_strok[j];

}
//функция функций
void function()
{
	Text text;
	InPutch(text);
	GeneralIn(text);
	change(text);
	out(text);
}




void main()
{
	setlocale(LC_ALL, "Russian");
	ofstream f_out("out.txt", ios::out);
	function();
}