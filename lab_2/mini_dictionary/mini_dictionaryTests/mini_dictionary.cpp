#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

typedef map<string, string> Dictionary;

Dictionary GetDictionary(char* fileName)
{
	ifstream ifs(fileName);
	Dictionary dictionary;

	//при ошибке чтения...
	if (ifs.is_open())
	{
		string word;
		string translation;
		while (getline(ifs, word, ' '))
		{
			getline(ifs, translation);
			dictionary.emplace(word, translation);
		}
	}
	else
	{
		cout << "Не удалось открыть файл со словарем." << endl;
	}

	return dictionary;
}

void SaveDictionary(const Dictionary& dictionary, char* fileName)
{
	ofstream fout(fileName);

	if (fout.is_open())
	{
		for (auto dictionaryEntry : dictionary)
		{
			fout << dictionaryEntry.first << " " << dictionaryEntry.second << endl;
		}
	}
}

bool IsNeedToSaveDictionary()
{
	cout << "Сохранить изменения в словаре? (да/нет)" << endl;

	string answer;
	bool isNeedToSave = false;

	getline(cin, answer);

	if (answer == "да")
	{
		isNeedToSave = true;
		cout << "Обновления сохранены" << endl;
	}

	return isNeedToSave;
}

bool AddNewWord(Dictionary& dictionary, const string& word)
{
	cout << "Неизвестное слово\"" << word << "\". Введите перевод или пустую строку для отказа." << endl;

	string answer;
	getline(cin, answer);

	bool isDictionaryAmended = false;

	if (answer != "")
	{
		dictionary.insert(Dictionary::value_type(word, answer));
		cout << "Перевод слова сохранен" << endl;
		isDictionaryAmended = true;
	}
	else
	{
		cout << "Перевод слова НЕ сохранен" << endl;
	}

	return isDictionaryAmended;
}

void SaveDictionaryOnUserApproval(const Dictionary& dictionary, char* fileName, bool isDictionaryAmended)
{
	if (isDictionaryAmended && IsNeedToSaveDictionary())
	{
		SaveDictionary(dictionary, fileName);
	}
}

bool ExecutionOfUserRequests(Dictionary& dictionary)
{
	string word;
	bool isDictionaryAmended;

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
			isDictionaryAmended = AddNewWord(dictionary, word);
		}
	}

	return isDictionaryAmended;
}

int main(int argc, char* argv[])
{
	locale::global(std::locale("rus"));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc < 2)
	{
		cout << "Данная программа должна получить на вход исходный словарь (который может быть пустым)." << endl;
		cout << "Необходимо передать программе файл с расширением .txt, который будет выполнять роль словаря." << endl;
	}
	else
	{
		//загрузить словарь
		Dictionary dictionary = GetDictionary(argv[1]);

		//диалог с пользователем
		bool isDictionaryAmended = ExecutionOfUserRequests(dictionary);

		//сохранение словаря при согласии пользователя
		if (isDictionaryAmended)
		{
			SaveDictionaryOnUserApproval(dictionary, argv[1], isDictionaryAmended);
		}
	}

	return 0;
}
