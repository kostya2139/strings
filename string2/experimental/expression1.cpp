#include <bits/stdc++.h>
using namespace std;

string word(string &s, const string &separator, int &pos)
{
    int pos1=s.find_first_not_of(separator, pos);
    if (pos1==-1)
    {
        pos=s.size();
        return "";
    }
    pos=s.find_first_of(separator, pos1);
    if(pos==-1) pos=s.size();
    return s.substr(pos1, pos-pos1);
}

long long& find_res_problem(string s, long long &res)
{
    string separator_op="+-", separator_brack="()";
    string num;
    int pos=0;
    char op;
    return res;
}

int main()
{
    freopen("expression_3.in", "r", stdin);
    freopen("expression_3.out", "w", stdout);
    string s;
    long long res;
    while(getline(cin, s))
    {
        if(s.empty())
            cout<<"NULL\n";
        else
        {
            find_res_problem(s, res);
            /*res=stoll(word(s, separator, pos));
            while(pos!=s.size())
            {
                oper=s[pos];
                differnce_res=-(oper-',')*stoll(word(s, separator, pos));
                res+=differnce_res;
            }*/
            cout<<res<<'\n';
        }
    }
    return 0;
}
