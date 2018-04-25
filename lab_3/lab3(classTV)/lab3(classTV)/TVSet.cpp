#include "stdafx.h"
#include "TVSet.h"

bool CTVSet::IsTurnedOn()const
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

int CTVSet::GetChannel()const
{
	return m_isOn ? m_selectedChannel : 0;
}

bool CTVSet::SelectChannel(int channel)
{
	bool isAvailableChannel = (channel >= 1) && (channel <= 99);
	if (isAvailableChannel && m_isOn)
	{
		m_selectedChannel = channel;
		return true;
	}
	return false;
}

bool CTVSet::SetChannelName(int chanel, std::string channelName)
{
	bool isCorrectChanelName = CheckChanelName(channelName);

	if (isCorrectChanelName) {
		//задаем имя для канала
		return true;
	}

	return false;
}

bool CTVSet::SearchSymbolInSting(std::string channelName) {

	int channelNameLength = channelName.length();

	for (int i = 0; i < channelNameLength; i++) {
		if (channelName[i] != ' ') {
			return true;
		}
	}

	return false;
}

bool CTVSet::CheckChanelName(std::string channelName) {

	bool isEmptyString = (channelName != "");

	bool isChannelNameConsistOfSymbol = SearchSymbolInSting(channelName);

	if (isEmptyString && isChannelNameConsistOfSymbol) {
		return true;
	}

	return false;
}
