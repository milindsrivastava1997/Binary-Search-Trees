#pragma once

struct node
{
    node* parent;
    node* left;
    node* right;

    int key;
    int subArraySize;
    
};

class BST
{
private:
    node* BSTRootNode;
    int kValue;

public:
    BST(void);
    void addNode(void);
    void printBST(node*);

    node* getRootNode(void);

    void countNodesLessThan(void);
    //~BST(void);
};