
# 🔢 Mathematical Formulas for LSB (Least Significant Set Bit)

This document explains three mathematical expressions that can be used to determine the position (index) of the **Least Significant Set Bit (LSB)** in a number using logarithmic and bitwise operations. These formulas are especially useful in competitive programming and bit manipulation tasks.

---

## 🧠 What is LSB?

The **Least Significant Set Bit (LSB)** of a number `n` is the rightmost bit that is set to `1` in its binary representation.

For example:
```
n = 20         → Binary: 10100
LSB position   → Index 2 (0-based), value 4 (2^2)
```

---

## 🧮 Formulas to Find LSB Index

Below are three equivalent expressions to find the **index** (position) of the LSB.

### 1️⃣ Formula 1:
```
log₂(n ^ (n & (n - 1)))
```
- `n & (n - 1)` clears the lowest set bit.
- `n ^ (...)` isolates that lowest set bit.
- `log₂(...)` gives the index of that bit.

### 2️⃣ Formula 2:
```
log₂(n ^ (n - 1))
```
- Slightly optimized form based on the same idea.
- `n - 1` flips all bits including and to the right of the LSB.
- XOR with `n` keeps only the LSB.

### 3️⃣ Formula 3:
```
log₂(n ^ (n & (n - 1)))
```
- Equivalent to Formula 1, shown again for clarity.

---

## 🧪 Example

Let `n = 20`:

- Binary of `n`: `10100`
- `n - 1`: `10011`
- `n & (n - 1)`: `10000`
- `n ^ (n & (n - 1))`: `00100` → which is `4`
- `log₂(4) = 2`

So, the **LSB is at index 2** (0-based).

---

## ✅ Summary

| Formula                             | Purpose                       |
|-------------------------------------|-------------------------------|
| `log₂(n ^ (n & (n - 1)))`          | Find index of LSB             |
| `log₂(n ^ (n - 1))`                | Shortcut version              |
| `log₂(n ^ (n & (n - 1)))`          | Equivalent form               |

All expressions give the same result and are valid as long as `n > 0`.

---

## 📌 Notes
- These formulas assume integer inputs `n > 0`.
- The result is a 0-based index of the least significant bit set to 1.
- Use integer-based `log2` if programming (e.g., `floor(log2(...))`).

---

## 📚 Reference
- Derived from standard bit manipulation identities:
  - `n & -n` isolates LSB value.
  - `n ^ (n & (n - 1))` also isolates LSB value.

---

## 🛠 Usage

Useful in:
- Bitmask DP
- Efficient set operations
- Fast power-of-two indexing
- Optimization in competitive programming

