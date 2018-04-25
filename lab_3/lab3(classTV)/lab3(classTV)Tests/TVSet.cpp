#include "stdafx.h"
#include "TVSet.h"
#include "string"

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
		m_previousChanel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
	}

	return false;
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		m_selectedChannel = m_previousChanel;
		return true;
	}

	return false;
}

bool CTVSet::SetChannelName(int channel, std::string channelName)
{
	bool isCorrectChanelName = CheckChanelName(channelName);
	bool isAvailableChannel = (channel >= 1) && (channel <= 99);

	if (isCorrectChanelName && isAvailableChannel) {
		//задаем имя для канала
		//?как заменить int на string
	}
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
