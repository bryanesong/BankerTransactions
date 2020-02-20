//
//  Bank.cpp
//  Program5
//
//  Created by Bryan Song  on 6/2/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#include "Bank.hpp"
inline void Bank::treePrint()
{
    customers.Display();
}
inline bool Bank::openAccount(string firstName, string lastName, int number )
{
    if(customers.Insert(new Client(firstName,lastName,number)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
inline bool Bank::withdrawFunds(int number, int index, int amount)
{
    Client *current;
    customers.Retrieve(number,current);
    if(current->withdrawFunds(index, amount))
    {
        return true;
    }
    return false;
}
inline bool Bank::depositFunds(int number,int index, int amount)
{
    Client *current;
    customers.Retrieve(number,current);
    //cout << "have retireved: " << *(current) << endl;
    
    if(current->addFunds(index,amount))
    {
        return true;
    }
    return false;
}
inline bool Bank::transferFunds(int number, int index, int amount, int transferNumber, int transferIndex)
{
    Client *current;
    customers.Retrieve(number,current);
    
    Client *transfer = new Client();
    customers.Retrieve(transferNumber,transfer);
    
    if(current->withdrawFunds(index, amount))
    {
        transfer->addFunds(transferIndex, amount);
        return true;
    }
    return false;
}
inline void Bank::printTransactionHistory(int number)
{
    Client *current;
    customers.Retrieve(number,current);
    cout << endl << current->getFirstName() << " " <<current->getLastName() << "'s Transaction History: "<< endl;
    if(current->transactionHistory.size()== 0 )
    {
        cout << "No history yet." << endl;
    }
    else
    {
        for (const auto& str: current->transactionHistory)
            cout << str << endl;
    }
    
}

inline void Bank::printTransactionHistory(int number, int index)
{
    Client *current;
    customers.Retrieve(number,current);
    cout << endl << current->getFirstName() << " " <<current->getLastName() << "'s Transaction History for Fund " <<index << ": "<< endl;
    if(current->transactionHistory.size()== 0 )
    {
        cout << "No history yet." << endl;
    }
    else
    {
        for (const auto& str: current->transactionHistory)
            if(str.substr(0,0) == "H" && str.length() == 7)
            {
                cout << str << endl;
            }
        else
        {
            cout << str <<" is not long enough" << endl;
        }
    }
}

inline void Bank::addTransactionHistory(int number, string history)
{
    Client *current = new Client();
    customers.Retrieve(number, current);
    current->transactionHistory.push_back(history);
}

inline void Bank::printClientFunds(int number)
{
    Client *current = new Client();
    customers.Retrieve(number, current);
    cout << "Money Market: " << current->funds[0] << endl;
    cout << "Prime Money Market: " << current->funds[1] << endl;
    cout << "Long-Term Bond: " << current->funds[2] << endl;
    cout << "Short-Term Bond: " << current->funds[3] << endl;
    cout << "500 Index Fund: " << current->funds[4] << endl;
    cout << "Capital Value Fund: " << current->funds[5] << endl;
    cout << "Growth Equity Fund: " << current->funds[6] << endl;
    cout << "Growth Index Fund: " << current->funds[7] << endl;
    cout << "Value Stock Index: " << current->funds[8] << endl;
    cout << "Value Fund: " << current->funds[9] << endl;
}

inline string Bank::getAccountName(int number)
{
    Client *current = new Client();
    customers.Retrieve(number, current);
    return current->getFirstName()+" "+current->getLastName();
}
