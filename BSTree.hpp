//
//  BSTree.hpp
//  Program5
//
//  Created by Bryan Song  on 6/2/19.
//  Copyright © 2019 Bryan Song . All rights reserved.
//

#ifndef BSTree_hpp
#define BSTree_hpp

#include "Client.hpp"
#include "Client.cpp"
#include <stdio.h>
class BSTree
{
public:
    BSTree();
    ~BSTree();
    bool Insert(Client *newClient);
    bool Retrieve(const int number, Client *&back) const;
    void Display() const;
    void Empty();
    bool isEmpty() const;
    
    
    
    
private:
    struct Node
    {
        Client *data;
        Node *right;
        Node *left;
    };
    Node *root;
    
    bool Insert(Node *curr, Client *target);
    void printInOrder(Node* curr)const;
    Client *search(Node *curr , const int number, Client *backs)const ;
};




#endif /* BSTree_hpp */
