#include "QueueLine.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	QueueLine payBills("A0", 10);
	payBills.issueTicket();
	payBills.issueTicket();
	payBills.issueTicket();
	payBills.printInfo();
	payBills.printTicketsRTL();
	payBills.printTicketsLTR();
	payBills.printAllTickets();
	payBills.serveNextClient();
	payBills.printInfo();
}

