#include <iostream>
#include "my_shared_ptr.h"

using namespace std;

class Box
{
public:
    int length, width, height;
    Box() : length(0), width(0), height(0)
    {
    }
};
int main()
{
    my_shared_ptr<Box> obj;
    cout << obj.get_count() << endl; //  0
    my_shared_ptr<Box> box1(new Box());
    cout << box1.get_count() << endl; // 1
    my_shared_ptr<Box> box2(box1); // calls copy constructor
    cout << box1.get_count() << endl; //  2
    cout << box2.get_count() << endl; //  2

    return 0;
}