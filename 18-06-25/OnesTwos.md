Here's the **corrected and cleaned-up version** of your `README.md` with proper formatting and consistency:

---

```markdown
# 🧮 1's & 2's Complement - Binary Arithmetic Reference

This README summarizes the concepts of **1’s and 2’s complement**, the **representation of negative numbers using boolean algebra**, and how to use complements for **binary subtraction**, based on [this article on GeeksforGeeks](https://www.geeksforgeeks.org/dsa/1s-2s-complement-binary-number/).

---

## 📌 What is 1's and 2's Complement?

In binary arithmetic, negative numbers are represented using **complements**. This allows addition and subtraction to be done using the same logic circuits.

### 🔹 1's Complement

- Inverts every bit of a binary number.
- `1` becomes `0`, and `0` becomes `1`.
- Example:  
  Original: `0101` (5)  
  1's Complement: `1010`

### 🔹 2's Complement

- Add `1` to the 1's complement of a number.
- Most common way to represent negative binary numbers in computers.
- Example:  
  Original: `0101` (5)  
  1's Complement: `1010`  
  2's Complement: `1011` → Represents `-5`

---

## 🧠 Why Use 2’s Complement?

- Eliminates the need for separate subtraction logic.
- Only one representation for zero.
- Efficient for hardware implementation.

---

## 💡 Representing Negative Numbers Using Boolean Algebra

In Boolean algebra (especially in digital circuits), **negative numbers** are often represented using **2’s complement** to keep addition/subtraction operations consistent.

### Example:
To represent `-5` in 4-bit:
1. Take binary of `5`: `0101`  
2. 1's complement: `1010`  
3. Add 1 → 2's complement: `1011` = `-5`

---

## ➖ Subtraction Using 2’s Complement

To subtract using complements, we **add the 2’s complement** of the subtrahend to the minuend.

### 🔧 Formula:

```

A - B = A + 2’s\_complement(B)

```

### 🧪 Example: 5 - 2

1. Binary of `5` = `0101`  
2. Binary of `2` = `0010`  
3. 1’s complement of `2` = `1101`  
4. 2’s complement of `2` = `1110`  
5. Add:
```

0101

* 1110

---

10011

```
6. Discard carry → `0011` = `3`

✔ Result: **5 - 2 = 3**

---

## 🧪 Example: 2 - 5

1. Binary of `2` = `0010`  
2. Binary of `5` = `0101`  
3. 2’s complement of `5` = `1011`  
4. Add:
```

0010

* 1011

---

1101

````

This is a **negative result**, and since it’s in 2’s complement:  
- 2's complement of `1101` = `0011`  
- → Result = `-3`

✔ Result: **2 - 5 = -3**

---

## ⚙️ C++ Code Example

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int toTwosComplement(int n, int bits) {
    if (n >= 0) return n;
    int mask = (1 << bits) - 1;
    return ((~(-n)) + 1) & mask;
}

int main() {
    int a = 5, b = -2;
    int bits = 4;

    int a_bin = toTwosComplement(a, bits);
    int b_bin = toTwosComplement(b, bits);

    int result = (a_bin + b_bin) & ((1 << bits) - 1);

    cout << "Result (binary): " << bitset<4>(result) << endl;

    // Interpret result in decimal (manual step to show negative)
    if ((result >> (bits - 1)) & 1) {
        result = -((~result + 1) & ((1 << bits) - 1));
    }

    cout << "Result (decimal): " << result << endl;
    return 0;
}
````

---

## 🧩 Notes

* 1’s complement has **two representations of 0** (`0000` and `1111`) → not used in modern systems.
* 2’s complement is widely adopted in modern hardware.
* Overflow can occur if the result exceeds the fixed bit width.

---

## 📚 References

* [GeeksforGeeks - 1's and 2's Complement](https://www.geeksforgeeks.org/dsa/1s-2s-complement-binary-number/)
* Digital Logic Design textbooks
* Computer Architecture standards (e.g., x86, MIPS)

---

## 🔗 Related Topics

* Bitwise Operators
* Binary Arithmetic
* Signed Integer Representation
* Arithmetic Overflow and Wrap-around

```

---

Let me know if you’d like this exported into a `.md` file, turned into a PDF, or added to an existing documentation project.
```
