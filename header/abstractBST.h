#ifndef AbstractBST_h
#define AbstractBST_h

class AbstractBST
{
public:
    AbstractBST(){};
    ~AbstractBST(){};
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void addBST(int key) = 0;
    virtual bool searchBST(int key) = 0;
    virtual void removeBST(int key) = 0;
};

#endif