#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

map<string, string> GetDictionary(char* fileName)
{

	ifstream ifs(fileName);
	map<string, string> imap;

	if (ifs.is_open())
	{
		string word;
		string translation;
		while (!ifs.eof())
		{
			getline(ifs, word, ' ');
			getline(ifs, translation);
			imap.insert(map<string, string>::value_type(word, translation));
		}
	}

	return imap;
}

void SaveDictionary(const map<string, string>& dictionary, char* fileName)
{
	ofstream fout(fileName);

	if (fout.is_open())
	{
		map<string, string>::const_iterator it;

		for (it = dictionary.begin(); it != dictionary.end(); it++)
		{
			fout << it->first << " " << it->second << endl;
		}
	}
}

void AskToSaveDictionary(const map<string, string>& dictionary, char* fileName)
{
	cout << "Сохранить изменения в словаре? (да/нет)" << endl;

	string answer;

	getline(cin, answer);

	if (answer == "да")
	{
		SaveDictionary(dictionary, fileName);
		cout << "Обновления сохранены" << endl;
	}
}

void AddNewWord(map<string, string>& dictionary, string word, bool* isNewWordPtr)
{
	cout << "Неизвестное слово\"" << word << "\". Введите перевод или пустую строку для отказа." << endl;

	string answer;
	getline(cin, answer);

	if (answer != "")
	{
		dictionary.insert(map<string, string>::value_type(word, answer));
		*isNewWordPtr = true;
		cout << "Перевод слова сохранен" << endl;
	}
	else
	{
		cout << "Перевод слова НЕ сохранен" << endl;
	}
}

void FinishCreateDictionary(const map<string, string>& dictionary, char* fileName, bool isNewWord)
{
	if (isNewWord)
	{
		AskToSaveDictionary(dictionary, fileName);
	}
}

void CreateDictionary(char* fileName)
{

	map<string, string> dictionary = GetDictionary(fileName);

	bool isNewWord = false;
	string word;

	while (getline(cin, word) && word != "...")
	{
		auto search = dictionary.find(word);

		if (search != dictionary.end())
		{
			if (word != "")
			{
				cout << "Найден перевод слова: " << search->second << '\n';
			}
			else
			{
				cout << "Вы ввели пустую строку" << endl;
			}
		}
		else
		{
			AddNewWord(dictionary, word, &isNewWord);
		}
	}

	FinishCreateDictionary(dictionary, fileName, isNewWord);
}

int main(int argc, char* argv[])
{
	locale::global(std::locale("rus"));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CreateDictionary(argv[1]);

	return 0;
}
