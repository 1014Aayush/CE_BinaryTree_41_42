#include "../header/arrayBST.h"
#include <iostream>
using namespace std;

// Sie is declared as private in the header file
// It increases if the addBST function is called
// It decreases if the removeBST function is called

// MAX_SIZE is declared as private in the header file
//  It is the maximum size of the array

bool ArrayBST::isEmpty()
{
    return (size == 0);
};
bool ArrayBST::isFull()
{
    return (size == MAX_SIZE);
};
void ArrayBST::addBST(int key, Student value)
{
    // Loops through the entire array to find the correct position for the key
    // If the key is found, a message is displayed
    // If the key is not found, the key and value are added to the array
    int index = 0;
    while (index < MAX_SIZE)
    {
        // If the value is 0, the key and value are added to the array
        // If the value is not 0, Other conditions are checked
        if (BST[index].key == 0)
        {
            BST[index].key = key;
            BST[index].student = value;
            size++;
            break;
        }
        else if (key < BST[index].key)
        {
            // Adds the key to the left of the parent node
            // Represented in Array as 2n+1
            // From Array representaion of BST, the left child is always less than the parent
            index = 2 * index + 1;
        }
        else if (key > BST[index].key)
        {
            // Adds the key to the right of the parent node
            // Represented in Array as 2n+2
            // From Array representaion of BST, the right child is always greater than the parent
            index = 2 * index + 2;
        }
        else
        {
            cout << "Duplicate Key" << endl;
        }
    }
}
void ArrayBST::removeBST(int key)
{
    // Find the index of the key in the array
    int index = 0;
    while (index < MAX_SIZE && BST[index].key != key)
    {
        if (key < BST[index].key)
        {
            // Traverse to the left child
            index = 2 * index + 1;
        }
        else
        {
            // Traverse to the right child
            index = 2 * index + 2;
        }
    }

    if (index < MAX_SIZE && BST[index].key == key)
    {
        // Key is found, remove the node
        // Shift the nodes to the left to maintain the BST structure

        // Find the index of the rightmost child of the left subtree
        int rightmostChildIndex = index - 1;
        while (rightmostChildIndex >= 0 && BST[rightmostChildIndex].key != 0)
        {
            rightmostChildIndex = 2 * rightmostChildIndex + 2;
        }

        // Shift the nodes to the left
        for (int i = index; i < rightmostChildIndex; i++)
        {
            BST[i] = BST[i + 1];
        }

        // Clear the rightmost child node
        BST[rightmostChildIndex].key = 0;
        BST[rightmostChildIndex].student = Student();
        size--;
    }
    else
    {
        cout << "Key not found" << endl;
    }
}
bool ArrayBST::searchBST(int key)
{
    // Loops through the entire array to find the key
    // If the key is found,true is returned
    // If the key is not found, false is returned
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (BST[i].key == key)
        {
            return 1;
        }
    }
    return 0;
}

void ArrayBST::printBST()
{
    // Prints the Entire Array
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        cout << BST[i].key << "\t";
    }
}