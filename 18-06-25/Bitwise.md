# 📘 C++ Bitwise Operators - Quick Reference

This document provides a summary of C++ Bitwise Operators, as referenced from [GeeksforGeeks](https://www.geeksforgeeks.org/cpp/cpp-bitwise-operators/). Bitwise operators operate on bits and perform bit-by-bit operations.

---

## 🧠 What Are Bitwise Operators?

Bitwise operators are used for performing operations on binary representations of integers. These are low-level operations and are especially useful in systems programming, competitive coding, and embedded systems.

---

## 🔧 List of Bitwise Operators

| Operator | Name           | Description                                             | Example (x = 5, y = 9) |
|----------|----------------|---------------------------------------------------------|------------------------|
| `&`      | Bitwise AND    | Each bit of result is 1 if both corresponding bits are 1| `x & y` = 1            |
| `\|`      | Bitwise OR     | Each bit of result is 1 if at least one bit is 1       | `x \| y` = 13           |
| `^`      | Bitwise XOR    | Each bit of result is 1 if bits are different          | `x ^ y` = 12           |
| `~`      | Bitwise NOT    | Inverts all bits                                        | `~x` = -6              |
| `<<`     | Left Shift     | Shifts bits left and fills 0 on the right              | `x << 1` = 10          |
| `>>`     | Right Shift    | Shifts bits right and discards bits on the right       | `y >> 1` = 4           |

---

## 🧪 Example Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 9;

    cout << "x & y = " << (x & y) << endl;
    cout << "x | y = " << (x | y) << endl;
    cout << "x ^ y = " << (x ^ y) << endl;
    cout << "~x = " << (~x) << endl;
    cout << "x << 1 = " << (x << 1) << endl;
    cout << "y >> 1 = " << (y >> 1) << endl;

    return 0;
}
```

**Output:**
```
x & y = 1
x | y = 13
x ^ y = 12
~x = -6
x << 1 = 10
y >> 1 = 4
```

---

## 🧱 Bitwise Operator Tricks & Applications

### 1. Check if a number is even or odd
```cpp
if (x & 1) cout << "Odd";
else cout << "Even";
```

### 2. Swap two numbers without a temporary variable
```cpp
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

### 3. Check if a number is a power of 2
```cpp
bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);
```

### 4. Clear the ith bit
```cpp
x = x & (~(1 << i));
```

### 5. Set the ith bit
```cpp
x = x | (1 << i);
```

### 6. Toggle the ith bit
```cpp
x = x ^ (1 << i);
```

### 7. Get the ith bit
```cpp
int bit = (x >> i) & 1;
```

### 8. Count number of set bits (Hamming Weight)
```cpp
int count = 0;
while (x) {
    count += x & 1;
    x >>= 1;
}
```

### 9. Left Shift and Right Shift in Base-x

Bitwise shifts have a mathematical interpretation in any numeric base `x` (commonly base 2):

#### Left Shift (`a << b`)
Equivalent to multiplying `a` by `x^b`:
```
a << b ≡ a × x^b
```
Example in base 2:
```cpp
int a = 3, b = 2;
int result = a << b; // 3 × 2^2 = 12
```

#### Right Shift (`a >> b`)
Equivalent to performing `floor(a / x^b)`:
```
a >> b ≡ floor(a / x^b)
```
Example in base 2:
```cpp
int a = 19, b = 2;
int result = a >> b; // floor(19 / 2^2) = 4
```

These interpretations help connect binary shifts to arithmetic scaling, which is often useful for writing optimized and readable code.

---

## 🧮 De Morgan's Laws

De Morgan’s Laws describe how logical expressions involving NOT, AND, and OR can be transformed using complement rules. These are extremely useful when simplifying bitwise conditions or Boolean algebra in programming.

### Laws:

1. `~(A & B) = (~A | ~B)`
2. `~(A | B) = (~A & ~B)`

### Example:
```cpp
int A = 5;   // 0101
int B = 9;   // 1001

cout << "~(A & B) = " << (~(A & B)) << endl;
cout << "(~A | ~B) = " << ((~A) | (~B)) << endl;
```

Both expressions above will yield the same result, confirming De Morgan’s Law.

---

## 🧩 Notes

- Bitwise operations are only applicable to integer types.
- These operations are fast and can optimize performance-critical code.
- `~` performs 1’s complement; signed integer results depend on compiler's number representation (usually 2's complement).
- Shifting by a negative or out-of-range value is undefined behavior.

---

## 📚 References

- [GeeksforGeeks - C++ Bitwise Operators](https://www.geeksforgeeks.org/cpp/cpp-bitwise-operators/)
- ISO C++ Standard Documentation

---

## 🔗 Related Topics

- Bitmasking
- Binary Representation
- C++ Operators
- De Morgan’s Laws
- Data Structures (like Trie, Segment Trees using bits)
- Bit Manipulation Tricks
