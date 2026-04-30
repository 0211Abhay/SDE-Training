#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<vector<int>> vvi;

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
pair<int,vvi> make_graph(){
    int v = 7;
    vvi edges = {{0,1},{0,2},{0,3},{1,4},{1,5},{2,5},{3,4},{6,6}};
    pair<int,vvi> Graph = make_pair(v,edges);
    return Graph;
}
void print_vec(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
vector<vector<bool>> get_adj_matrix(pair<int,vvi> &graph){
    int n = graph.first;
    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));

    for(auto &edge: graph.second){
        adj_matrix[edge[0]][edge[1]] = true;
        // If undirected:
        adj_matrix[edge[1]][edge[0]] = true;
    }
    return adj_matrix;
}

void  print_adj_matrix(vector<vector<bool>> &adj_matrix){
    for(auto x: adj_matrix){
        for(auto y: x){
            cout << y << "\t";
        }
        cout << "\n";
    }
}

void solve()
{
    pair<int,vvi> graph = make_graph();
    vector<vector<bool>> adj_matrix = get_adj_matrix(graph);
    print_adj_matrix(adj_matrix);
    // code here
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