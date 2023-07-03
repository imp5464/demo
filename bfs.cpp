#include<bits/stdc++.h>
using namespace std ;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pii>
#define vpl vector<pll>
#define F first
#define S second
#define fr(i,a,n) for(int i=a;i<n;i++)
#define frd(i,b,n) for(int i=n-1;i>=b;i--)

int n,m ;
vector<vector<int>> dist ;
vector<vector<pii>> par ;
vector<string> arr ;
int dx[] = {0,1,-1,0} ;
int dy[] = {1,0,0,-1} ;

bool check(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!='#')
    return 1 ;
    else
    return 0 ;
}
void bfs(pii strt)
{
    dist.clear() ;
    dist.assign(n,vector<int> (m,100)) ;
    par.assign(n,vector<pii>(m,make_pair(-1,-1))) ;
    dist[strt.F][strt.S] = 0 ;
    queue<pii> q ;
    q.push(strt) ;
    while(!q.empty())
    {
        pii curr = q.front() ;
        q.pop() ;
        int x = curr.F ;
        int y = curr.S ;
        for(int k=0;k<4;k++)
        {
         int nx = x+dx[k] ;
         int ny = y+dy[k] ;
         if(check(nx,ny) && dist[nx][ny]>dist[x][y]+1)
         {
             dist[nx][ny] = dist[x][y]+1 ;
             par[nx][ny] = {x,y} ;
             q.push({nx,ny}) ;
         }
         
        }
    }
}

void solve()
{
  cin>>n>>m ;
  arr.resize(n) ;
  for(int i=0;i<n;i++)
  {
      cin>>arr[i] ;
  }
  pii strt,end ;
  cin>>strt.F>>strt.S ;
  cin>>end.F>>end.S ;
  bfs(strt) ;
  cout<<dist[end.F][end.S]<<endl ;
  pii curr = end ;
 vector<pii> path ;
 while(curr!= make_pair(-1,-1))
 {
     path.push_back(curr) ;
     curr = par[curr.F][curr.S] ;
 }
 reverse(path.begin(),path.end()) ;
 for(int i=0;i<path.size();i++)
 {
     cout<<path[i].F<<" "<<path[i].S<<endl ;
 }
 
}
 
signed main()
{
    IOS
    int t ;
    cin>>t ;
    while(t--)
    {
        solve() ;
        
    }
}
