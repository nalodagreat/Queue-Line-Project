#pragma once
#include <iostream>
#include <string>
using namespace std;
class QueueLine
{
	string prefix;
	int TotalTickets=0;
	int servedClients=0;
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
		servedClients++;
		waitClients++;
	}
	void printInfo()
	{
		cout << "Pay Bills Info\n";
		cout << "\t\t\t_________________________________________________________\n";
		cout << "\t\t\t\t\tQUEUE INFO\n";
		cout << "\t\t\t_________________________________________________________\n";
		cout << "\t\t\tprefix : "<<prefix;
		cout << "\t\t\tTotalTickets : "<< TotalTickets<<endl;
		cout << "\t\t\tservedClients : "<< servedClients << endl;
		cout << "\t\t\twaitClients : "<< waitClients << endl;
		cout << "\t\t\t____________________________\n";
	}
};

