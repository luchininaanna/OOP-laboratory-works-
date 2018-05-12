#pragma once

class CTVSet;

class CRemoteControl
{
public:
	CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output);
	bool HandleCommand();

	
    //CRemoteControl& operator=(const CRemoteControl &) = delete;
private:
	bool TurnOn(std::istream & args);
	bool TurnOff(std::istream & args);
	bool SelectChannel(std::istream& args);
	bool SelectPreviousChannel(std::istream& args);
	bool Info(std::istream & args);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	CTVSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};