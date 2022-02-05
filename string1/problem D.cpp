#include <bits/stdc++.h>
using namespace std;

int sum_digs(const string &s)
{
    int sum=0;
    for(int i=0; i<s.size(); ++i)
        sum+=s[i]-48;
    return sum;
}

void do_test()
{
    string s;
    cin>>s;
    if(sum_digs(s)%3==0) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    int n;
    cin>>n;
    for(int i=0 ;i<n; ++i)
        do_test();
    return 0;
}

