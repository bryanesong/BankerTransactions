//
//  Transaction.hpp
//  Program5
//
//  Created by Bryan Song  on 6/9/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#ifndef Transaction_hpp
#define Transaction_hpp

#include <string>
#include <stdio.h>

using namespace std;

class Transaction
{
public:
    void setType(string type);
    void setFirstName(string name);
    void setLastName(string name);
    void setAccountNumber(int number);
    void setAccountIndex(int index);
    void setAmount(int amount);
    void setTransferNumber(int number);
    void setTransferIndex(int index);
    void setTransactionLine(string line);
    
    string getType();
    string getFirstName();
    string getLastName();
    int getAccountNumber();
    int getAccountIndex();
    int getAmount();
    int getTransferNumber();
    int getTransferIndex();
    string getTransactionLine();
    
private:
    string type;
    string firstName;
    string lastName;
    int accountNumber;
    int accountIndex;
    int amount;
    int transferNumber;
    int transferIndex;
    
    string transactionLine;
};
#endif /* Transaction_hpp */
