#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;

    Node()
    {
        data = '\0';
        prev = nullptr;
        next = nullptr;
    }

    Node(int data, Node *prev = nullptr, Node *next = NULL)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    // Node(int data)
    // {
    //     this->data = data;
    //     this->prev = this->next = nullptr;
    // }
};

class DLL
{
public:
    struct Node *head, *tail;
    int size;

    DLL()
    {
        head = tail = nullptr;
        size = 0;
    }

    DLL(Node *head)
    {
        this->head = head;
        this->tail = head;
        size = 1;
    }

    void insertNode(int data);
    void insertNode(int data, int pos);
    void length();
    void printDLLReverse();
    bool searchValue(int data);
    void deleteNode_hit(Node *addr);
    void deleteNode(Node *adr) void deleteNode(int pos);
};

void DLL::insertNode(int data)
{
    Node *newNode = new Node(data);
    size++;
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void DLL::length()
{
    cout << size;
}

void DLL::printDLLReverse()
{
    Node *temp = tail;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";

    // Node temp = *tail;
    // while (temp.prev)
    // {
    //     cout << temp.data << "\t";
    //     temp = *(temp.prev);
    // }
    // cout << temp.data << "\n";
}

void DLL::deleteNode_hit(Node *adr)
{
    // if(head==NULL){
    //     cout << "dll is empty." << endl;
    //     return;
    // }
    if (!adr)
    {
        cout << "Invalid address.\n";
    }
    if (size == 1 && adr == head)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    if (adr == head)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
    }
    Node *temp = adr->prev;
    // while (temp->next != adr)
    // {
    //     temp = temp->next;
    // }
    Node *t2 = temp->next;
    temp->next = t2->next;
    if (t2->next->prev)
    {
        t2->next->prev = temp;
    }
    delete t2;
}

void DLL::deleteNode(Node *addr)
{
    if (!addr)
    {
        cout << "wrong\n";
    }
    if (addr->next)
    {
        addr->next->prev = addr->prev;
    }
    if (addr->prev)
    {
        addr->prev->next = addr->next;
    }
    delete addr;
    size--;
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

bool DLL::searchValue(int val)
{
    // Node* temp = head;
    // while(temp){
    //     if(temp->data == val){
    //         return true;
    //     }
    //     temp = temp->next;
    // }
    // return false;

    Node *left = head, *right = tail;
    while (left != right)
    {
        if (left->data == val || right->data == val)
        {
            return true;
        }
        left = left->next;
        right = right->prev;
    }
    return false;
}

void playing_with_Dll()
{
    Node *head = new Node(1);
    DLL dll1(head);
    // cout << dll1.head->data << "\n";
    // cout << dll1.head->prev << "\n";
    // cout << dll1.head->next << "\n";
    // cout << dll1.tail->data << "\t" << dll1.tail->prev << "\t" << dll1.tail->next->data << "\n";
    forn(i, 5)
    {
        dll1.insertNode(i + 2);
        // cout << dll1.head->next->data << "\n";
        // cout << dll1.head->next->prev->data << "\n";
        // cout << dll1.head->next->next << "\n";
        // forn(j, i + 1)
        // {
        //     //
        // }
        //     cout << dll1.head->data << "\t" << dll1.head->prev << "\t" << dll1.head->next->data << "\n";
        //     cout << dll1.tail->data << "\t" << dll1.tail->prev << "\t" << dll1.tail->next->data << "\n";
    }
    // dll1.printDLLReverse();
    cout << dll1.searchValue(3) << "\n";
    cout << dll1.searchValue(7) << '\n';
    // cout << dll1.tail->data << "\n";       // 5
    // cout << dll1.tail->next << "\n";       // null
    // cout << dll1.tail->prev->data << "\n"; // 4
    // cout << dll1.head->next->data << "\n"; // 2
    // cout << dll1.head->data << "\n";       // null
}

void solve()
{
    playing_with_Dll();
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