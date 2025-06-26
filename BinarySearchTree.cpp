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
        rigthchild = nullptr; // Initialize rigth child to null
    }
};

class BinaryTree
{
    public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // Initializing ROOT to null
    }

    void insert()
    {
        int x;
        cout << "Masukkan nilai: ";
        cin >> x;

        // step 1: Allocate memory for the new node 
        Node *newNode = new Node();

        // step 2: Assing value to the data field of new node
        newNode->info = x;

        // step 3: Make the left and rigth child of the new node point to NULL
        newNode->leftchild = nullptr;
        newNode->rigthchild = nullptr;

        // step 4: Locate the node which will be the parent of the node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);
    }
}