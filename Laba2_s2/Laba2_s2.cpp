#include <iostream>
#include <fstream>
#include <windows.h>


using namespace std;

const int N = 5;

struct stroka {
	char str[N];
};

struct txt {
	stroka* array;
	int size;
};

struct apocalypse {
	int word_length[1024];
};

struct characteristics {
	int* starter;
	int* starter1;
	int* word_in_str;
	apocalypse* str_num;
	int* word_length;
	int* kolvo_zap;
	int* kolvo_zap_word;
	int* kolvo_zap_symbol;
};


void word_cutter(txt& text, characteristics& num) {

	int kolvo_word = 0;

	for (int i = 0; i < text.size; i++) {
		for (int j = 0; j < N; j++) {
			if (text.array[i].str[j] == ' ' || text.array[i].str[j] == '\n') {
				kolvo_word++;
				num.word_in_str[i] = num.word_in_str[i] + kolvo_word;
			}
		}
		kolvo_word = 0;
	}
}

void word_size_cutter(txt& text, characteristics& num) {

	for (int i = 0; i < text.size; i++) {


		for (int j = 0; j < num.kolvo_zap[i]; j++) {


		}

		for (int j = 0; j < num.kolvo_zap[i]; j++) {

			if (text.array[i].str[j] == ' ') {



				num.str_num[i].word_length[num.kolvo_zap_word[i]] = num.word_length[i];

				num.kolvo_zap_word[i]++;

				num.word_length[i] = 0;
			}
			else {
				num.word_length[i]++;


			}

			if (num.starter[i] == num.starter1[i]) {
				num.str_num[i].word_length[num.kolvo_zap_word[i]] = num.str_num[i].word_length[num.kolvo_zap_word[i]] + num.word_length[i];
				num.word_length[i] = 0;
			}

		}
	}

}

int block_txt_zap(txt& text, fstream& fin, characteristics& num, int breaker, int kolvo_word) {
	char tmp;
	int kolvo_skip;

	kolvo_skip = 0;

	fin.open("input.txt", ios::in);

	fin >> text.size >> noskipws;
	fin.get(tmp);

	for (int i = 0; i < text.size; i++) {

		if (kolvo_skip < num.starter[i]) {
			for (int skip = 0; skip < num.starter[i]; skip++) {
				fin.get(tmp);
			}
		}

		for (int j = 0; j < N; j++) {
			fin.get(tmp);

			if (fin.eof()) {
				breaker++;
			}

			if (tmp == '\n' || fin.eof()) {

				break;
			}
			else {
				text.array[i].str[j] = tmp;
				cout << text.array[i].str[j];
				kolvo_skip++;

			}
		}
		cout << "\n";

		while (tmp != '\n') {

			fin.get(tmp);

			if (fin.eof()) {
				break;
			}

		}
		num.kolvo_zap[i] = kolvo_skip;

		num.starter[i] = num.starter[i] + kolvo_skip;
		kolvo_skip = 0;
	}
	cout << "\n";
	fin.close();
	return(breaker);
}

void main() {
	setlocale(LC_ALL, "Russian");

	txt text;
	characteristics num;

	fstream fout;
	fstream fin;

	char tmp;
	int* max_str_length;
	int starter;
	int breaker;
	int kolvo_word;
	int length;

	cout << "Автор: Леонович Даниил Михайлович\n";
	cout << "Группа: 0309\n";

	cout << "Задание:\n";
	cout << "1)Выделить в строке отдельные слова, разделённые пробелами, определить длину каждого слова, подсчитать общее количество слов.\n";
	cout << "\n";
	cout << "Способ решения:\n";
	cout << "1)Считать текст блоками по 5 символов на количество строк в тексте\n";
	cout << "2)Выделить в строках отдельные слова\n";
	cout << "3)Найти длину слов\n";

	fin.open("input.txt", ios::in);
	fout.open("output.txt", ios::out);

	fin >> text.size >> noskipws;
	fin.get(tmp);

	cout << "Текст состоит из: " << text.size << " строк.\n";
	cout << "\n";

	fout << "Текст состоит из: " << text.size << " строк.\n";
	fout << "\n";

	fin.close();

	max_str_length = new int[text.size];

	fin.open("input.txt", ios::in);

	fin >> text.size >> noskipws;
	fin.get(tmp);

	starter = 0;
	int i = 0;
	while (i < text.size) {

		while (true) {
			fin.get(tmp);
			if (tmp == '\n' || fin.eof()) {
				break;
			}
			else {
				starter++;
			}
		}

		max_str_length[i] = starter;

		starter = 0;
		i++;
	}
	cout << "\n";
	fin.close();


	fin.open("input.txt", ios::in);

	fin >> text.size >> noskipws;
	fin.get(tmp);

	text.array = new stroka[text.size];

	num.starter = new int[text.size];
	num.starter1 = new int[text.size];
	num.word_in_str = new int[text.size];
	num.kolvo_zap = new int[text.size];

	for (int i = 0; i < text.size; i++) {
		num.starter[i] = 0;
	}

	for (int i = 0; i < text.size; i++) {
		num.word_in_str[i] = 1;
	}

	fin.close();

	breaker = 0;
	kolvo_word = 0;

	while (breaker == 0) {

		breaker = block_txt_zap(text, fin, num, breaker, kolvo_word);
		word_cutter(text, num);

		for (int i = 0; i < text.size; i++) {
			num.starter1[i] = num.starter[i];
		}

	}

	fin.close();

	kolvo_word = 0;

	for (int i = 0; i < text.size; i++) {
		kolvo_word = kolvo_word + num.word_in_str[i];
	}

	num.str_num = new apocalypse[text.size];
	num.word_length = new int[text.size];
	num.kolvo_zap_word = new int[text.size];
	num.kolvo_zap_symbol = new int[text.size];

	for (int i = 0; i < text.size; i++) {
		for (int j = 0; j < num.word_in_str[i]; j++) {
			num.str_num[i].word_length[j] = 0;
		}
	}

	for (int i = 0; i < text.size; i++) {
		num.starter[i] = 0;
		num.word_length[i] = 0;
		num.kolvo_zap_word[i] = 0;
		num.kolvo_zap_symbol = 0;
	}

	breaker = 0;

	while (breaker == 0) {
		breaker = block_txt_zap(text, fin, num, breaker, kolvo_word);
		word_size_cutter(text, num);
	}

	cout << "===========================\n";

	for (int i = 0; i < text.size; i++) {
		for (int j = 0; j < num.word_in_str[i]; j++) {
			if (num.str_num[i].word_length[j] == 0) {
				kolvo_word--;
			}
			else {
				cout << "Длина " << j + 1 << " слова " << i + 1 << " строки: " << num.str_num[i].word_length[j] << "\n";
				fout << "Длина " << j + 1 << " слова " << i + 1 << " строки: " << num.str_num[i].word_length[j] << "\n";
			}
		}
		cout << "\n";
		fout << "\n";
	}

	cout << "В тексте удалось обнаружить " << kolvo_word << " слов.\n";
	cout << "\n";
	fout << "В тексте удалось обнаружить " << kolvo_word << " слов.\n";
	fout << "\n";

	fout.close();
}