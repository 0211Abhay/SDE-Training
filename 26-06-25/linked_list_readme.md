# 📘 Linked List - Complete Guide with Code

A **Linked List** is a dynamic data structure where each element is called a node and contains two parts:

- **Data**
- **Pointer to next node**

---

## 🧱 Structure of a Node

### Using Struct:

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
```

### Using Class:

```cpp
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
```

---

## 🔧 Basic Operations (Struct Based)

### Create Linked List

```cpp
Node* head = nullptr;
```

### Insert at Beginning

```cpp
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
```

### Insert at End

```cpp
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}
```

### Insert at Position

```cpp
void insertAtPosition(Node*& head, int pos, int value) {
    if (pos == 0) {
        insertAtBeginning(head, value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp) return; // position out of range
    newNode->next = temp->next;
    temp->next = newNode;
}
```

### Delete from Beginning

```cpp
void deleteFromBeginning(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
```

### Delete from End

```cpp
void deleteFromEnd(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}
```

### Delete at Position

```cpp
void deleteAtPosition(Node*& head, int pos) {
    if (!head) return;
    if (pos == 0) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp->next && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp->next) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
```

### Search a Value

```cpp
bool search(Node* head, int key) {
    while (head) {
        if (head->data == key) return true;
        head = head->next;
    }
    return false;
}
```

### Print Linked List

```cpp
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}
```

### Reverse a Linked List

```cpp
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```

---

## 🎯 Class-Based Implementation

```cpp
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int pos, int val);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteAtPosition(int pos);
    bool search(int key);
    void printList();
    void reverse();
};

void LinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void LinkedList::insertAtPosition(int pos, int val) {
    if (pos == 0) return insertAtBeginning(val);
    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) return;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::deleteFromBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::deleteAtPosition(int pos) {
    if (pos == 0) return deleteFromBeginning();
    Node* temp = head;
    for (int i = 0; temp && temp->next && i < pos - 1; i++) temp = temp->next;
    if (!temp || !temp->next) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

bool LinkedList::search(int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
```

---

## 📌 Summary Table

| Operation   | Time Complexity |
| ----------- | --------------- |
| Insert Head | O(1)            |
| Insert Tail | O(n)            |
| Delete Head | O(1)            |
| Delete Tail | O(n)            |
| Search      | O(n)            |
| Traverse    | O(n)            |
| Reverse     | O(n)            |

---

Let me know if you want the class extended to a doubly or circular linked list version as well.

