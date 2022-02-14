#include <bits/stdc++.h>
using namespace std;

const long long max_long_long=(-1^((long long)1<<sizeof(long long)*8-1));
const long long min_long_long=(-1&((long long)1<<sizeof(long long)*8-1));

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

int main()
{
    freopen("expression_2.in", "r", stdin);
    freopen("expression_2.out", "w", stdout);
    string s;
    string separator="+-";
    long long res, differnce_res;
    char oper;
    int pos=0;
    bool flag_error;
    while(getline(cin, s))
    {
        if(s.empty())
            cout<<"NULL\n";
        else
        {
            flag_error=0;
            res=stoll(word(s, separator, pos));
            while(pos!=s.size())
            {
                oper=s[pos];
                differnce_res=-(oper-',')*stoll(word(s, separator, pos));
                if(differnce_res>0 && res>0 && max_long_long-res<differnce_res) flag_error=1;
                if(differnce_res<0 && res<0 && min_long_long-res>differnce_res) flag_error=1;
                res+=differnce_res;
            }
            pos=0;
            if(flag_error) cout<<"Error\n";
            else cout<<res<<'\n';
        }
    }
    return 0;
}
