//
//  Client.hpp
//  Program5
//
//  Created by Bryan Song  on 6/2/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#include <string>
#include <sstream>
#include<vector>
#include <iostream>
#ifndef Client_hpp
#define Client_hpp

using namespace std;

#include <stdio.h>
class Client
{
public:
    Client();
    Client(string fname, string lname, int num);
    Client(const Client &copy);
    ~Client();
    void setFirstName(string name);
    void setLastName(string name);
    void setAccountNumber(int num);
    string getFirstName();
    string getLastName();
    int getAccountNumber();
    bool addFunds(int index, int amount);
    bool withdrawFunds(int index, int amount);
    friend ostream& operator<<(ostream& out, const Client &person);
    bool operator<(const Client &other) const;
    bool operator>(const Client &other) const;
    vector<string> transactionHistory;
    vector<int> funds;
    
private:
    string firstName;
    string lastName;
    int accountNumber;
    
};
#endif /* Client_hpp */
