#include <iostream>

using namespace std;

int main()
{
    // *ptr is value at
    int *p, x;
    x = 10;
    p = &x; // p is a pointer to x / p is store address of x
    cout << "Address of x: " << &x << endl;
    cout << "value of p: " << p << " because p is store x address" << endl;
    cout << "value at p: " << *p << " because *p is point x, therefor print value of x" << endl;
    // change value of x through p
    *p = 20;
    cout << "value of x: " << x << endl;

    // Double Pointer:
    // Double Pointer is a pointer to a pointer
    int **pp;
    pp = &p; // pp is a pointer to a pointer / pp is store address of p
    cout << "Address of p: " << &p << endl;
    cout << "value of pp: " << pp << " because pp is store p address" << endl;
    cout << "value at pp: " << *pp << " because *pp is point p, therefor print value of p" << endl;
    cout << "value at **pp: " << **pp << " because **pp, its point to point, mean, first **pp is point to p, but p is point to x, so print the value x" << endl;
    // change value of x through pp
    **pp = 30;
    cout << "value of x: " << x << endl;
    return 0;
}
