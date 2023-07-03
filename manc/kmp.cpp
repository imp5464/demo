#include<bits/stdc++.h>
using namespace std ;
int kmp[100010] ;
int n ;
string s ;
void solve() // kmp algo
{
    cin>>n ;
    cin>>s ;
    kmp[0] = 0 ;
    for(int i=1;i<n;i++) // kmp
    {
        int j = kmp[i-1] ;
        while(j>0 && s[i]!=s[j])
        {
            j = kmp[j-1] ;
        }
        if(s[i]==s[j])
        j++ ;
        kmp[i] = j ;
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