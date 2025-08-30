#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Date.h"
using namespace std;
class QueueLine
{
	struct stTicketsInfo
	{
		queue <string> prefixTickets;
		int serveTime;
		Date date;
		Date time;
		int waitClients = 0;

	};
	stTicketsInfo t;
	string prefix;
	int TotalTickets=0;
	int servedClients=0;
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
		this->t.serveTime = serveTime;
	}
	void issueTicket()
	{
		
		t.prefixTickets.push(_generatePrefix(prefix));
		TotalTickets++;
		t.waitClients++;
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
		cout << "\t\t\twaitClients : "<< t.waitClients << endl;
		cout << "\t\t\t____________________________\n";
	}
	void printTicketsRTL()
	{
		queue<string> temp = t.prefixTickets;
		cout << "\n\t\t\tTickets: ";
		while (!temp.empty()) {
			cout << temp.front() << " <-- ";
			temp.pop();
		}

	}
	void printTicketsLTR()
	{
		queue<string> temp = t.prefixTickets;
		stack<string> s;

		while (!temp.empty()) 
		{
			s.push(temp.front());
			temp.pop();
		}
		cout << "\n\t\t\tTickets: ";
		while (!s.empty()) {
			cout << s.top() << " --> ";
			s.pop();
		}
	}
	void printAllTickets()
	{
		cout << "\t\t\tTickets:\n";

	}
};

