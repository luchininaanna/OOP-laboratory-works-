#include "stdafx.h"
#include "TVSet.h"
#include "string"

using namespace std;


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
		m_previousChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
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
	}
	else
	{
		cout << "The TV is turned on" << endl;
	}
}
