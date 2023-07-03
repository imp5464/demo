#include<bits/stdc++.h>
using namespace std ;
int n ;
vector<vector<int>> g ;
int partial[100010] ;
int par[100010][25] ;
int depth[100010] ;
int lca(int u, int v) // largest common ancestor
{
    if(depth[u]<depth[v])
        swap(u,v) ;
    for(int i=20;i>=0;i--)
    {
        if(((depth[u]-depth[v])&(1<<i)))
        {
            u= par[u][i] ;
        }
    }
    if(u==v)
        return u ;
    for(int i=20;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            u = par[u][i] ;
            v= par[u][i] ;
        }
    }
    return par[u][0] ;
}
void dfs2(int node, int prev, int dep)
{
    depth[node]= dep ;
    par[node][0] = prev ;
    for(int i=1;i<=20;i++)
        par[node][i] = par[par[node][i-1]][i-1] ;
    for(auto v:g[node])
    {
        if(v!=prev)
            dfs2(v,node,dep+1) ;
    }
}
void dfs(int node, int parent)
{
    for(auto v:g[node])
    {
        if(v!=parent)
            dfs(v,node) ;
    }
    partial[par[node][0]] += partial[node] ;
}
void add(int x, int y, int z)
{
    partial[x]+= z ;
    partial[y]+= z ;
    int lc = lca(x,y) ;
    partial[lc]-= z ;
    partial[par[lc][0]]-=z ;
}
void solve()
{
    cin>>n ;
    g.clear() ;
    g.resize(n+1) ;
    memset(partial,0,sizeof(partial)) ;
    memset(par,0,sizeof(par)) ;
    memset(depth,0,sizeof(depth)) ;
    g[1].push_back(0) ;
    g[0].push_back(1) ;
   for(int i=0;i<n-1;i++)
    {
        int u,v ;
        cin>>u>>v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    
    int q ;
    cin>>q ;
    dfs2(1,0,0) ;
    
    while(q--)
    {
        int x,y,z ;
        cin>>x>>y>>z ;
        add(x,y,z) ;
    }
    dfs(1,0) ;
    for(int i=1;i<=n;i++)
        cout<<partial[i]<<" " ;
    cout<<endl ;
    
}
signed main()
{
    int t ;
    cin>>t ;
    while(t--)
    {
        solve() ;        
    }
}