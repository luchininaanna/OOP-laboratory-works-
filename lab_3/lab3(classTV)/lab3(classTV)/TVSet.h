#pragma once

class CTVSet
{
public:
	bool IsTurnedOn()const; // ����� Info
	void TurnOn(); //
	void TurnOff(); //
	int GetChannel()const; // ����� Info
	bool SelectChannel(int channel); //
	bool SelectPreviousChannel();
	bool SetChannelName(int chanel, std::string chanelName);

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_previousChanel = 1;

	//������� ��� �������� ����� ������
	bool CheckChanelName(std::string chanelName);
	bool SearchSymbolInSting(std::string chanelName);
};
