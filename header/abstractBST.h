#ifndef AbstractBST_h
#define AbstractBST_h

class AbstractBST
{
public:
    AbstractBST(){};
    ~AbstractBST(){};
    virtual bool isEmpty() = 0;
    virtual void addBST(int) = 0;
    virtual void removeBST(int) = 0;
    virtual bool searchBST(int) = 0;
    virtual void max(int &output) = 0;
    virtual void min(int &output) = 0;
};

#endif