# Arrays and Vectors: Time Complexity and Operations

## Array

### Time Complexity:

* **Insert**: O(1)
* **Remove**: O(1)
* **Update**: O(1)
* **Pushing**: O(n)
* **Pop**: O(n)

### Pushing:

**Steps:**

1. Reserve `n+1` slots in memory → O(1)
2. Copy `n` elements → O(n)
3. Insert `n+1`th element → O(1)

**Overall Complexity:** `O(n+2)` → **O(n)**

### Popping:

**Steps:**

1. Reserve `n-1` slots in memory → O(1)
2. Copy `n-1` elements → O(n)

**Overall Complexity:** `O(n+1)` → **O(n)**

---

## Vector

### Time Complexity:

* **Insert**: O(1)
* **Remove**: O(1)
* **Update**: O(1)
* **Pushing**: O(1)
* **Pop**: O(1)

### Amortization:

Vectors are internally implemented using arrays. When a vector is filled with `n` elements and an `n+1`th element is added:

* A new array of size `2n` is allocated
* The original `n` elements are copied into it → O(n)
* `n+1`th element is added → O(1)

For the next `n-1` additions, each insertion is O(1). Hence, on average, the **amortized complexity** for `push_back` is **O(1)**.

---

## Vector Declaration:

* `vector<int> v;` → Calls default constructor of the vector class for object `v`
* `vector<int> v(n);` → Calls parameterized constructor with size `n`
* `vector<int> v(n, 0);` → Calls parameterized constructor with size `n` and initial values as 0

### Utility:

* `v.size()` → Returns size of vector `v`

---

## Segmentation Fault:

Occurs when there is a memory read/write on an unallocated memory space.

---

## Vector Functions:

* `v.push_back` → Performs push operation for vectors
* `v.pop_back` → Performs pop operation for vectors (correct function name is `pop_back` not `pop`)

---

## TODO:

* Max element of array and vectors
* Max element of array and vectors using functional/modular programming
* Reverse a vector 

  * **Modules:**

    * Input
    * Output
    * Logic



