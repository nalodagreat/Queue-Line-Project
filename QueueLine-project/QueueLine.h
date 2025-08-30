#pragma once
#include <iostream>
#include <string>
#include <queue>
using namespace std;
class QueueLine
{
	queue <string> prefixTickets;
	string prefix;
	int TotalTickets=0;
	int servedClients=0;
	int waitClients=0;
	int serveTime;
	short prefixContactor=1;
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
		prefixTickets.push(_generatePrefix(prefix));
		TotalTickets++;
		waitClients++;
	}
	void printInfo()
	{
		cout << "Pay Bills Info:\n";
		cout << "\t\t\t_________________________________________________________\n";
		cout << "\n\t\t\t\t\tQUEUE INFO\n";
		cout << "\t\t\t_________________________________________________________\n";
		cout << "\t\t\tprefix : "<<prefix << endl;
		cout << "\t\t\tTotalTickets : "<< TotalTickets<<endl;
		cout << "\t\t\tservedClients : "<< servedClients << endl;
		cout << "\t\t\twaitClients : "<< waitClients << endl;
		cout << "\t\t\t____________________________\n";
	}
	void printTicketsRTL()
	{
		queue<string> temp = prefixTickets;
		cout << "\n\t\t\tTickets: ";
		while (!temp.empty()) {
			cout << temp.front() << " <-- ";
			temp.pop();
		}

	}
	void printTicketsLTR()
	{
		queue<string> temp = prefixTickets;
		cout << "\n\t\t\tTickets: ";
		while (!temp.empty()) {
			cout << temp.back() << " --> ";
			temp.pop();
		}

	}
};

