
# 🧱 Stack in C++ STL and Java Collections – In-Depth Guide

## 📖 Introduction

A **stack** is an abstract data type (ADT) that serves as a collection of elements, with **two principal operations**:

- `push`: Adds an element to the top of the stack.
- `pop`: Removes the element from the top of the stack.

It follows the **LIFO (Last-In First-Out)** model. Many real-world systems like browsers (back buttons), recursive function calls, and expression evaluation rely on stacks.

---

## 📘 C++ Stack (STL)

### 🔧 Header & Initialization

C++ stack is defined in the `<stack>` header and is built on top of other containers like `deque` or `vector`.

```cpp
#include <stack>
std::stack<int> stk;
```

You can also specify the underlying container:

```cpp
std::stack<int, std::vector<int>> vStack;
std::stack<int, std::deque<int>> dStack; // default
```

---

### ⚙️ Core Operations

| Operation      | Code            | Description                                | Time Complexity |
|----------------|-----------------|--------------------------------------------|------------------|
| `push(x)`      | `stk.push(10);` | Adds `x` to the top                         | O(1)              |
| `pop()`        | `stk.pop();`    | Removes the top element                    | O(1)              |
| `top()`        | `stk.top();`    | Returns a reference to the top element     | O(1)              |
| `empty()`      | `stk.empty();`  | Returns true if stack is empty             | O(1)              |
| `size()`       | `stk.size();`   | Returns number of elements in the stack    | O(1)              |

---

### 📌 Example

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> history;
    history.push("Home");
    history.push("About");
    history.push("Contact");

    while (!history.empty()) {
        cout << "Now at: " << history.top() << endl;
        history.pop();
    }

    return 0;
}
```

---

### 🧠 Behind the Scenes

- Internally, `std::stack` is an **adaptor** class. It uses another container (like `deque`) and provides LIFO access only.
- It **does not** allow iteration (no `.begin()`, `.end()`).
- If you need iterator access, use the underlying container directly.

---

## ☕ Java Stack (java.util.Stack)

### 🔧 Import & Initialization

```java
import java.util.Stack;
Stack<Integer> stk = new Stack<>();
```

---

### ⚙️ Core Operations

| Operation      | Code             | Description                               | Time Complexity |
|----------------|------------------|-------------------------------------------|------------------|
| `push(x)`      | `stk.push(10);`  | Adds x to top                             | O(1)              |
| `pop()`        | `stk.pop();`     | Removes top element                       | O(1)              |
| `peek()`       | `stk.peek();`    | Access top element without removing       | O(1)              |
| `isEmpty()`    | `stk.isEmpty();` | Checks if stack is empty                  | O(1)              |
| `size()`       | `stk.size();`    | Returns number of elements                | O(1)              |
| `search(x)`    | `stk.search(x);` | Returns 1-based position from top or -1   | O(n)              |

---

### 📌 Example

```java
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<String> tabs = new Stack<>();

        tabs.push("Google");
        tabs.push("YouTube");
        tabs.push("StackOverflow");

        while (!tabs.isEmpty()) {
            System.out.println("Current Tab: " + tabs.peek());
            tabs.pop();
        }
    }
}
```

---

### 🔒 Java Internals

- `java.util.Stack` **extends `Vector`**, meaning it's synchronized.
- This can be **inefficient in single-threaded contexts**.
- For better performance, use `Deque` via `ArrayDeque` (recommended):

```java
Deque<Integer> stack = new ArrayDeque<>();
stack.push(10); // same as addFirst
stack.pop();    // same as removeFirst
```

---

## 🧰 Real-World Applications

| Application                  | Use Case Description                                       |
|------------------------------|-------------------------------------------------------------|
| Browser History              | Tracks visited pages                                        |
| Undo Mechanism               | In editors and IDEs                                         |
| Expression Evaluation        | Postfix, Prefix parsing                                     |
| Parentheses Matching         | Balanced brackets check                                     |
| Call Stack                   | Tracks function call sequence                               |
| Depth-First Search (DFS)     | Algorithm for graph/tree traversal                          |

---

## 🔁 Custom Stack Implementation (Optional)

### In C++

```cpp
class Stack {
private:
    vector<int> data;

public:
    void push(int x) { data.push_back(x); }
    void pop() { if (!data.empty()) data.pop_back(); }
    int top() { return data.back(); }
    bool empty() { return data.empty(); }
    int size() { return data.size(); }
};
```

### In Java

```java
class MyStack {
    private ArrayList<Integer> data = new ArrayList<>();

    public void push(int x) { data.add(x); }
    public void pop() { if (!data.isEmpty()) data.remove(data.size() - 1); }
    public int top() { return data.get(data.size() - 1); }
    public boolean isEmpty() { return data.isEmpty(); }
    public int size() { return data.size(); }
}
```

---

## ⚠️ Edge Cases & Gotchas

- **Accessing top of an empty stack** → leads to **undefined behavior (C++)** or **EmptyStackException (Java)**.
- Avoid using `java.util.Stack` in high-performance code; prefer `ArrayDeque`.
- STL Stack **cannot be iterated**; you must copy its content to another container.

---

## 🚀 Performance Tips

- Use `reserve()` in C++ if you implement with `vector` to reduce reallocations.
- Use `ArrayDeque` in Java for faster non-synchronized stack.
- Avoid recursive stack overflow by manually managing stack in iterative DFS/BFS.

---

## 🏁 Summary

| Feature            | C++ STL Stack       | Java Stack               |
|--------------------|---------------------|--------------------------|
| Synchronization    | No                  | Yes                      |
| Iteration Support  | No                  | Yes                      |
| Performance        | High (Deque)        | Medium (Vector-based)    |
| Underlying Storage | `deque` (default)   | `Vector`                 |
| Customization      | High (via template) | Moderate (via inheritance) |

---

