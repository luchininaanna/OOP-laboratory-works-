#pragma once
#include "stdafx.h"
#include "vector"

using namespace std;


class CTVSet
{

public:
	//struct Channel;

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


	//map <string, int> m_channels;
};