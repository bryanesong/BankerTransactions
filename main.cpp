//
//  main.cpp
//  Program5
//
//  Created by Bryan Song  on 6/2/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include "Bank.cpp"
#include "Bank.hpp"
#include <queue>
#include "Transaction.hpp"
#include "Transaction.cpp"
#include <string.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile) {
        cerr << "Unable to open file "<< endl;
        exit(1);   // call system to stop
    }
    string line;
    queue<Transaction> commands;
    while (inFile >> line) {
        Transaction current;
        string currentLine = "";
        if(line == "O")
        {
            current.setType("O");
            currentLine +="O ";
            
            inFile >> line;
            current.setLastName(line);
            currentLine+=line+" ";
            
            inFile >> line;
            current.setFirstName(line);
            currentLine+=line+" ";
            
            inFile >> line;
            int number;
            istringstream iss (line);
            iss >> number;
            current.setAccountNumber(number);
            currentLine+=line;
            current.setTransactionLine(currentLine);
            
            commands.push(current);
        }
        else if(line == "D")
        {
            current.setType("D");
            currentLine +="D ";
            
            inFile >> line;
            int number;
            istringstream iss (line.substr(0,4));
            iss >> number;
            current.setAccountNumber(number);
            istringstream iss2 (line.substr(4,4));
            iss2 >> number;
            current.setAccountIndex(number);
            currentLine +=line+" ";
            
            inFile >> line;
            istringstream iss3 (line);
            iss3 >> number;
            current.setAmount(number);
            currentLine +=line;
            current.setTransactionLine(currentLine);
            
            commands.push(current);
        }
        else if(line == "W")
        {
            current.setType("W");
            currentLine +="W ";
            
            inFile >> line;
            int number;
            istringstream iss (line.substr(0,4));
            iss >> number;
            current.setAccountNumber(number);
            istringstream iss2 (line.substr(4,4));
            iss2 >> number;
            current.setAccountIndex(number);
            currentLine +=line+" ";
            
            inFile >> line;
            istringstream iss3 (line);
            iss3 >> number;
            current.setAmount(number);
            currentLine +=line;
            current.setTransactionLine(currentLine);
            
            commands.push(current);
        }
        else if(line == "T")
        {
            current.setType("T");
            currentLine +="T ";
            
            inFile >> line;
            int number;
            istringstream iss (line.substr(0,4));
            iss >> number;
            current.setAccountNumber(number);
            istringstream iss2 (line.substr(4,4));
            iss2 >> number;
            current.setAccountIndex(number);
            currentLine +=line+" ";
            
            inFile >> line;
            istringstream iss3 (line);
            iss3 >> number;
            current.setAmount(number);
            currentLine +=line+" ";
            
            inFile >> line;
            istringstream iss4 (line.substr(0,4));
            iss4 >> number;
            current.setTransferNumber(number);
            istringstream iss5 (line.substr(4,4));
            iss5 >> number;
            current.setTransferIndex(number);
            currentLine +=line;
            current.setTransactionLine(currentLine);
            
            commands.push(current);
        }
        else if(line == "H")
        {
            
            current.setType("H");
            currentLine+="H ";
            
            inFile >> line;
            int number;
            istringstream iss (line.substr(0,4));
            iss >> number;
            current.setAccountNumber(number);
            currentLine+=line;
            current.setTransactionLine(currentLine);
            
            commands.push(current);
        }
        else
        {
            cout << line << " is a invalid transaction type." << endl;
        }
    }
    inFile.close();
    //now all the transactions have been read into the queue
    
    Bank jollyBank;
    while(!commands.empty())
    {
        //cout<<"current transaction: "<< commands.front().getTransactionLine()<<endl;
        if(commands.front().getType()=="O")
        {
            jollyBank.openAccount(commands.front().getFirstName(), commands.front().getLastName(),commands.front().getAccountNumber());
            
            //   cout << "Unable to Open Account for "<< commands.front().getFirstName() << " " << commands.front().getLastName()<< endl;
            
        }
        else if(commands.front().getType()=="D")
        {
            if(!jollyBank.depositFunds(commands.front().getAccountNumber(), commands.front().getAccountIndex(), commands.front().getAmount()))
            {
                cout << "Unable to deposit amount" << endl;
            }
        }
        else if(commands.front().getType()=="W")
        {
            if(!jollyBank.withdrawFunds(commands.front().getAccountNumber(), commands.front().getAccountIndex(), commands.front().getAmount()))
            {
                cout << "ERROR: Not enough funds to withdraw $" << commands.front().getAmount() << " from " << jollyBank.getAccountName(commands.front().getAccountNumber())<< "'s account" << endl;
            }
        }
        else if(commands.front().getType()=="T")
        {
            if(!jollyBank.transferFunds(commands.front().getAccountNumber(), commands.front().getAccountIndex(), commands.front().getAmount(), commands.front().getTransferNumber(), commands.front().getTransferIndex()))
            {
                cout << "Transfer was not successful" << endl;
            }
            
        }
        else if(commands.front().getType()=="H")
        {
            jollyBank.printTransactionHistory(commands.front().getAccountNumber());
        }
        else
        {
            cout << "Invalid transaction" << endl;
        }
        jollyBank.addTransactionHistory(commands.front().getAccountNumber(), commands.front().getTransactionLine());
        commands.pop();
    }
    cout <<endl<< "Processing Done. Final Balances: "<< endl;
    jollyBank.treePrint();
    
}
