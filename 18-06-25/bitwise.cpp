#include <iostream>
using namespace std;

int main() {
    int a = 7; //  0111
    int b = 4; //  0100

    // Bitwise AND
    int bitwise_and = a & b;

    // Bitwise OR
    int bitwise_or = a | b;

    // Bitwise XOR
    int bitwise_xor = a ^ b;

    // Bitwise NOT
    int bitwise_not = ~b;

    // Bitwise Left Shift
    int left_shift = 5 << 2;

    // Bitwise Right Shift
    int right_shift = 5 >> 2;

      // Printing the Results of
    // Bitwise Operators
    cout << "AND: " << bitwise_and << endl;
    cout << "OR: " << bitwise_or << endl;
    cout << "XOR: " << bitwise_xor << endl;
    cout << "NOT b: " << bitwise_not << endl;
    cout << "Left Shift: " << left_shift << endl;
    cout << "Right Shift: " << right_shift << endl;

    return 0;
}