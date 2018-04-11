#include "stdafx.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <locale>

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

	ifs.close();

	return imap;
}

int saveDictionary(map<string, string> dictionary, char* fileName)
{
	ofstream fout(fileName);

	if (fout.is_open())
	{
		map<string, string>::const_iterator it;

		for (it = dictionary.begin(); it != dictionary.end(); it++) {
			fout << it->first << " " << it->second << endl;
		}
	}

	fout.close();
	return 0;
}

int AskToSaveDictionary(map<string, string> dictionary, char* fileName)
{

	cout << "Сохранить изменения в словаре?" << endl;

	string answer;

	getline(cin, answer);

	if (answer == "да")
	{
		saveDictionary(dictionary, fileName);
		cout << "Обновления сохранены" << endl;
	}

	return 0;
}

map<string, string> AddNewWord(map<string, string> dictionary, string word, bool* isNewWord_ptr)
{
	cout << "Неизвестное слово\"" << word << "\". Введите перевод или пустую строку для отказа." << endl;

	string answer;
	getline(cin, answer);

	if (answer != "")
	{
		dictionary.insert(map<string, string>::value_type(word, answer));
		*isNewWord_ptr = true;
		cout << "Перевод слова сохранен" << endl;
	}
	else
	{
		cout << "Перевод слова НЕ сохранен" << endl;
	}

	return dictionary;
}

int main(int argc, char* argv[])
{
	locale::global(std::locale("rus"));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, string> dictionary = GetDictionary(argv[1]);

	bool isNewWord = false;
	bool* isNewWord_ptr = &isNewWord;

	string word;
	while (getline(cin, word) && word != "...")
	{
		auto search = dictionary.find(word);

		if (search != dictionary.end())
		{ //cлово найдено
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
		{ //слово нужно добавить в словарь
			dictionary = AddNewWord(dictionary, word, isNewWord_ptr);
		}
	}

	if (isNewWord)
	{
		AskToSaveDictionary(dictionary, argv[1]);
	}

	return 0;
}
