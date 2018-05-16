#pragma once
#include "stdafx.h"
#include "vector"

class CTVSet
{

public:
	bool IsTurnedOn()const; // часть Info
	void TurnOn();
	void TurnOff();
	int GetChannel()const; // часть Info
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
	void Info()const;

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_previousChannel = 1;


	std::map <std::string, int> m_channels;
};
