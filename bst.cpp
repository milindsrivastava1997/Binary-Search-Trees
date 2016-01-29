#include "bst.h"
#include <math.h>
#include <iostream>
using namespace std;

BST::BST(void)
{
    BSTRootNode = new node;
    BSTRootNode->key = 0;
    BSTRootNode->subArraySize = 1;

    cout << "Enter the k-value : ";
    cin >> kValue;

    do {
        cout << "Enter the landing time for the root node of BST : ";
        cin >> BSTRootNode->key;
        cout << endl;
    }while(BSTRootNode->key <= 0);

    
    BSTRootNode->parent = nullptr;
    BSTRootNode->left = nullptr;
    BSTRootNode->right = nullptr;
    
}

void BST::addNode(void)
{
    node* nodeToBeAdded = new node;
    cout << "New Node Being Added!" << endl;
    cout << "Enter landing time of new node : ";
    cin >> nodeToBeAdded->key;
    nodeToBeAdded->parent = nullptr;
    nodeToBeAdded->left = nullptr;
    nodeToBeAdded->right = nullptr;
    nodeToBeAdded->subArraySize = 1;

    node* currentNode = BSTRootNode;
    while (1)
    {
        if ((abs(nodeToBeAdded->key - currentNode->key) <= kValue))
        {
            cout << "Landing time to be added violates k-value property!";
            cout << endl << "Landing time not added" <<endl;
            return;
        }
        if (nodeToBeAdded->key < 0)
        {
            cout << "Landing time has to be greater than 0";
            cout << endl << "Landing time not added" << endl;
            return;
        }

        currentNode->subArraySize++;

        if (nodeToBeAdded->key < currentNode->key)
        {
            if (currentNode->left == nullptr)
            {
                currentNode->left = nodeToBeAdded;
                nodeToBeAdded->parent = currentNode;
                return;
            }
            else
            {
                currentNode = currentNode->left;
            }
        }
        else
        {
            if (currentNode->right == nullptr)
            {
                currentNode->right = nodeToBeAdded;
                nodeToBeAdded->parent = currentNode;
                return;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }
    }
}

void BST::printBST(node* temp)
{
    cout << temp->key << "----" << temp->subArraySize << endl;
    if (temp->left != nullptr)
    {
        printBST(temp->left);
    }
    if (temp->right != nullptr)
    {
        printBST(temp->right);
    }
}

node* BST::getRootNode(void)
{
    return BSTRootNode;
}

void BST::countNodesLessThan(void)
{
    int targetLandingTime;
    int numberOfNodes = 0;

    cout << "I want to find number of nodes with landing time less than (enter landing time) : ";
    cin >> targetLandingTime;

    node* currentNode = BSTRootNode;
    while (1)
    {
        
        if (currentNode->key == targetLandingTime)
        {
            numberOfNodes++;
            if (currentNode->left != nullptr)
            {
                numberOfNodes += currentNode->left->subArraySize;
            }
            break;
        }
        if (targetLandingTime < currentNode->key)
        {
            if (currentNode->left == nullptr)
            {
                break;
            }
            else
            {
                currentNode = currentNode->left;
                continue;
            }
        }
        else
        {
            numberOfNodes++;//for adding current node
            numberOfNodes += currentNode->left->subArraySize;
            if (currentNode->right == nullptr)
            {
                break;
            }
            else
            {
                currentNode = currentNode->right;
                continue;
            }
        }
    }

    cout << "Number of nodes with landing time less than equal to " << targetLandingTime << " is/are : " << numberOfNodes << endl << endl;
}
