
# 🔧 Bitwise Properties for Competitive Programming

This repository contains a curated list of **bitwise tricks, properties, and patterns** that are frequently used in **competitive programming**. Bit manipulation is a powerful tool for writing highly efficient code, especially in contests where both time and space are critical.

## 🚀 Why Bitwise?

Bitwise operations:
- Are extremely **fast** (constant time).
- Allow elegant solutions for problems involving subsets, masks, parity, etc.
- Help in optimizing space with **bitsets** and compact representations.

---

## 📘 Table of Contents

- [Basics](#basics)
- [Common Bitwise Operations](#common-bitwise-operations)
- [Finding MSB and LSB](#finding-msb-and-lsb)
- [Useful Bitwise Tricks](#useful-bitwise-tricks)
- [Set Manipulation using Bits](#set-manipulation-using-bits)
- [Advanced Patterns](#advanced-patterns)
- [Practice Problems](#practice-problems)

---

## 🧱 Basics

| Operation        | Expression       | Description                        |
|------------------|------------------|------------------------------------|
| AND              | `a & b`          | Bitwise AND                        |
| OR               | `a \| b`          | Bitwise OR                         |
| XOR              | `a ^ b`          | Bitwise XOR                        |
| NOT              | `~a`             | Bitwise NOT                        |
| Left Shift       | `a << n`         | Shifts bits of `a` left by `n`     |
| Right Shift      | `a >> n`         | Shifts bits of `a` right by `n`    |

---

## 🔍 Common Bitwise Operations

| Property                             | Expression / Result                      |
|--------------------------------------|------------------------------------------|
| Check if `n` is even                 | `n & 1 == 0`                              |
| Multiply `n` by 2^k                  | `n << k`                                  |
| Divide `n` by 2^k                    | `n >> k`                                  |
| Check if `n` is power of 2           | `n & (n - 1) == 0` (only if `n > 0`)      |
| Swap `a` and `b` without temp        | `a ^= b; b ^= a; a ^= b;`                 |
| Clear lowest set bit                | `n & (n - 1)`                             |
| Isolate lowest set bit              | `n & -n`                                  |
| Count set bits (Brian Kernighan's)  | `while (n) { n &= (n - 1); count++; }`    |
| Turn on k-th bit                    | `n \| (1 << k)`                            |
| Turn off k-th bit                   | `n & ~(1 << k)`                           |
| Toggle k-th bit                     | `n ^ (1 << k)`                            |
| Check k-th bit is on                | `n & (1 << k)`                            |

---

## 🔦 Finding MSB and LSB

**LSB (Least Significant Set Bit)**:
- Isolate: `n & -n`
- Clear: `n & (n - 1)`
- Position (0-based index): Count trailing zeros

**MSB (Most Significant Set Bit)**:
- Isolate: Use a method to round `n` down to the nearest power of 2.
    - Example logic:
        ```
        n |= n >> 1
        n |= n >> 2
        n |= n >> 4
        n |= n >> 8
        n |= n >> 16
        ...
        (n + 1) >> 1
        ```
- Position (0-based index): Count leading zeros in word size, subtract from total bits

---

## 🧠 Useful Bitwise Tricks

| Trick / Goal                        | Expression / Technique                   |
|------------------------------------|------------------------------------------|
| Clear lowest set bit               | `n & (n - 1)`                             |
| Isolate lowest set bit             | `n & -n`                                  |
| Create mask with first k bits on   | `(1 << k) - 1`                            |
| Check if n is power of 2           | `n > 0 && (n & (n - 1)) == 0`             |

---

## 🧮 Set Manipulation Using Bits

You can represent a subset of `{0, 1, ..., N-1}` using a single integer of `N` bits.

| Operation               | Code                      | Meaning                      |
|------------------------|---------------------------|------------------------------|
| Add element `i`        | `mask \|= (1 << i)`         | Add `i` to set               |
| Remove element `i`     | `mask &= ~(1 << i)`        | Remove `i` from set          |
| Toggle element `i`     | `mask ^= (1 << i)`         | Toggle presence of `i`       |
| Check element `i`      | `(mask & (1 << i)) != 0`   | Check if `i` is in set       |
| Count elements in set  | Count of 1s in binary      | Number of elements present   |

---

## 🧠 Advanced Patterns

| Pattern                                 | Description                                 |
|----------------------------------------|---------------------------------------------|
| Loop through all subsets of a set      | `for (int sub = mask; sub; sub = (sub - 1) & mask)` |
| Get highest one bit (like log2)        | Use MSB isolation techniques                |
| Get position of rightmost set bit      | Use LSB and count trailing zeros            |
| Turn off rightmost 1-bit               | `n & (n - 1)`                               |
| Create mask with first k bits on       | `(1 << k) - 1`                              |

---



## 🛠 Tools & Tips

- Use built-in bit functions when available: trailing/leading zero count, population count.
- Use `bitset<N>` or equivalent for compact set representation.
- Avoid undefined behavior when shifting: only shift within type’s bit-width.

---

## 📚 References

- [CP-Algorithms: Bit Manipulation](https://cp-algorithms.com/)
- [GeeksforGeeks Bit Magic](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
- [Topcoder Bit Tricks](https://www.topcoder.com/thrive/articles/Bit%20Manipulation%20-%20Basics)

