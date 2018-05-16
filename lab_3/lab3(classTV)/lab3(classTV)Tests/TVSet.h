#pragma once
#include <string>
#include <map>

class CTVSet
{
public:
	bool IsTurnedOn()const; // часть Info
	void TurnOn(); 
	void TurnOff();
	int GetChannel()const; // часть Info
	int GetChannelByName(std::string name) const;
    std::string GetChannelName(int channel) const;
	bool SelectChannel(int channel);
	bool SelectChannel(std::string channelName);
	bool SelectPreviousChannel();
	void Info()const;
	void DeleteChannelName(std::string channelName);

	bool SetChannelName(int channelNumber, std::string channelName);

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_previousChannel = 1;
	
	std::map <std::string, int> m_channels;

	bool m_isCorrectChannelName(std::string name)
	{
		bool isCorrectName = true;

		int nameLength = name.length();
		int amountSpaces = 0;

		for (int i = 0; i < nameLength; i++)
		{
			if (name[i] == ' ')
			{
				amountSpaces++;
			}
		}

		if ((nameLength == amountSpaces) || (nameLength == 0))
		{
			isCorrectName = false;
		}

		return isCorrectName;
	};

	std::string m_GetChannelNameWithoutExtraSpaces(const std::string & name)
	{
		std::string channelNameWithoutExtraSpaces = "";
		int nameLength = name.length();

		//определение номера последнего значимого символа в имени
		int lastSymbolNumber = nameLength - 1;
		while (name[lastSymbolNumber] == ' ')
		{
			lastSymbolNumber--;
		}

		//пропуск пробелов в начале имени
		int i = 0;
		while (name[i] == ' ')
		{
			i++;
		}

		//обработка лишних пробелов между символами
		bool isPreviousElementIsSpace = false;
		while (i <= lastSymbolNumber)
		{

			if (name[i] != ' ')
			{
				channelNameWithoutExtraSpaces += name[i];
				if (isPreviousElementIsSpace)
				{
					isPreviousElementIsSpace = false;
				}
			}
			else
			{
				if (!isPreviousElementIsSpace)
				{
					channelNameWithoutExtraSpaces += name[i];
					isPreviousElementIsSpace = true;
				}
			}

			i++;
		}

		return channelNameWithoutExtraSpaces;
	}
};