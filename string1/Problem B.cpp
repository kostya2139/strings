#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    bool error=0;
    for(int i=0; i+2<s.size(); i+=2)
    {
        if(s[i]!='(' || s[i+1]!=')') error=1;
    }
    if(error)
    {
        cout<<"ERROR";
        return 0;
    }
    if(s.size()%2)
    {
       if(s[s.size()-1]=='(') cout<<"INSIDE";
       else cout<<"ERROR";
    }
    else
    {
        if(s[s.size()-2]=='(' && s[s.size()-1]==')') cout<<"OUTSIDE";
       else cout<<"ERROR";
    }
    return 0;
}

