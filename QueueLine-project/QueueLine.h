#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Date.h"

using namespace std;

class QueueLine {
    struct Ticket {
        string prefix;
        string date;
        string time;
        int waitClients;
        int serveTime;
    };

    queue<Ticket> tickets;
    string prefix;
    int TotalTickets = 0;
    int servedClients = 0;
    short prefixCounter = 1;
    int standardServeTime;

    string _generatePrefix(string prefix) {
        prefix += to_string(prefixCounter++);
        return prefix;
    }

public:
    QueueLine(string prefix, int serveTime) {
        this->prefix = prefix;
        this->standardServeTime = serveTime;
    }

    void issueTicket() {
        Ticket tckt;
        tckt.prefix = _generatePrefix(prefix);
        tckt.date = Date::convertDateOfLoginstructToString(Date::getSystemDate());
        tckt.time = Date::getSystemTime();

        if (TotalTickets == 0) {
            tckt.serveTime = 0;
            tckt.waitClients = 0;
        }
        else {
            tckt.serveTime = tickets.back().serveTime + standardServeTime;
            tckt.waitClients = tickets.back().waitClients + 1;
        }

        tickets.push(tckt);
        TotalTickets++;
    }

    void printInfo() {
        cout << "Pay Bills Info:\n";
        cout << "\t\t\t_________________________________________________________\n";
        cout << "\n\t\t\t\t\tQUEUE INFO\n";
        cout << "\t\t\t_________________________________________________________\n";
        cout << "\t\t\tprefix : " << prefix << endl;
        cout << "\t\t\tTotalTickets : " << TotalTickets << endl;
        cout << "\t\t\tservedClients : " << servedClients << endl;
        cout << "\t\t\t----------------------------\n";
    }

    void printTicketsRTL() {
        queue<Ticket> temp = tickets;
        cout << "\n\t\t\tTickets: ";
        while (!temp.empty()) {
            cout << temp.front().prefix << " <-- ";
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
            cout << s.top().prefix << " --> ";
            s.pop();
        }
        cout << endl;
    }

    void printAllTickets() {
        queue<Ticket> temp = tickets;
        cout << "\n\t\t\t\t---Tickets---:\n";
        cout << "\t\t\t-----------------------------------\n";

        while (!temp.empty()) {
            Ticket tckt = temp.front();
            cout << "\t\t\t" << tckt.prefix << "\n";
            cout << "\t\t\tDate: " << tckt.date << "\n";
            cout << "\t\t\tTime: " << tckt.time << "\n";
            cout << "\t\t\tWaiting clients: " << tckt.waitClients << "\n";
            cout << "\t\t\tServe in time: " << tckt.serveTime << "\n";
            cout << "\t\t\t-----------------------------------\n";
            temp.pop();
        }
    }
};
