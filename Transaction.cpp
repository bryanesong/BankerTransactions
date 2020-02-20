//
//  Transaction.cpp
//  Program5
//
//  Created by Bryan Song  on 6/9/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#include "Transaction.hpp"
inline void Transaction::setType(string type)
{
    this->type = type;;
}
inline void Transaction::setFirstName(string name)
{
    firstName = name;
}
inline void Transaction::setLastName(string name)
{
    lastName = name;
}
inline void Transaction::setAccountNumber(int number)
{
    accountNumber = number;
}
inline void Transaction::setAccountIndex(int index)
{
    accountIndex = index;
}
inline void Transaction::setAmount(int amount)
{
    this->amount = amount;
}
inline void Transaction::setTransferNumber(int number)
{
    transferNumber = number;
}
inline void Transaction::setTransferIndex(int index)
{
    transferIndex = index;
}
inline void Transaction::setTransactionLine(string line)
{
    transactionLine = line;
}

inline string Transaction::getType()
{
    return type;
}
inline string Transaction::getFirstName()
{
    return firstName;
}
inline string Transaction::getLastName()
{
    return lastName;
}
inline int Transaction::getAccountNumber()
{
    return accountNumber;
}
inline int Transaction::getAccountIndex()
{
    return accountIndex;
}
inline int Transaction::getAmount()
{
    return amount;
}
inline int Transaction::getTransferNumber()
{
    return transferNumber;
}
inline int Transaction::getTransferIndex()
{
    return transferIndex;
}
inline string Transaction::getTransactionLine()
{
    return transactionLine;
}
