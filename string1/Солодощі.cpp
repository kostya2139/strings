#include <bits/stdc++.h>
using namespace std;

bool is_palindrom(const string &s)
{
    return string(s.rbegin(), s.rend())==s;
}

bool is_num(const string &s)
{
    for(int i=0; i<s.size(); ++i)
        if(!isdigit(s[i])) return 0;
    return 1;
}

int main()
{
    string s;
    bool has_palindroms_nums=0;
    while(cin>>s)
    {
        if(is_palindrom(s)&&is_num(s))
        {
            cout<<s<<'\n';
            has_palindroms_nums=1;
        }
    }
    if(!has_palindroms_nums) cout<<"The notepad is clean.";
    return 0;
}

