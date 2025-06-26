#include <iostream>
using namespace std;

class Node
{
    public:
    int info;
    Node *leftchild;
    Node *rigthchild;

    // Constructor for the node class
    Node(){
        leftchild = nullptr; // Initialize left child to null
        
    }
}