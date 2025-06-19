
# Bit Masking in C/C++

Bit masking is a powerful technique used in programming, especially in problems involving sets, permissions, or manipulating bits directly. It allows you to use bits to represent information compactly and perform operations efficiently.

---

## 🔍 What is Bit Masking?

Bit masking involves using **bitwise operators** to **set, clear, toggle, or check** individual bits in an integer. Common use cases:
- Efficient subset generation
- Checking for certain properties (like being a power of two)
- Representing on/off states

---

## 🛠️ Common Bitwise Operators

| Operator | Symbol | Description                      |
|----------|--------|----------------------------------|
| AND      | `&`    | Both bits must be 1              |
| OR       | `\|`    | Either bit is 1                  |
| XOR      | `^`    | One bit must be 1                |
| NOT      | `~`    | Inverts bits                     |
| Left Shift | `<<` | Shifts bits to the left (×2)     |
| Right Shift|`>>`  | Shifts bits to the right (÷2)    |

---

## 📘 Example Problem 1: Check if a Number is Power of 2

### ✅ Problem
Determine whether a given number `n` is a power of 2.

### 🧠 Concept

A number is a power of 2 if it has **only one bit set** in its binary representation.
Example:  
- `4` in binary → `100`
- `8` in binary → `1000`

Only one bit is set → `n & (n - 1)` will be 0.

### ✅ Code (C++)
```cpp
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}
```

### 🔍 Step-by-Step
Let `n = 8`  
Binary: `1000`  
`n - 1 = 7` → `0111`  
Now `n & (n - 1)` = `1000 & 0111` = `0000` → Result is `true`

---

## 📘 Example Problem 2: Count Set Bits in an Integer

### ✅ Problem
Count the number of 1s in the binary representation of a number.

### ✅ Code (C++)
```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);  // Check LSB
        n >>= 1;           // Shift right
    }
    return count;
}
```

### 🔍 Step-by-Step
Let `n = 13` → Binary: `1101`

```
Iteration 1: 1101 & 0001 = 1 → count = 1
Iteration 2: 0110 & 0001 = 0 → count = 1
Iteration 3: 0011 & 0001 = 1 → count = 2
Iteration 4: 0001 & 0001 = 1 → count = 3
```

---

## 📘 Example Problem 3: Turn Off the k-th Bit of a Number

### ✅ Problem
Turn off (set to 0) the `k-th` bit of a number.

### ✅ Code (C++)
```cpp
int turnOffKthBit(int n, int k) {
    return n & ~(1 << (k - 1));
}
```

### 🔍 Step-by-Step
Let `n = 29` → Binary: `11101`, k = 3  
`1 << (3-1)` = `1 << 2` = `100`  
`~(100)` = `111011`  
`11101 & 11011` = `11001` = 25

---

## 📘 Example Problem 4: Generate All Subsets of a Set

### ✅ Problem
Generate all subsets of a given set using bit masking.

### ✅ Code (C++)
```cpp
void generateSubsets(vector<int> &arr) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}
```

### 🔍 Step-by-Step
Let arr = {1, 2, 3} → n = 3  
We go from 0 to 2³ - 1 = 7

Example:
- mask = 5 → `101` → includes elements at index 0 and 2 → subset = `{1, 3}`

---

## 📎 References

- [Bitmasking in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/bitmasking-in-cpp/)
- [Bitmasking in C - GeeksforGeeks](https://www.geeksforgeeks.org/c/c-bitmasking/)
- [Check Power of 2 - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/program-to-find-whether-a-given-number-is-power-of-2/)

---

## 📚 Conclusion

Bit masking is a critical concept in competitive programming and system-level development. It enhances performance by allowing you to operate directly on bits, making certain problems extremely efficient.

Practice more problems to master bitwise techniques!
