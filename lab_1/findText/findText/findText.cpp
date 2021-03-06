#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <functional>
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

void FindWord(char* argv[]) //2 параметра
{
	//определение слова для поиска
	string searchingText = argv[2];

	ifstream strm(argv[1]);

	if (!FindStingInStream(strm, searchingText, PrintFoundLineIndex))
	{
		cout << "No string found" << endl;
	}
}

int main(int argc, char* argv[])
{
	locale::global(std::locale("rus"));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc < 3)
	{
		cout << "Не переданы все необходимые параметры." << endl;
		cout << "Программе необходимо передать слово и файл, в котором будет производиться его поиск." << endl;
	}
	else
	{
		ifstream ifs(argv[1]);

		if (!ifs.is_open())
		{
			cout << "File is  not open" << endl;
		}
		else
		{
			FindWord(argv);
		}
	}
}
