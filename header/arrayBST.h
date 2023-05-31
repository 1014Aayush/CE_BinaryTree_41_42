#include "./abstractBST.h"
#include "student.h"
#ifndef arrayBST_h
#define arrayBST_h
#define MAX_SIZE 140

class ArrayBSTNode
{
public:
    int key;
    Student student;
    ArrayBSTNode()
    {
        key = 0;
        Student student;
        student = student;
    };
    ArrayBSTNode(int k, Student newstudent)
    {
        key = k;
        student = newstudent;
    };
};

class ArrayBST : public AbstractBST
{
private:
    ArrayBSTNode BST[MAX_SIZE];
    int size;

public:
    ArrayBST(){};
    ArrayBST(ArrayBSTNode Node)
    {
        int index;
        BST[index] = Node;
    }
    virtual bool isEmpty();
    bool isFull();
    void addBST(int key, Student value);
    bool searchBST(int key);
    void removeBST(int key);
    void printBST();
};

#endif