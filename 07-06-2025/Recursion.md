# 📘 Understanding Recursion in Programming

## 🧠 What is Recursion?
Recursion is a programming technique where a function **calls itself** to solve smaller instances of a problem, until it reaches a **base condition** that stops the recursion.

## 📌 When to Use Recursion
- Factorial calculation
- Fibonacci series
- Tree traversal
- Backtracking problems
- Divide and conquer algorithms (e.g., Merge Sort, Quick Sort)

## 🧩 Components of a Recursive Function
1. **Base Case**: Stops the recursion.
2. **Recursive Case**: Function calls itself with simpler input.

## 🔁 How Recursion Works (Step by Step)
**Example: Factorial(n)**
```javascript
function factorial(n) {
  if (n === 0) return 1;         // Base case
  return n * factorial(n - 1);   // Recursive case
}
```

### Step-by-Step for `factorial(3)`
1. `factorial(3)`
2. -> `3 * factorial(2)`
3. -> `3 * (2 * factorial(1))`
4. -> `3 * (2 * (1 * factorial(0)))`
5. -> `3 * (2 * (1 * 1))`  <- Base case hit!
6. -> `3 * (2 * 1)`
7. -> `3 * 2`
8. -> `6`

## 🧠 Memory and Stack Behavior
Each recursive call goes on the **call stack**. Once the base case is hit, calls resolve in **LIFO (Last In, First Out)** order.

## ⚠️ Common Mistakes
- ❌ Missing base case → infinite loop
- ❌ No simplification
- ❌ Incorrect recursion logic

## ✅ Recursion vs Iteration
| Feature        | Recursion                   | Iteration                    |
|----------------|-----------------------------|------------------------------|
| Style          | Elegant and concise          | Usually more verbose         |
| Performance    | Higher memory usage (call stack) | Better memory efficiency     |
| Use Case       | Natural for tree/graph problems | Good for loops and counters  |

## 📘 Examples in Different Languages
### JavaScript - Fibonacci
```javascript
function fib(n) {
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}
```

### Python - Sum of List
```python
def sum_list(lst):
    if not lst:
        return 0
    return lst[0] + sum_list(lst[1:])
```

### Java - Factorial
```java
int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
```

## 🧠 Tips for Mastering Recursion
1. Identify the **base case** first.
2. Simplify the input.
3. Visualize the **call stack**.
4. Use **helper functions** if needed.
5. Trace manually or debug step by step.

## 🧪 Practice Problems
- Factorial
- Fibonacci
- Reverse a string
- Palindrome check
- Recursive binary search
- DFS on tree/graph

## 📚 Resources
- [Visualgo.net](https://visualgo.net/en/recursion)
- [GeeksforGeeks - Recursion](https://www.geeksforgeeks.org/recursion/)
- [Khan Academy - Recursion](https://www.khanacademy.org/computing/computer-science/algorithms/recursive-algorithms)

## 🏁 Conclusion
Recursion is a powerful tool. Understand the structure, visualize the call stack, and practice often!
