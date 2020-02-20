//
//  BSTree.cpp
//  Program5
//
//  Created by Bryan Song  on 6/2/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#include "BSTree.hpp"
#include <stdio.h>
#include <stack>

inline BSTree::BSTree()
{
    root = NULL;
}

inline BSTree::~BSTree()
{
    root = NULL;
}

inline bool BSTree::Insert(Node *curr, Client *data)
{
    if (data->getAccountNumber() > curr->data->getAccountNumber())
    {
        if (curr->right == NULL)
        {
            Node *insInTree = new Node();
            insInTree->data = data;
            insInTree->left = NULL;
            insInTree->right = NULL;
            curr->right = insInTree;
            return true;
        }
        else
        {
            return Insert(curr->right, data);
        }
        
    }
    else if(data->getAccountNumber() < curr->data->getAccountNumber())
    {
        
        if (curr->left == NULL)
        {
            
            Node *insInTree = new Node();
            insInTree->data = data;
            insInTree->left = NULL;
            insInTree->right = NULL;
            curr->left = insInTree;
            return true;
        }
        else
        {
            return Insert(curr->left, data);
        }
        
    }
    else
    {
        cout << "Account Number: " << data->getAccountNumber()<< " is already open. " << endl;
        return false;
    }
}

inline bool BSTree::Insert(Client *newClient)
{
    if(root == NULL)
    {
        root = new Node();
        root->data = newClient;
    }
    else
    {
        Node *curr = root;
        return Insert(curr,newClient);
    }
    return false;
}

inline Client *BSTree::search(Node *curr, const int number, Client *back) const
{
    if(curr == NULL)
    {
        cout << "Account Number: "<<number << " not found." << endl;
        return NULL;
    }
    else if(number == curr->data->getAccountNumber())
    {
        return curr->data;
    }
    else if (number > curr->data->getAccountNumber())
    {
        return search(curr->right, number, back);
    }
    else if(number < curr->data->getAccountNumber())
    {
        return search(curr->right, number,back);
    }
    else{
        cout << "something went wrong"<< endl;
        Client newClient;
        return NULL;
    }
}

inline bool BSTree::Retrieve(const int number, Client *&back) const
{
    Client *temp = search(root,number, back);
    
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        back = temp;
        return true;
    }
    
}

inline void BSTree::printInOrder(Node* curr) const
{
    if (curr == NULL)
    {
        return;
    }
    
    this->printInOrder(curr->left);
    Client *print = curr->data;
    cout << print->getFirstName()<<" "<<print->getLastName()<<" Account ID: "<<print->getAccountNumber()<< endl;
    cout << "Money Market: " << print->funds[0] << endl;
    cout << "Prime Money Market: " << print->funds[1] << endl;
    cout << "Long-Term Bond: " << print->funds[2] << endl;
    cout << "Short-Term Bond: " << print->funds[3] << endl;
    cout << "500 Index Fund: " << print->funds[4] << endl;
    cout << "Capital Value Fund: " << print->funds[5] << endl;
    cout << "Growth Equity Fund: " << print->funds[6] << endl;
    cout << "Growth Index Fund: " << print->funds[7] << endl;
    cout << "Value Stock Index: " << print->funds[8] << endl;
    cout << "Value Fund: " << print->funds[9] << endl;
    cout<<endl;
    this->printInOrder(curr->right);
    
}

inline void BSTree::Display() const
{
    if(root == NULL)
    {
        cout << "Can't print empty bank" << endl;
    }
    else
    {
        printInOrder(root);
    }
}

inline void BSTree::Empty()
{
    root = NULL;
    root->right = NULL;
    root->left = NULL;
}

inline bool BSTree::isEmpty() const
{
    if(root == NULL)
    {
        return true;
    }
    return false;
}
