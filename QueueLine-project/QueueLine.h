#pragma once
#include <iostream>
#include <string>
using namespace std;
class QueueLine
{
	string prefix;
	int TotalTickets=0;
	int sevedClients=0;
	int waitClients=0;
	int serveTime;
	short prefixContactor=0;
	string _generatePrefix(string prefix)
	{
		prefix += to_string(prefixContactor);
		prefixContactor++;
		return prefix;
	}
public:
	QueueLine(string prefix, int serveTime)
	{
		this->prefix = prefix;
		this->serveTime = serveTime;
	}
	void issueTicket()
	{
		_generatePrefix(prefix);
		TotalTickets++;
		sevedClients++;
		waitClients++;
	}
};

