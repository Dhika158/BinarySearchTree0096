
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

        // step 5: If parent is NULL (Tree is empty)
        if (parent == nullptr)
        {
            // 5a: Mark the new node as ROOT
            ROOT = newNode;

            // 5b: Exit
            return;
        }

        // step 6: If the value in the data field of new node is less than of parent
        if (x < parent->info)
        {
            // 6a: Make the left child of parent point to the new node
            parent->leftchild = newNode;

            // 6b: Exit
            return;
        }
        // step 7: If the value in the data field of the new node is greater than that of the parent
        else if (x > parent->info)
        {
        // 7a: Make the rigth child of parent point to the new node 
        parent->rigthchild = newNode;

        // 7b: Exit
        return;
        }
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        // this function searches the currentNode of the specified Node as well as the current Node of the is parent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
            currentNode = currentNode->leftchild;
            else
            currentNode = currentNode->rigthchild;
        }
    }

    public :
    bool isEmpty()
    {
    return ROOT == nullptr;
    }

    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        inorder(ptr->leftchild);
        cout << ptr->info << " "; 
        inorder(ptr->rigthchild);
    }
    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        cout << ptr->info << " "; 
        preorder(ptr->leftchild);
        inorder(ptr->rigthchild);
    }
    void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;
        postorder(ptr->leftchild);
        inorder(ptr->rigthchild);
        cout << ptr->info << " "; 
    }
};

int main()
{
BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}