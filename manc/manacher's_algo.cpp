#include<bits/stdc++.h>
using namespace std ;
int man[200010] ;
int n ;
string s ;
void solve() // manacher's algo // largest palindromic length with centre as i
{
    cin>>n ;
    cin>>s ;
    string t = "$#" ;
    for(int i=0;i<n;i++)
    {
        t+=s[i] ;
        t+='#' ;
    }
    t+='@' ;
   int m[t.length()] = {} ;
   for(int i=0,c=1,r=1;i<t.length()-1;i++)
   {
       int j = 2*c-i ; // mirror indexing
       if(i<r)  // intitilaizing
       {
           man[i] = min(r-i,man[j]) ;
       }
       while(t[i+man[i]+1]==t[i-man[i]-1])  // expanding
       man[i]++ ;
       if(i+man[i]>r) // update
       {
           c = i ;
           r = i+man[i] ;
       }
   }
 
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