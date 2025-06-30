#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val = 0) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;
    int size;

    DLL() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insertNode(int data);
    void insertNode(int data, int pos);
    int length();
    void printDLL();
    bool searchValue(int val);
    void deleteNode(Node* addr);
    void deleteNode(int pos);
};

// Insert node at end
void DLL::insertNode(int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DLL::printDLL() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int DLL::length() {
    return size;
}

bool DLL::searchValue(int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

void DLL::deleteNode(Node* addr) {
    if (!addr) return;
    if (addr == head) {
        head = head->next;
        if (head) head->prev = nullptr;
    } else if (addr == tail) {
        tail = tail->prev;
        if (tail) tail->next = nullptr;
    } else {
        addr->prev->next = addr->next;
        addr->next->prev = addr->prev;
    }
    delete addr;
    size--;
}

void DLL::deleteNode(int pos) {
    if (pos < 0 || pos >= size) return;
    Node* temp = head;
    while (pos--) temp = temp->next;
    deleteNode(temp);
}

vi input_vector() {
    int n;
    cin >> n;
    vi v(n);
    forn(i, n) {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi& v) {
    forn(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

// void solve() {
//     DLL dll;
//     vi vals = input_vector();
//     for (int x : vals) dll.insertNode(x);

//     dll.printDLL();
//     cout << "Length: " << dll.length() << "\n";

//     int toSearch;
//     cin >> toSearch;
//     cout << (dll.searchValue(toSearch) ? "Found\n" : "Not Found\n");

//     int data;
//     cin >> data;
//     dll.deleteNode(3);

//     dll.printDLL();
// }
void solve() {
    DLL dll;
    vi vals = input_vector(); // e.g. input: 5 10 20 30 40 50

    Node* targetNode = nullptr; // we’ll store the pointer to the 3rd node (index 2)

    int indexToTrack = 2; // let's delete the 3rd node (0-based index)
    int curIndex = 0;

    for (int x : vals) {
        dll.insertNode(x);
        if (curIndex == indexToTrack) {
            targetNode = dll.tail; // since insertNode adds at end
        }
        curIndex++;
    }

    cout << "Original DLL:\n";
    dll.printDLL();

    if (targetNode) {
        cout << "Deleting node with value: " << targetNode->data << "\n";
        dll.deleteNode(targetNode);
    }

    cout << "DLL after deleting by address:\n";
    dll.printDLL();

    cout << "Length: " << dll.length() << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
