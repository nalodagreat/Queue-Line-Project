#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Date.h"

using namespace std;

class QueueLine 
{
	class Ticket
	{
		int PrefixContactor = 0;
		string ticketNumber;
		string dateOfTicket;
		string timeOfTicket;
		int waitaingClients;
		int whenMyTurn;
	public:
		Ticket(string ticketNumber,int PrefixContactor,int waitaingClients, int whenMyTurn)
		{
			this->ticketNumber = ticketNumber;
			this->dateOfTicket = Date::convertDateOfLoginstructToString(Date::getSystemDate());
			this->waitaingClients = waitaingClients;
			this->timeOfTicket = Date::getSystemTime();
			this->whenMyTurn = whenMyTurn;
			this->PrefixContactor = PrefixContactor;
		}
		string getTicketNumber()
		{
			return ticketNumber += to_string(PrefixContactor);
		}
		string getDateOfTicket()
		{
			return this->dateOfTicket;
		}
		string getTimeOfTicket()
		{
			return this->timeOfTicket;
		}
		int getWhenMyTurn()
		{
			return  whenMyTurn * waitaingClients;
		}
		void printTicket()
		{
			cout << "\t\t\t-----------------------------------\n";
			
				cout << "\t\t\t" << getTicketNumber() << "\n";
				cout << "\t\t\tDate: " << dateOfTicket << "\n";
				cout << "\t\t\tTime: " << timeOfTicket << "\n";
				cout << "\t\t\tWaiting clients: " << waitaingClients << "\n";
				cout << "\t\t\tServe in time: " << getWhenMyTurn() << "\n";

				cout << "\t\t\t-----------------------------------\n";
		}





	};
	queue <Ticket> tickets;
	string prefix = "";
	int totalTickets=0;
	int servedClients=0;
	int StandardTimeToServe;
	int waitaingClients()
	{
		return tickets.size();
	}
public:
	QueueLine(string prefix,int StandardTimeToServe)
	{
		this->prefix = prefix;
		this->StandardTimeToServe = StandardTimeToServe;
	}
	void issueTicket()
	{
		totalTickets++;
		tickets.push(Ticket(prefix, totalTickets, waitaingClients(),StandardTimeToServe));
	}
	void printInfo() 
	{
		cout << "Pay Bills Info:\n";
		cout << "\t\t\t_________________________________________________________\n";
		cout << "\n\t\t\t\t\tQUEUE INFO\n";
		cout << "\t\t\t_________________________________________________________\n";
		cout << "\t\t\tprefix : " << prefix << endl;
		cout << "\t\t\tTotalTickets : " << totalTickets<< endl;
		cout << "\t\t\tservedClients : " << servedClients << endl;
		cout << "\t\t\t waitaingClients : " << waitaingClients()<< endl;
		cout << "\t\t\t----------------------------\n";
	}
	void printTicketsRTL() {
		queue<Ticket> temp = tickets;
		cout << "\n\t\t\tTickets: ";
		while (!temp.empty()) 
		{
			cout << temp.front().getTicketNumber() << " <-- ";
			temp.pop();
		}
		cout << endl;
	}

	void printTicketsLTR() {
		queue<Ticket> temp = tickets;
		stack<Ticket> s;
		while (!temp.empty()) {
			s.push(temp.front());
			temp.pop();
		}

		cout << "\n\t\t\tTickets: ";
		while (!s.empty()) {
			cout << s.top().getTicketNumber() << " --> ";
			s.pop();
		}
		cout << endl;
	}
	void printAllTickets()
	{
		queue<Ticket> temp = tickets;
		cout << "\n\n\t\t\t\t---Tickets---:\n";
		while (!temp.empty())
		{
			temp.front().printTicket();
			temp.pop();
		}
	}
	void serveNextClient()
	{
		if (!tickets.empty())
		{
			tickets.pop();
			servedClients++;
		}
	}
};
