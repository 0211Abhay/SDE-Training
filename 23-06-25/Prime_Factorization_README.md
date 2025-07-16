
# Prime Factorization - Print All Prime Factors of a Given Number

This project explains and implements two approaches to **print all prime factors** of a given number `n`.

---

## 🧠 Problem Statement

Given an integer `n`, find and print **all its prime factors** in ascending order.

### Example:

```
Input: n = 36  
Output: 2 2 3 3

Input: n = 97  
Output: 97
```

---

## 🔧 Approaches

### 🟠 1. Naive Approach – O(n) to O(n²)

#### 🔹 Logic:
- Iterate from 2 to n.
- For every `i`, check if it is a prime.
- If prime, divide `n` by `i` as long as it is divisible.

#### 🔸 Drawbacks:
- Time-consuming due to repeated primality checks.
- Not optimal for large `n`.

#### 💻 Code (C++):

```cpp
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void naivePrimeFactors(int n) {
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
    }
}
```

---

### 🟢 2. Optimized Approach – O(√n)

#### 🔹 Logic:
- Remove all factors of 2 and 3.
- For remaining primes, iterate from 5 to √n in steps of 6:
  - Check `i` and `i+2` as possible factors (since primes > 3 are of form 6k ± 1).

#### 🔸 Benefits:
- Skips unnecessary divisions.
- Efficient for large numbers.

#### 💻 Code (C++):

```cpp
#include <iostream>
using namespace std;

void primeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    while (n % 3 == 0) {
        cout << 3 << " ";
        n /= 3;
    }

    for (int i = 5; i * i <= n; i += 6) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
        while (n % (i + 2) == 0) {
            cout << (i + 2) << " ";
            n /= (i + 2);
        }
    }

    if (n > 3)
        cout << n << " ";
}
```

---

## ⏱️ Time & Space Complexity

| Approach         | Time Complexity | Space Complexity | Notes                     |
|------------------|------------------|------------------|---------------------------|
| Naive (Trial Div) | O(n√n)           | O(1)              | Repeated primality tests |
| Optimized         | O(√n)            | O(1)              | Efficient, recommended   |

---

## 🧪 Test Cases

| Input | Output      |
|-------|-------------|
| 1     |             |
| 2     | 2           |
| 36    | 2 2 3 3     |
| 97    | 97          |
| 100   | 2 2 5 5     |

---

## 📚 Reference

- [Take U Forward - Prime Factorization](https://takeuforward.org/data-structure/print-all-prime-factors-of-the-given-number/)

---

## 🚀 Enhancements

- Add return-type based versions (e.g., returning `vector<int>`).
- Support for negative integers or zero.
- Count occurrences (frequencies) of each factor.
