#include "struct.h";

void �ounting_rows(insert& �ountrows)
{
	ofstream f_out("out.txt", ios::out | ios::app);

	ifstream f("input.txt");
	if (!f.is_open())
	{
		cout << "������ �������� ����� " << endl;
		f_out << "������ �������� ����� " << endl;
		exit(-1);
	}
	f.unsetf(ios::skipws);

	char s;
	//������� ���������
	while (f.eof() != 1)
	{
		f >> s;
		if ((f).eof())
		{
			�ountrows.str++;
			break;
		}
		if (s == '\n')
		{
			�ountrows.str++;
		}
	}

	cout << "\n���-�� ��������� � ������:" << �ountrows.str << endl;
	f_out << "\n���-�� ��������� � ������:" << �ountrows.str << endl;
}

void print(Elem** firstElem, Elem* slider)
{
	ofstream f_out("out.txt", ios::out | ios::app);
	int i;

	slider = *firstElem;
	while (slider != NULL)
	{
		for (i = 0; i < slider->intdata; i++)
		{
			cout << slider->data[i];
			f_out << slider->data[i];
		}
		if (slider->next != NULL)
		{
			cout << " -> ";
			f_out << " -> ";
		}
		(slider) = slider->next;
	}

	cout << endl;
	f_out << endl;
}
