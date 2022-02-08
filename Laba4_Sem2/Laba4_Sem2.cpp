#include <iostream>
#include <fstream>
using namespace std;

int MainFunc(ifstream& fin1, ifstream& fin2, ofstream& fout);
void finalmessage(int err);

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream fin1("data.txt");
	ifstream fin2("data2.txt");
	ofstream fout("output.txt");

	int res = MainFunc(fin1, fin2, fout);

	fin1.close();
	fin2.close();
	fout.close();
	finalmessage(res);

	return 0;
}
