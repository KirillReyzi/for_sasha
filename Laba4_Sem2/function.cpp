#include "lists.h"

void finaldata(Page& indata, Page& checkdata, Stroka& outdata)
{
	Page::NODE* tmpStr = indata.head;
	for (int i = 0; i < indata.Size; i++)
	{
		Stroka::NODE* tmp = tmpStr->value.head;
		for (int j = 0; j < tmpStr->value.Size; j++)
		{
			if ((!outdata.CheckChar(tmp->value)) && (!checkdata.CheckChar(tmp->value)))
				outdata.push_back(tmp->value);
			tmp = tmp->next;
		}
		tmpStr = tmpStr->next;
	}
}

void GenerateData(Page& indata1, Page& indata2, Stroka& outdata)
{
	finaldata(indata1, indata2, outdata);
	finaldata(indata2, indata1, outdata);
}

int MainFunc(ifstream& fin1, ifstream& fin2, ofstream& fout)
{
	Page list1;
	if (list1.getData(fin1))
		return 1;
	cout << endl << "Был считан текст 1:" << endl;
	fout << endl << "Был считан текст 1:" << endl;
	list1.outData(fout);

	Page list2;
	if (list2.getData(fin2))
		return 2;
	cout << endl << "Был считан текст 2:" << endl;
	fout << endl << "Был считан текст 2:" << endl;
	list2.outData(fout);

	Stroka outStroka;
	GenerateData(list1, list2, outStroka);
	cout << endl << endl << "Был сформирован текст:" << endl;
	fout << endl << endl << "Был сформирован текст:" << endl;
	outStroka.outData(fout);

	list1.Clear();
	list2.Clear();
	outStroka.Clear();

	return 0;
}

void finalmessage(int err)
{
	cout << endl << endl;
	switch (err) {
	case 0:
		cout << "Программа завершилась без ошибoк" << endl
			<< "Память очищена" << endl
			<< "Все файлы сохранены и закрыты" << endl;
		break;
	case 1:
		cout << "Ошибка: Файл data.txt отсутствует в директории" << endl;
		break;
	case 2:
		cout << "Ошибка: Файл data2.txt отсутствует в директории " << endl;
		break;
	case 3:
		cout << "Ошибка: Файлы одинаковые" << endl;
		break;
	}
}
