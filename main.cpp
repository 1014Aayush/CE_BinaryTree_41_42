#include "./cpp/arrayBST.cpp"
#include "./header/abstractBST.h"
#include "./header/student.h"
using namespace std;

int main()
{
    Student student;
    student.name = 'A';
    student.age = 20;
    student.roll_no = 42;

    ArrayBSTNode Node1;
    Node1.key = student.roll_no;
    Node1.student = student;

    ArrayBST ArrayB;
    ArrayB.addBST(1, student);
    ArrayB.addBST(3, student);
    ArrayB.addBST(5, student);
    ArrayB.addBST(6, student);
    ArrayB.addBST(7, student);
    ArrayB.addBST(2, student);
    ArrayB.addBST(8, student);
    ArrayB.printBST();

    // Removes Node
    ArrayB.removeBST(5);

    // Prints BST After Removing
    cout << endl
         << "After Removing 5" << endl;
    ArrayB.printBST();

    return 0;
}
