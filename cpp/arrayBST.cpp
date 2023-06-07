#include "../header/abstractBST.h"
#include "../header/arrayBST.h"
#include <iostream>
using namespace std;

ArrayBST::ArrayBST()
{
    size = 0;
};

bool ArrayBST ::isEmpty()
{
    if (size == 0)
        return true;
    return false;
};

void ArrayBST ::addBST(int key, int value)
{
    if (size == MAX_SIZE)
    {
        cout << "Size Exceed" << endl;
        return;
    }
    if (size == 0)
    {
        BST[0] = ArrayBSTNode(key, value);
        size++;
        return;
    }

    int currentindex = 0;
    while (true)
    {
        if (key > BST[currentindex].key)
        {
            if ((2 * currentindex + 2) >= MAX_SIZE)
            {
                cout << "Size Exceed" << endl;
                return;
            }
            currentindex = 2 * currentindex + 2;
        }

        else if (key < BST[currentindex].key)
        {
            if ((2 * currentindex + 1) >= MAX_SIZE)
            {
                cout << "Size Exceeded" << endl;
                return;
            }
            currentindex = 2 * currentindex + 1;
        }

        else
        {
            BST[currentindex].value = value;
            return;
        }

        if (BST[currentindex].key == 0)
        {
            BST[currentindex] = ArrayBSTNode(key, value);
            size++;
            return;
        }
    }
};

void ArrayBST ::removeBST(int keytoDelete)
{
    if (size == 0)
    {
        cout << "Array is empty" << endl;
        return;
    }

    int currentIndex = 0;
    while (true)
    {
        if (keytoDelete > BST[currentIndex].key)
        {
            if ((2 * currentIndex + 2) >= MAX_SIZE)
            {
                cout << " Not Found" << endl;
                return;
            }
            currentIndex = 2 * currentIndex + 2;
        }

        else if (keytoDelete < BST[currentIndex].key)
        {
            if ((2 * currentIndex + 1) >= MAX_SIZE)
            {
                cout << " Not Found" << endl;
                return;
            }
            currentIndex = 2 * currentIndex + 1;
        }
        else
        {

            if (2 * currentIndex + 1 < MAX_SIZE && BST[2 * currentIndex + 1].key != 0 &&
                2 * currentIndex + 2 < MAX_SIZE && BST[2 * currentIndex + 2].key != 0)
            {

                int successorIndex = 2 * currentIndex + 1;
                while (2 * successorIndex + 2 < MAX_SIZE && BST[2 * successorIndex + 2].key != 0)
                {
                    successorIndex = 2 * successorIndex + 2;
                }
                BST[currentIndex] = BST[successorIndex];
                currentIndex = successorIndex;
            }
            else if (2 * currentIndex + 1 < MAX_SIZE && BST[2 * currentIndex + 1].key != 0)
            {
                BST[currentIndex] = BST[2 * currentIndex + 1];
                currentIndex = 2 * currentIndex + 1;
            }
            else if (2 * currentIndex + 2 < MAX_SIZE && BST[2 * currentIndex + 2].key != 0)
            {
                BST[currentIndex] = BST[2 * currentIndex + 2];
                currentIndex = 2 * currentIndex + 2;
            }
            else
            {
                BST[currentIndex] = ArrayBSTNode();
                return;
            }
        }

        if (BST[currentIndex].key == 0)
        {
            cout << "Not Found" << endl;
            return;
        }
    }
};

bool ArrayBST::searchBST(int targetkey)
{
    int currentIndex = 0;
    while (true)
    {
        if (targetkey > BST[currentIndex].key)
        {
            if ((2 * currentIndex + 2) >= MAX_SIZE)
            {
                return false;
            }
            currentIndex = 2 * currentIndex + 2;
        }

        else if (targetkey < BST[currentIndex].key)
        {
            if ((2 * currentIndex + 1) >= MAX_SIZE)
            {
                return false;
            }
            currentIndex = 2 * currentIndex + 1;
        }
        else
        {
            cout << "The value of key " << BST[currentIndex].key << " is " << BST[currentIndex].value << " The index  is " << currentIndex << endl;
            return true;
        }
        if (BST[currentIndex].key == 0)
        {
            return false;
        }
    }
};