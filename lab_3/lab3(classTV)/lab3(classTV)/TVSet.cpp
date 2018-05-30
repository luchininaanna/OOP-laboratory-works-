#include "stdafx.h"
#include "TVSet.h"
#include "string"

using namespace std;

//добавить пользовательский интерфейс для работы с каналами по их именам

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

int CTVSet::GetChannelByName(string name) const
{
	if (m_isOn) {
		auto search = m_channels.find(name);

		if (search != m_channels.end())
		{
			return search->second;
		}
	}

	return 0;
}

string CTVSet::GetChannelName(int channel) const
{
	string channelName = "";

	if (m_isOn)
	{
		for (auto& item : m_channels)
		{
			if (item.second == channel)
			{
				channelName = item.first;
			}
		}
	}

	return channelName;
}

bool CTVSet::SelectChannel(int channel)
{
	bool isAvailableChannel = (channel >= 1) && (channel <= 99);

	if (isAvailableChannel && m_isOn)
	{
		m_previousChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
	}

	return false;
}

bool CTVSet::SelectChannel(string channelName)
{
	auto search = m_channels.find(channelName);

	if (search != m_channels.end())
	{
		int channel = search->second;

		if (m_isOn)
		{
			m_previousChannel = m_selectedChannel;
			m_selectedChannel = channel;
			return true;
		}
	}

	return false;
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		swap(m_previousChannel, m_selectedChannel);
		return true;
	}

	return false;
}

void CTVSet::Info()const
{
	if (IsTurnedOn())
	{
		cout << "The TV is turned off" << endl;
		cout << "Current channel is " << GetChannel() << endl;

		for (auto channelsEntry : m_channels)
		{
			cout << channelsEntry.first << " " << channelsEntry.second << endl;
		}
	}
	else
	{
		cout << "The TV is turned on" << endl;
	}
}

bool CTVSet::SetChannelName(int channelNumber, string channelName)
{
	bool isAvailableChannel = (channelNumber >= 1) && (channelNumber <= 99);

	if (isAvailableChannel && m_isCorrectChannelName(channelName))
	{
		string channelNameWithoutExtraSpaces;

		channelNameWithoutExtraSpaces = m_GetChannelNameWithoutExtraSpaces(channelName);

		string currentChannelName = this->GetChannelName(channelNumber);

		if (currentChannelName != "")
		{
			m_channels.erase(currentChannelName);
		}

		m_channels.emplace(channelNameWithoutExtraSpaces, channelNumber);

		return true;
	}

	return false;
} 

void CTVSet::DeleteChannelName(string channelName)
{
	if (m_isOn)
	{
		m_channels.erase(channelName);
	}
}
