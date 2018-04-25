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

	//��� ������ ������...
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
		cout << "�� ������� ������� ���� �� ��������." << endl;
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
	cout << "��������� ��������� � �������? (��/���)" << endl;

	string answer;
	bool isNeedToSave = false;

	getline(cin, answer);

	if (answer == "��")
	{
		isNeedToSave = true;
		cout << "���������� ���������" << endl;
	}

	return isNeedToSave;
}

bool AddNewWord(Dictionary& dictionary, const string& word)
{
	cout << "����������� �����\"" << word << "\". ������� ������� ��� ������ ������ ��� ������." << endl;

	string answer;
	getline(cin, answer);

	bool isDictionaryAmended = false;

	if (answer != "")
	{
		dictionary.insert(Dictionary::value_type(word, answer));
		cout << "������� ����� ��������" << endl;
		isDictionaryAmended = true;
	}
	else
	{
		cout << "������� ����� �� ��������" << endl;
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
				cout << "������ ������� �����: " << search->second << '\n';
			}
			else
			{
				cout << "�� ����� ������ ������" << endl;
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
		cout << "������ ��������� ������ �������� �� ���� �������� ������� (������� ����� ���� ������)." << endl;
		cout << "���������� �������� ��������� ���� � ����������� .txt, ������� ����� ��������� ���� �������." << endl;
	}
	else
	{
		//��������� �������
		Dictionary dictionary = GetDictionary(argv[1]);

		//������ � �������������
		bool isDictionaryAmended = ExecutionOfUserRequests(dictionary);

		//���������� ������� ��� �������� ������������
		if (isDictionaryAmended)
		{
			SaveDictionaryOnUserApproval(dictionary, argv[1], isDictionaryAmended);
		}
	}

	return 0;
}
