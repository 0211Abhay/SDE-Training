#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

struct Node
{
    // public:
    int data;
    Node *next;
    Node()
    {
        this->data = '\0';
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = nullptr;
    }
    LinkedList(Node *head)
    {
        this->head = head;
    }

    void insert(int val); // inserts at Tail
    void insertHead(int val);
    void deleteNode(int pos);
    void deleteNode(Node *addr);
    void print();
    bool search(int target);
    int size();
    bool empty();
};

bool LinkedList::empty()
{
    return (head == NULL);
}
void LinkedList::insert(int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

void LinkedList::insertHead(int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

bool LinkedList::search(int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

int LinkedList::size()
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void LinkedList::deleteNode(int pos)
{
    if (head == NULL)
    {
        cout << "Can't delete, list is empty.\n";
        return;
    }
    int length = size();
    if (pos < 1 || pos > length)
    {
        cout << "index out of bound.\n";
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *curr = head;
    while (pos > 2 && curr->next != NULL)
    {
        pos--;
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

void playing_with_structs()
{
    Node obj;
}

Node *playing_with_nodes()
{
    Node *five = new Node(5);
    Node *four = new Node(4, five);
    Node *three = new Node(3, four);
    Node *second = new Node(2, three);
    Node *head = new Node(1, second);
    return head;
}

void test_delete(LinkedList &list1)
{
    list1.deleteNode(1); // 2 3 4 5
    list1.print();
    list1.deleteNode(5); // Index out of bound
    list1.deleteNode(4); // 2 3 4
    list1.print();
    list1.deleteNode(2); // 2 4
    list1.print();
}

void test_search(LinkedList &list1)
{
    int val;
    cin >> val;
    cout << list1.search(val) << "\n";
}

void test_insertion()
{
    LinkedList list1;
    for (int i = 1; i <= 3; i++)
    {
        list1.insert(i);
    }
    list1.print();
    cout << list1.size() << "\n";
    list1.print();
}

void test_insertHead(LinkedList &list1)
{
    list1.insertHead(6);
    list1.print();
}

void solve()
{
    Node *head = playing_with_nodes();
    LinkedList list1(head);
    // test_search(list1);
    // test_delete(list1);
    // test_insertion();
    test_insertHead(list1);
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}