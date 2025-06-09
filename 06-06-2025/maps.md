
# 🗺️ Maps in Programming

Maps (also known as dictionaries, hash tables, or associative arrays) are data structures that store data in key-value pairs.

---

## 🧠 Basic Concept

- **Key**: Unique identifier.
- **Value**: Data associated with the key.
- **Map**: A collection of key-value pairs.

---

## 📌 Common Operations

| Operation        | Description                     |
|------------------|---------------------------------|
| `insert(key, value)` | Add a key-value pair        |
| `get(key)`          | Retrieve value for key       |
| `delete(key)`       | Remove key-value pair        |
| `contains(key)`     | Check if key exists          |
| `size()`            | Number of key-value pairs    |

---

## 🌐 Types of Maps

### Java
| Type            | Description                          |
|------------------|--------------------------------------|
| `HashMap`        | Unordered, allows one null key       |
| `TreeMap`        | Sorted by keys (Red-Black Tree)      |
| `LinkedHashMap`  | Maintains insertion order            |

### C++
| Type              | Header              | Description               |
|-------------------|---------------------|---------------------------|
| `map`             | `<map>`             | Ordered, implemented via BST |
| `unordered_map`   | `<unordered_map>`   | Faster, uses hashing      |
| `multimap`        | `<map>`             | Allows duplicate keys     |

### Python
- `dict`: Built-in map type. Unordered until Python 3.6, insertion-ordered since 3.7.

---

## 🧪 Examples

### Java
```java
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("apple", 3);
        map.put("banana", 5);
        map.remove("banana");

        if (map.containsKey("apple")) {
            System.out.println("Apple Count: " + map.get("apple")); // Output: 3
        }

        for (String key : map.keySet()) {
            System.out.println(key + " => " + map.get(key));
        }
    }
}
```

---

### C++
```cpp
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    std::map<std::string, int> orderedMap;
    orderedMap["apple"] = 3;
    orderedMap["banana"] = 5;

    std::unordered_map<std::string, int> unorderedMap;
    unorderedMap["apple"] = 3;
    unorderedMap["banana"] = 5;

    std::cout << "Ordered Map:\n";
    for (auto &p : orderedMap) {
        std::cout << p.first << " => " << p.second << "\n";
    }

    std::cout << "Unordered Map:\n";
    for (auto &p : unorderedMap) {
        std::cout << p.first << " => " << p.second << "\n";
    }

    return 0;
}
```

---

### Python
```python
# Python 3.7+ dict maintains insertion order
map = {"apple": 3, "banana": 5}
map["cherry"] = 7
map.pop("banana")

if "apple" in map:
    print("Apple Count:", map["apple"])

for key, value in map.items():
    print(f"{key} => {value}")
```

---

## ⚖️ Time Complexity

| Operation     | Java `HashMap` / C++ `unordered_map` / Python `dict` | Java `TreeMap` / C++ `map` |
|----------------|------------------------------------------------------|-----------------------------|
| `insert`       | O(1) avg / O(n) worst                                | O(log n)                    |
| `get`          | O(1) avg / O(n) worst                                | O(log n)                    |
| `delete`       | O(1) avg / O(n) worst                                | O(log n)                    |
| `containsKey`  | O(1) avg / O(n) worst                                | O(log n)                    |
| `traverse`     | O(n)                                                 | O(n)                        |

> ℹ️ Unordered maps use hashing; worst-case can be O(n) if many hash collisions.

---

## 🧩 Use Cases

- Counting frequency of elements
- Caching systems
- Lookup tables (e.g., language translation, configuration files)
- Storing relationships (e.g., adjacency list in graphs)

---

## ✅ Tips

- In Java, always override `hashCode()` and `equals()` if you use custom objects as keys.
- Use `unordered_map` in C++ for fast access unless order is required.
- Python `dict` is efficient and should be used by default for key-value data.

---

> 📚 References:
> - Java Docs: HashMap, TreeMap
> - C++ STL: map, unordered_map
> - Python Docs: dict
