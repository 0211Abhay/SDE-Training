#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
    Node(int data, Node* next) : data(data), next(next) {}

    
};

vi input_vector() {
    int n;
    cin >> n;
    vi v(n);
    forn(i, n) {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi &v) {
    forn(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void Runtime() {
    Node* newNode = new Node();
    Node* newNode2 = new Node();

    newNode->data = 5;
    newNode->next = newNode2;
    newNode2->data = 6;

    cout << newNode->data << " " << newNode->next->data << endl;
}

class LinkedList {
    Node *head;

public:
    LinkedList() : head(NULL) {}
    LinkedList(Node* head) {
        this->head = head;
    }

    void insertNode(int data);
    void insertNode(int data, int pos);
    void deleteNode(int pos);
    void deleteNode(Node* node);
    bool searchValue(int val);
    void printList();
};

void LinkedList::insertNode(int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::insertNode(int data, int pos) {
    Node* newNode = new Node(data);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp) return; // invalid position
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::deleteNode(int pos) {
    if (!head) return;
    if (pos == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node* temp = head;
    for (int i = 0; temp->next != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp->next) return; // invalid position
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void LinkedList::deleteNode(Node* node) {
    if (!head || !node) return;
    if (head == node) {
        head = head->next;
        delete node;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next != node) {
        temp = temp->next;
    }
    if (temp->next == node) {
        temp->next = node->next;
        delete node;
    }
}

bool LinkedList::searchValue(int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void CompileTime() {
    Node node2(2);
    Node node1(1);

    node1.next = &node2;

    cout << node1.data << " " << node1.next->data << endl;
}

void solve() {
    // CompileTime();
    // Runtime();

    LinkedList ll;
    ll.insertNode(10);
    ll.insertNode(20);
    ll.insertNode(30);
    ll.insertNode(25, 2);
    ll.deleteNode(1);
    ll.printList();
    cout << (ll.searchValue(25) ? "Found" : "Not Found") << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
