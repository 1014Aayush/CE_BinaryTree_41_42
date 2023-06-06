#ifndef arrayBST_h
#define arrayBST_h

#include "./abstractBST.h"
#define MAX_SIZE 10

struct ArrayBSTNode
{
public:
    int key;
    int value;

    ArrayBSTNode()
    {
        key = 0;
        value = 0;
    };

    ArrayBSTNode(int k, int value)
    {
        key = k;
        value = value;
    };
};

class ArrayBST
{
public:
    ArrayBST();
    ~ArrayBST();
    bool isEmpty();
    void addBST(int key, int value);
    bool searchBST(int key);

    void removeBST(int keytoDelete);
    void printBST();

private:
    int size;
    ArrayBSTNode BST[MAX_SIZE];
};

#endif