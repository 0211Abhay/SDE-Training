#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forLL(temp) for (Node *temp = head; temp; temp = temp->next)
#define pb push_back

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        //
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

    // copy constructor
    // Node(Node &obj_ptr)
    // {
    //     // this->data = obj->data;
    //     // this->a = obj->a;
    //     // this->b = obj->b;
    //     this = obj_ptr;
    // }

    // Node(int data)
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = NULL;
    }
    LinkedList(Node *head)
    {
        this->head = head;
    }

    void insertNode(int data); // 4
    int length();
    void insertNode(int pos, int data);
    void insertNodeHead(int data);
    void deleteNode(int pos);    // 5
    void deleteNode(Node *node); // 3
    bool searchValue(int val);   // 2
    void printList();            // 1
};

int LinkedList::length()
{
    int __length = 0;
    forLL(curr)
    {
        __length++;
    }
    return __length;
}

void LinkedList::printList()
{
    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     cout << temp->data << "\t";
    //     temp = temp->next;
    // }
    forLL(temp)
    {
        cout << temp->data << "\t";
    }
    cout << "\n";
}

void LinkedList::insertNodeHead(int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void LinkedList::insertNode(int data)
{
    Node *obj = new Node(data);
    if (!head)
    {
        head = obj;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = obj;
}

bool LinkedList::searchValue(int val)
{
    // Node *temp = head;
    // while (temp)
    // {
    // if (temp->data == val)
    // {
    //     return true;
    // }
    // temp = temp->next;
    // }
    // for (Node *temp = head; temp; temp = temp->next)
    forLL(temp)
    {
        if (temp->data == val)
        {
            return true;
        }
    }
    return false;
}

void LinkedList::deleteNode(int pos)
{
    int l = length();
    if (pos < 0 || pos > l)
    {
        cout << "Invalid Index.\n";
    }
    if (!head)
    {
        if (pos)
        {
            cout << "The list is empty.\n";
        }
        return;
    }

    // delete head node
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    while (temp && pos-- > 2)
    {
        temp = temp->next;
    }
    Node *dummy = temp->next;
    temp->next = dummy->next;
    delete dummy;
}

vi input_vector()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void playing_at_compile_time()
{
    Node node1;
    Node node2(2);
    node1.next = &node2;
    cout << node1.data << "\t" << node1.next->data << "\n";
}

Node *playing_with_nodes()
{
    // Node *obj1 = new Node(1);
    Node *node5 = new Node(5);
    Node *node4 = new Node(4, node5);
    Node *node3 = new Node(3, node4);
    Node *node2 = new Node(2, node3);
    Node *head = new Node(1, node2);
    // obj1->next = obj2;
    // cout << (*node1).data << '\t' << node1->next->data << "\n";
    return head;
}

void ll_via_nodes()
{
    Node *head = playing_with_nodes();
    LinkedList *ll = new LinkedList(head);
    ll->printList();
}

void populate_ll(LinkedList &ll)
{
    forn(i, 5)
    {
        ll.insertNode(i + 1);
    }
    ll.insertNodeHead(6);
}

int length(LinkedList &ll)
{
    int __length = 0;
    Node *head = ll.head;
    forLL(curr)
    {
        __length++;
    }
    return __length;
}

void playing_with_ll()
{
    LinkedList ll;
    populate_ll(ll);
    ll.deleteNode(4); // 6 1 2 4 5
    ll.printList();
    ll.deleteNode(6); // error
    ll.printList();
    ll.deleteNode(0); // error
    ll.deleteNode(1); // 1 2 4 5
    ll.printList();
    ll.deleteNode(3); // 1 2 5
    ll.printList();
    // cout << ll.length() << "\n";
    // cout << length(ll) << "\n";
    // cout << ll.searchValue(4) << "\n";
    // cout << ll.searchValue(7) << "\n";
    // ll.printList();
}

void reverse_linked_list(Node *&head)
{
    if (!head || !head->next)
    {
        return;
    }
    Node *prev = head, *curr = head->next;
    Node *after = curr->next;
    head->next = nullptr;
    while (curr)
    {
        curr->next = prev;
        prev = curr;
        curr = after;
        if (after != nullptr)
        {
            after = after->next;
        }
    }
    head = prev;
}

void solve()
{
    // playing_with_nodes();
    // ll_via_nodes();
    // playing_with_ll();
    // playing_at_compile_time();
    // int a = 1;
    // a++;
    // play();
    // int a = new Inte();

    Node *head = playing_with_nodes();
    LinkedList ll(head);
    ll.printList();
    reverse_linked_list(head);
    LinkedList ll2(head);
    ll2.printList();
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