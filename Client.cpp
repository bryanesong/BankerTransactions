//
//  Client.cpp
//  Program5
//
//  Created by Bryan Song  on 6/2/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#include "Client.hpp"
#include <string>
#include<array>
#include<vector>
#include<iostream>
using namespace std;

inline Client::Client()
{
    firstName = "NULL";
    lastName = "NULL";
    accountNumber = 0;
    funds.assign(10, 0);//assign the value of 0 to 10 slots in the vector

}
inline Client::Client(const Client &copy)
{
    this->firstName = copy.firstName;
    this->lastName = copy.lastName;
    this->accountNumber = copy.accountNumber;
    this->funds = copy.funds;
}

inline Client::Client(string fname, string lname, int num)
{
    firstName = fname;
    lastName = lname;
    accountNumber = num;
    funds.assign(10, 0);//assign the value of 0 to 10 slots in the vector
}

inline Client::~Client()
{
    firstName = "";
    lastName = "";
    accountNumber = -1;
    for(int i = 0;i<funds.size();i++)
    {
        funds[i] = NULL;
    }
}

inline bool Client::addFunds(int index, int amount)
{
    if(amount < 0 || index < 0 || index > 9)
    {
        return false;
    }
    funds[index] = funds[index]+amount;
    return true;
}

inline bool Client::withdrawFunds(int index, int amount)
{
    if(amount < 0 || index < 0 || index > 9)
    {
        return false;
    }
    if(funds[index] < amount)//if current funds are not enough
    {
        if(index == 0)//if funds are being withdrawn from money market 1
        {
            if(funds[0]+funds[1] < amount)//if combined funds are not enough
            {
                return false;
            }
            else
            {
                amount-=funds[0]; //will first subtract funds from money market 1
                funds[0] = 0;
                funds[1]-=amount; //then subtract money from money market 2
                return true;
            }
        }
        else if (index == 1) //if funds are being withdrawn from money market 2
        {
            if(funds[1]+funds[0] < amount)//if combined funds are not enough
            {
                return false;
            }
            else
            {
                amount-=funds[1]; //will first subtract funds from money market 1
                funds[1] = 0;
                funds[0]-=amount; //then subtract money from money market 2
                return true;
            }
        }
        else if(index == 2) // if funds are being withdrawn from bond 1
        {
            if(funds[2]+funds[3] < amount)//if combined funds are not enough
            {
                return false;
            }
            else
            {
                amount-=funds[2]; //will first subtract funds from bond 1
                funds[2] = 0;
                funds[3]-=amount; //then subtract money from bond 2
                return true;
            }
        }
        else if(index == 3)// if funds are being withdrawn from bond 2
        {
            if(funds[3]+funds[2] < amount)//if combined funds are not enough
            {
                cout << "ERROR: Not enough funds to withdraw "<< amount << " from "<< this->firstName << " "<< this->lastName;
                return false;//Johnny Cash Growth Index Fund"
            }
            else
            {
                amount-=funds[3]; //will first subtract funds from bond 2
                funds[3] = 0;
                funds[2]-=amount; //then subtract money from bond 1
                return true;
            }
        }
        else//no possible funds to get enough
        {
            return false;
        }
    }
    else
    {
        funds[index]-= amount;
        return true;
    }
}

inline void Client::setFirstName(string name)
{
    firstName = name;
}

inline void Client::setLastName(string name)
{
    lastName = name;
}

inline void Client::setAccountNumber(int num)
{
    accountNumber = num;
}

inline string Client::getFirstName()
{
    return firstName;
}

inline string Client::getLastName()
{
    return lastName;
}

inline int Client::getAccountNumber()
{
    return accountNumber;
}
inline bool Client::operator<(const Client &other) const
{
    if(accountNumber < other.accountNumber)
    {
        return true;
    }
    return false;
}

inline bool Client::operator>(const Client &other) const
{
    if(accountNumber > other.accountNumber)
    {
        return true;
    }
    return false;
}
