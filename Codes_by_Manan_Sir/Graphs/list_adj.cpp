#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef unordered_map<int, int> mii;
typedef unordered_map<int, vi> mivi;
typedef pair<int, vi> pivi;
typedef unordered_map<int, mii> mimii;
typedef pair<int, mii> pimii;
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

void print_mivi(mivi &adj_list)
{
    for (pivi row : adj_list)
    {
        cout << row.first << ": ";
        print_vec(row.second);
    }
}

void print_mimii(mimii &adj_list)
{
    for (const pimii &row : adj_list)
    {
        cout << row.first << "->";
        for (const pii &col : row.second)
        {
            cout << "(" << col.first << "," << col.second << "), ";
        }
        cout << "\n";
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

mivi get_adj_list_uw_ud(pivvi &graph)
{
    // undirected
    int v = graph.first;
    vvi &edges = graph.second;
    mivi adj_list;
    forn(i, v)
    {
        adj_list[i] = vi();
    }
    for (vi &edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
        if (edge[0] != edge[1])
        {
            adj_list[edge[1]].push_back(edge[0]);
        }
    }
    return adj_list;
}

mivi get_adj_list_uw_d(pivvi &graph)
{
    int v = graph.first;
    vvi &edges = graph.second;
    mivi adj_list;
    forn(i, v)
    {
        adj_list[i] = vi();
    }
    for (vi &edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
    }
    return adj_list;
}

mimii get_adj_list_w_ud(pivvi &graph)
{
    int v = graph.first;
    vvi &edges = graph.second;
    mimii adj_list;
    forn(i, v)
    {
        adj_list[i] = mii();
    }
    for (vi &edge : edges)
    {
        adj_list[edge[0]][edge[1]] = edge[2];
        adj_list[edge[1]][edge[0]] = edge[2];
    }
    return adj_list;
}

mimii get_adj_list_w_d(pivvi &graph)
{
    int v = graph.first;
    vvi &edges = graph.second;
    mimii adj_list;
    forn(i, v)
    {
        adj_list[i] = mii();
    }
    for (vi &edge : edges)
    {
        adj_list[edge[0]][edge[1]] = edge[2];
        // adj_list[edge[1]][edge[0]] = edge[2];
    }
    return adj_list;
}

void solve()
{
    pivvi graph = make_graph();
    mimii adj_list = get_adj_list_w_ud(graph);
    print_mimii(adj_list);

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