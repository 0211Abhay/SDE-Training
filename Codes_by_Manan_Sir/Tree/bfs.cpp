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
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
    }
};

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

Node *dummy_tree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

void print_levelorder(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> nodes_queue;
    nodes_queue.push(root);
    while (!nodes_queue.empty())
    {
        cout << nodes_queue.front()->data << "\t";
        if (nodes_queue.front()->left)
        {
            nodes_queue.push(nodes_queue.front()->left);
        }
        if (nodes_queue.front()->right)
        {
            nodes_queue.push(nodes_queue.front()->right);
        }
        nodes_queue.pop();
    }
    cout << "\n";
}

void print_levelWiseOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> nodes_queue;
    nodes_queue.push(root);
    while (!nodes_queue.empty())
    {
        int n = nodes_queue.size();
        forn(i, n)
        {
            cout << nodes_queue.front()->data << "\t";
            if (nodes_queue.front()->left)
            {
                nodes_queue.push(nodes_queue.front()->left);
            }
            if (nodes_queue.front()->right)
            {
                nodes_queue.push(nodes_queue.front()->right);
            }
            nodes_queue.pop();
        }
        cout << "\n";
    }
}

void solve()
{
    Node *root = dummy_tree();
    print_levelWiseOrder(root);
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