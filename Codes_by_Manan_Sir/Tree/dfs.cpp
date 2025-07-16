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

void print_inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << "\t";
    print_inorder(root->right);
}

void print_anyorder(Node *root, string order_type)
{
    if (!root)
    {
        return;
    }
    if (order_type == "pre")
    {
        cout << root->data << "\t";
    }
    print_anyorder(root->left, order_type);
    if (order_type == "in")
    {
        cout << root->data << "\t";
    }
    print_anyorder(root->right, order_type);
    if (order_type == "post")
    {
        cout << root->data << "\t";
    }
}

void solve()
{
    Node *root = dummy_tree();
    // cout << root->data << "\t" << root->left->data << "\t" << root->right->data << "\n";
    // print_inorder(root);
    print_anyorder(root, "pre");
    cout << "\n";
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