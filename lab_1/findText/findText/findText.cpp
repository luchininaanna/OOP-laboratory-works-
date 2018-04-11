
#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <functional> // Необходим для std::function
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

using FindStringCallback = function<void(int lineIndex, const string& line, size_t foundPos)>;

bool FindStingInStream(
	istream& haystack,
	const string& searchingText,
	const FindStringCallback& callback = FindStringCallback())
{
	string line;
	bool found = false;
	for (int lineIndex = 1; getline(haystack, line); ++lineIndex)
	{
		auto pos = line.find(searchingText);
		if (pos != string::npos)
		{
			found = true;
			// Передаем в функцию обратного вызова информацию о
			// первом найденном вхождении подстроки
			if (callback)
			{
				callback(lineIndex, line, pos);
			}
		}
	}
	return found;
}

void PrintFoundLineIndex(int lineIndex, const string& /*line*/, size_t /*foundPos*/)
{
	cout << lineIndex << endl;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream ifs(argv[1]);
	string hayStack;
	int i = 1;

	if (!ifs.is_open())
	{
		cout << "File is  not open" << endl;
	}
	else
	{
		string s;
		while (getline(ifs, s))
		{ // пока не достигнут конец файла класть очередную строку в переменную (s)
			hayStack += s;
			hayStack += '\n';
		}

		//cout << hayStack;

		istringstream strm(hayStack);

		string searchingText = argv[2];

		cout << searchingText << endl;
		cout << "небо" << endl;

		if (!FindStingInStream(strm, searchingText, PrintFoundLineIndex))
		{
			cout << "No string found" << endl;
		}

		strm.clear(); // сбросили флаг окончания потока
		strm.seekg(0, ios_base::beg); // перемотали в начало

		// можно не передавать callback и довольствоваться лишь информацией о наличии/отсутствии вхождений
		//assert(FindStingInStream(strm, searchingText));
	}
}
