# 📘 Doubly Linked List - Complete Guide with Code

A **Doubly Linked List (DLL)** is a type of linked list in which each node contains three parts:

- **Data**
- **Pointer to next node**
- **Pointer to previous node**

This allows traversal in both directions.

---

## 🧱 Structure of a Node

### Using Struct:

```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
```

### Using Class:

```cpp
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
```

---

## 🔧 Basic Operations (Struct Based)

### Create Doubly Linked List

```cpp
Node* head = nullptr;
```

### Insert at Beginning

```cpp
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    if (head) head->prev = newNode;
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
    newNode->prev = temp;
}
```

### Insert at Position

```cpp
void insertAtPosition(Node*& head, int pos, int value) {
    if (pos == 0) {
        insertAtBeginning(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) return;
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}
```

### Delete from Beginning

```cpp
void deleteFromBeginning(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
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
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
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
    for (int i = 0; temp && i < pos; i++) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
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

### Print List Forward

```cpp
void printForward(Node* head) {
    while (head) {
        std::cout << head->data << " <-> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}
```

### Print List Backward

```cpp
void printBackward(Node* tail) {
    while (tail) {
        std::cout << tail->data << " <-> ";
        tail = tail->prev;
    }
    std::cout << "NULL\n";
}
```

---

## 🎯 Class-Based Implementation

```cpp
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int pos, int val);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteAtPosition(int pos);
    bool search(int key);
    void printForward();
    void printBackward();
};

void DoublyLinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void DoublyLinkedList::insertAtPosition(int pos, int val) {
    if (pos == 0) return insertAtBeginning(val);
    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) return;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void DoublyLinkedList::deleteFromBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

void DoublyLinkedList::deleteFromEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void DoublyLinkedList::deleteAtPosition(int pos) {
    if (pos == 0) return deleteFromBeginning();
    Node* temp = head;
    for (int i = 0; temp && i < pos; i++) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

bool DoublyLinkedList::search(int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

void DoublyLinkedList::printForward() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

void DoublyLinkedList::printBackward() {
    Node* temp = head;
    if (!temp) return;
    while (temp->next) temp = temp->next;
    while (temp) {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    std::cout << "NULL\n";
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

---

Let me know if you want to extend this to Circular Doubly Linked List or convert into a downloadable `.md` or `.pdf` file.

