// function of pointer
#include <iostream>

using namespace std;

auto increment(int *a) -> void {
    // (*a)++;
    // *a += 1;
    *a = *a + 1;
}

int main(){
    int a = 4;
    cout << "a = " << a << endl;
    cout << "call the function of increment(&a)" << endl;
    increment(&a);
    cout << "a = " << a << endl;
}