#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<int, vi> mivi;
typedef map<int, mii> mimii;
typedef pair<int, int> pii;
typedef pair<int, vvi> pivvi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

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

void print_vvb(vvb &adj_matrix)
{
    for (vb &row : adj_matrix)
    {
        for (bool val : row)
        {
            cout << val << "\t";
        }
        cout << "\n";
    }
}

void print_vvi(vvi &adj_matrix)
{
    for (vi &v : adj_matrix)
    {
        print_vec(v);
    }
}

pivvi make_graph()
{
    int v = 7; // vertex set complete
    // vs vertices({"MU", })
    vvi edges({{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 5}, {3, 4}, {6, 6}});
    vvi edges_weighted({{0, 1, 2}, {0, 2, 3}, {0, 3, 5}, {1, 4, 7}, {1, 5, 11}, {2, 5, 17}, {3, 4, 23}, {6, 6, 13}});
    pair<int, vvi> graph(make_pair(v, edges));
    pair<int, vvi> graph_weighted(v, edges_weighted);
    return graph_weighted;
}

vvb get_adj_matrix_undirected(pivvi &graph)
{
    // undirected
    int v = graph.first;
    vvb adj_matrix(v, vb(v, false));
    vvi edges = graph.second;
    for (vi &edge : edges)
    {
        adj_matrix[edge[0]][edge[1]] = true;
        adj_matrix[edge[1]][edge[0]] = true;
    }
    return adj_matrix;
}

vvb get_adj_matrix_directed(pivvi &graph)
{
    // undirected
    int v = graph.first;
    vvb adj_matrix(v, vb(v, false));
    vvi edges = graph.second;
    for (vi &edge : edges)
    {
        adj_matrix[edge[0]][edge[1]] = true;
        // adj_matrix[edge[1]][edge[0]] = true;
    }
    return adj_matrix;
}

vvi get_adj_matrix_ud_w(pivvi &graph)
{
    int v = graph.first;
    vvi edges = graph.second;

    vvi adj_matrix(v, vi(v, 0));
    for (vi &edge : edges)
    {
        adj_matrix[edge[0]][edge[1]] = edge[2];
        adj_matrix[edge[1]][edge[0]] = edge[2];
    }
    return adj_matrix;
}

mivi get_adj_list(pivvi &graph)
{
    //
}

mimii get_adj_list_weighted(pivvi &graph_weighted)
{
    // convert all map to unordered_map
}

void solve()
{
    pivvi graph = make_graph();
    vvb adj_matrix = get_adj_matrix_directed(graph);
    print_vvb(adj_matrix);

    // pivvi graph_weighted = make_graph();
    // vvi adj_matrix = get_adj_matrix_ud_w(graph_weighted);
    // print_vvi(adj_matrix);
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