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

Node *playing_with_nodes()
{
    Node *five = new Node(5);
    Node *four = new Node(4, five);
    Node *three = new Node(3, four);
    Node *second = new Node(2, three);
    Node *head = new Node(1, second);
    return head;
}

void print_ll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

Node *reverse_linked_list(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = head, *curr = head->next;
    Node *after = curr->next;
    head->next = NULL;
    // cout << curr->data << "\n";
    while (curr != NULL)
    {
        // cout << prev->data << "\t" << curr->data << "\t" << after->data << "\n";
        curr->next = prev;
        prev = curr;
        curr = after;
        if (after != nullptr)
        {
            after = after->next;
        }
        // cout << curr->data << "\n";
        // if (prev->data == 4)
        // {
        //     print_ll(prev);
        // }
        // print_ll(prev);
    }
    // cout << prev->data << "\t" << curr << "\n";
    head = prev;
    // return prev;
}

void solve()
{
    Node *head = playing_with_nodes();
    print_ll(head);
    reverse_linked_list(head);
    print_ll(head);
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