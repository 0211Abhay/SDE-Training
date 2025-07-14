
# 📚 Monotonic Stack

A **Monotonic Stack** is a variant of the stack data structure that maintains its elements in either increasing or decreasing order.  
It is commonly used to solve problems that involve finding **next greater / smaller elements** or **previous greater / smaller elements** in an array in linear time (`O(n)`).

---

## ✨ Why Monotonic Stack?

✅ Efficient (`O(n)`) for problems that otherwise look like nested loops (`O(n²)`).  
✅ Works well with problems involving ranges, maximums, or minimums in sliding windows.  
✅ Easy to implement and widely used in competitive programming & interviews.

---

## 🧾 Problems Solved by Monotonic Stack

- Next Greater Element
- Next Smaller Element
- Largest Rectangle in Histogram
- Trapping Rain Water
- Daily Temperatures
- Minimum Additions to Make Parentheses Valid

---

## 🧰 Types of Monotonic Stack

| Type               | Order Maintained |
|--------------------|------------------|
| **Monotone Increasing Stack**  | Elements are in **increasing order** (bottom → top). Useful for finding **next smaller elements**. |
| **Monotone Decreasing Stack**  | Elements are in **decreasing order** (bottom → top). Useful for finding **next greater elements**. |

---

## 🔗 API / Typical Pattern

### Next Greater Element Example (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> stk;  // decreasing monotonic stack

    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && nums[i] > nums[stk.top()]) {
            res[stk.top()] = nums[i];
            stk.pop();
        }
        stk.push(i);
    }

    return res;
}
```

---

## 🚀 Complexity

| Operation          | Time Complexity |
|--------------------|-----------------|
| Building the stack | `O(n)` |
| Each element pushed/popped at most once | `O(1)` per op |
| Total              | `O(n)` |

---

## 📝 Key Insights

- Every element is pushed and popped at most once → `O(n)` overall.
- Use **indices** in the stack instead of values if you also need positions.
- Choose stack type (incr/decr) depending on whether you’re solving for *greater* or *smaller*.

---

## 📖 References

- [LeetCode: Next Greater Element](https://leetcode.com/problems/next-greater-element-i/)
- [LeetCode: Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
- [Competitive Programming Handbook](https://cses.fi/book/)

---

## 👨‍💻 Author

*This README was generated with ❤️ by [ChatGPT](https://openai.com/).*
