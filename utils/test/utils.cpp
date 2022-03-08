#include <iostream>
#include "../include/utils.hpp"

using namespace std;

int main() {
    // test the reverse integer
    cout << "Reverse 153 Integer: " << utils::reverse_integer(153) << endl;
    // test the is armstrong integer
    cout << "Is Armstrong 153 Integer: " << (utils::is_armstrong_integer(153)?"True":"False") << endl;
    cout << "Is Armstrong 45 Integer: " << (utils::is_armstrong_integer(45)?"True":"False") << endl;
}