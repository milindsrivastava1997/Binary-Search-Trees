#include "bst.h"
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    BST obj;
    char c = 'n';
    do {
        cout << "Do you want to enter another landing time ? ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            obj.addNode();
        }
    } while (c == 'y' || c == 'Y');
    
    cout << "---Done Adding New Nodes---"<< endl;
    cout << "Printing tree : " << endl << endl;
    
    obj.printBST(obj.getRootNode());
    obj.countNodesLessThan();
    c = 'n';
    do {
        cout << "Do you want to compute number of nodes less than a specified landing time ? ";
        cin >> c;
        cout << endl;
        if (c == 'y' || c == 'Y')
        {
            obj.countNodesLessThan();
        }
    } while (c == 'y' || c == 'Y');
    
    _getch();
    return 0;
}