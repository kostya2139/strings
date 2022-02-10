#include <bits/stdc++.h>
using namespace std;

bool is_palindrom(const string &s)
{
    for(int i=0; i<s.size(); ++i)
        if(s[i]!=s[s.size()-1-i] && tolower(s[i])!=tolower(s[s.size()-1-i]))
            return 0;
    return 1;
}

int main()
{
    string s;
    ifstream in("palindrom.in");
    ofstream out("palindrom.out");
    int length=0;
    in>>length;
    bool empty=1, has_palindroms_this_length=0;
    while(in>>s)
    {
        empty=0;
        if(is_palindrom(s)&&s.size()==length)
        {
            out<<s<<'\n';
            has_palindroms_this_length=1;
        }
    }
    if (empty) out<<"NULL";
    else if (!has_palindroms_this_length) out<<-1;
    in.close();
    out.close();
    return 0;
}

