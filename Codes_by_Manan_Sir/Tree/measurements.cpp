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
    // root->right->left = new Node(6);
    root->right->right = new Node(7);
    // root->left->right->right = new Node(8);
    return root;
}

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 0;
    }
    int ltree_height = height(root->left);
    int rtree_height = height(root->right);
    return 1 + max(ltree_height, rtree_height);
}

int width(Node *root)
{
    int width = 0;
    if (!root)
    {
        return 0;
    }
    queue<Node *> nodes_queue;
    nodes_queue.push(root);
    while (!nodes_queue.empty())
    {
        int n = nodes_queue.size();
        width = max(width, n);
        forn(i, n)
        {
            // cout << nodes_queue.front()->data << "\t";
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
        // cout << "\n";
    }
    return width;
}

int diameter(Node *root)
{
    return 0;
}

void solve()
{
    Node *root = dummy_tree();
    // cout << root->data << "\t" << root->left->data << "\t" << root->right->data << "\n";
    cout << width(root) << "\n";
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