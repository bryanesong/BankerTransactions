//
//  Bank.hpp
//  Program5
//
//  Created by Bryan Song  on 6/2/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp

#include "BSTree.cpp"
#include "BSTree.hpp"
#include <stdio.h>
#include<string>

using namespace std;

class Bank
{
public:
    bool openAccount(string firstName, string lastName, int number );
    bool withdrawFunds(int number, int index, int amount);
    bool depositFunds(int number,int index, int amount);
    bool transferFunds(int number, int index, int amount, int transferNumber, int transferIndex);
    void printTransactionHistory(int number);
    void printTransactionHistory(int number, int index);
    void addTransactionHistory(int number, string history);
    void treePrint();
    void printClientFunds(int number);
    string getAccountName(int number);

private:
    BSTree customers;
};
#endif /* Bank_hpp */
