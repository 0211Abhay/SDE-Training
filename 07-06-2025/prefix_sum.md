
# 📘 Prefix Sum – In-Depth Guide

## 📌 What is Prefix Sum?

A **Prefix Sum** (also called **Cumulative Sum**) is a technique used to **quickly calculate the sum of elements in a range** of an array. It is commonly used in problems that require repeated range sum queries.

---

## 📚 Basic Idea

Given an array `A` of size `n`, create an array `prefix[]` such that:

```
prefix[i] = A[0] + A[1] + ... + A[i]
```

This allows us to compute the **sum of any subarray from index `l` to `r`** in constant time using:

```
sum(l, r) = prefix[r] - prefix[l-1]
```

(If `l = 0`, then `sum(0, r) = prefix[r]`)

---

## ⚙️ Step-by-Step Construction

### 🔹 Step 1: Original Array
Let’s take an example array:

```
A = [3, 2, 4, 5, 1]
```

### 🔹 Step 2: Initialize Prefix Array

```
prefix[0] = A[0] = 3
```

### 🔹 Step 3: Compute Remaining Prefix Sums

```
prefix[1] = prefix[0] + A[1] = 3 + 2 = 5
prefix[2] = prefix[1] + A[2] = 5 + 4 = 9
prefix[3] = prefix[2] + A[3] = 9 + 5 = 14
prefix[4] = prefix[3] + A[4] = 14 + 1 = 15
```

### 🔹 Final Prefix Array

```
prefix = [3, 5, 9, 14, 15]
```

---

## 🧮 Query Example

**Find the sum of A[1] to A[3] (i.e., 2 + 4 + 5 = 11)**

```
sum(1, 3) = prefix[3] - prefix[0] = 14 - 3 = 11
```

---

## 🧠 Why Use Prefix Sum?

- Reduces **O(n)** range sum queries to **O(1)** after **O(n)** preprocessing.
- Used in:
  - Range queries
  - Sliding window techniques
  - 2D prefix sum
  - XOR-based prefix variants

---

## 🔄 Time & Space Complexity

| Operation      | Time    | Space   |
|----------------|---------|---------|
| Preprocessing  | O(n)    | O(n)    |
| Range Query    | O(1)    |         |

---

## 🧪 Edge Cases

- Empty array: return 0 or handle as base case.
- Single element queries.
- Query from index `0` (requires checking before subtracting `prefix[l-1]`).
- Negative numbers.

---

## 🔠 C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> computePrefixSum(const vector<int>& A) {
    int n = A.size();
    vector<int> prefix(n);
    prefix[0] = A[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + A[i];
    }
    return prefix;
}

int rangeSum(const vector<int>& prefix, int l, int r) {
    return l == 0 ? prefix[r] : prefix[r] - prefix[l - 1];
}

int main() {
    vector<int> A = {3, 2, 4, 5, 1};
    vector<int> prefix = computePrefixSum(A);

    cout << "Sum of range [1, 3]: " << rangeSum(prefix, 1, 3) << endl; // Output: 11
}
```

---

## 🐍 Python Implementation

```python
def compute_prefix_sum(A):
    prefix = [0] * len(A)
    prefix[0] = A[0]
    for i in range(1, len(A)):
        prefix[i] = prefix[i-1] + A[i]
    return prefix

def range_sum(prefix, l, r):
    if l == 0:
        return prefix[r]
    return prefix[r] - prefix[l-1]

A = [3, 2, 4, 5, 1]
prefix = compute_prefix_sum(A)

print("Sum of range [1, 3]:", range_sum(prefix, 1, 3))  # Output: 11
```

---

## 💡 Advanced Concepts

### 1️⃣ 2D Prefix Sum

Used to compute submatrix sums efficiently:

```text
prefix[i][j] = A[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
```

### 2️⃣ Prefix XOR

Used in XOR-related problems:

```text
prefix[i] = A[0] ^ A[1] ^ ... ^ A[i]
```

---

## 🛠️ Real-World Applications

- Competitive programming
- Financial analytics (cumulative revenue/sales)
- Histogram analysis in image processing
- Sliding window optimizations
- Difference arrays

---

## ✅ Summary

- Prefix sum is a powerful technique to reduce query time.
- Works best for **static arrays** where updates are rare.
- For dynamic updates, consider **Segment Trees** or **Binary Indexed Trees (Fenwick Tree)**.

---

## 📎 Resources

- [Prefix Sum on GeeksForGeeks](https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/)
- [Prefix Sum Patterns – LeetCode Discuss](https://leetcode.com/discuss/general-discussion/1152825/prefix-sum-technique-explained)

---
