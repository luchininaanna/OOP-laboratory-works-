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
	Dictionary startDictionary;

	if (ifs.is_open())
	{
		string word;
		string translation;
		while (!ifs.eof())
		{
			getline(ifs, word, ' ');
			getline(ifs, translation);
			startDictionary.emplace(Dictionary::value_type(word, translation));
		}
	}
	else
	{
		cout << "Не удалось открыть файл со словарем." << endl;
	}

	return startDictionary;
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

bool isNeedToSaveDictionary()
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

	bool isNewWord = false;

	if (answer != "")
	{
		dictionary.insert(Dictionary::value_type(word, answer));
		cout << "Перевод слова сохранен" << endl;
		isNewWord = true;
	}
	else
	{
		cout << "Перевод слова НЕ сохранен" << endl;
	}

	return isNewWord;
}

void HandleCreateDictionary(const Dictionary& dictionary, char* fileName, bool isNewWord)
{
	if (isNewWord && isNeedToSaveDictionary())
	{
		SaveDictionary(dictionary, fileName);
	}
}

void DialogWithUser(Dictionary& dictionary, bool& isNewWord)
{
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
			isNewWord = AddNewWord(dictionary, word);
		}
	}
}

void GetStarted(char* fileName)
{
	//загрузить словарь
	Dictionary dictionary = GetDictionary(fileName);

	//диалог с пользователем
	bool isNewWord = false;
	DialogWithUser(dictionary, isNewWord);

	//сохранение словаря при согласии пользователя
	HandleCreateDictionary(dictionary, fileName, isNewWord);
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
		GetStarted(argv[1]);
	}

	return 0;
}
