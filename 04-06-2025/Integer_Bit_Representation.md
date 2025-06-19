# 🧮 Integer Bit Representation and Ranges in C++

This guide explains how integers are stored using bits, focusing on signed and unsigned types in a 32-bit system.

---

## 📌 Basics of Bit Representation

An `int` in C++ typically uses **32 bits** of memory.

- Each bit can be either 0 or 1.
- With 32 bits, we can represent `2^32` distinct values.

```
Total combinations: 2^32 = 4,294,967,296 values
```

---

## 🔄 Signed vs Unsigned Integers

### 🔹 Signed Integers

- Use **one bit** for sign (0 for positive, 1 for negative)
- Remaining **31 bits** for the magnitude of the number
- Range:
  ```
  -2^31 to (2^31) - 1
  = -2,147,483,648 to 2,147,483,647
  ```
- **Why is max positive `(2^31) - 1`?**
  Because 0 is a non-negative number and takes up **one** value from the positive range.

### 🔹 Unsigned Integers

- No sign bit, all 32 bits used for magnitude
- Range:
  ```
  0 to (2^32) - 1
  = 0 to 4,294,967,295
  ```

---

## 📐 General Formula

| Type      | Range                             |
|-----------|-----------------------------------|
| Signed    | `-2^(n-1)` to `(2^(n-1)) - 1`      |
| Unsigned  | `0` to `(2^n) - 1`                |

Where `n` is the number of bits (e.g., 32 for standard `int`, 64 for `long long` on some systems).

---

## 📊 Approximations

To help estimate powers of 2 more easily:

```
2^10 ≈ 10^3 (roughly 1000)
```

So, rough conversions:

- 2^20 ≈ 1 million
- 2^30 ≈ 1 billion
- 2^32 ≈ 4.3 billion

---

## 🧩 Summary Table for 32-bit Integer

| Representation | Minimum Value      | Maximum Value      | Count of Values     |
|----------------|--------------------|--------------------|---------------------|
| Signed int     | -2,147,483,648     | 2,147,483,647      | 2^32 values         |
| Unsigned int   | 0                  | 4,294,967,295      | 2^32 values         |

---

## 🔗 Related Topics

- Two’s Complement
- Bitwise Operators
- Integer Overflow
- Memory Representation
