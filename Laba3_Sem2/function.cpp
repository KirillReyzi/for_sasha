#include "struct.h";

void ñounting_rows(insert& ñountrows)
{
	ofstream f_out("out.txt", ios::out | ios::app);

	ifstream f("input.txt");
	if (!f.is_open())
	{
		cout << "Îøèáêà îòêðûòèÿ ôàéëà " << endl;
		f_out << "Îøèáêà îòêðûòèÿ ôàéëà " << endl;
		exit(-1);
	}
	f.unsetf(ios::skipws);

	char s;
	//ïîäñ÷åò ýëåìåíòîâ
	while (f.eof() != 1)
	{
		f >> s;
		if ((f).eof())
		{
			ñountrows.str++;
			break;
		}
		if (s == '\n')
		{
			ñountrows.str++;
		}
	}

	cout << "\nÊîë-âî ýëåìåíòîâ â òåêñòå:" << ñountrows.str << endl;
	f_out << "\nÊîë-âî ýëåìåíòîâ â òåêñòå:" << ñountrows.str << endl;
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
