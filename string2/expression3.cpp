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

bool is_empty_problem(const string& s)
{
    return all_of(s.begin(), s.end(), [](char c){return isspace(c);});
}

void open_brackets(string &s)
{
    int i=0, j;
    if(s[0]=='(')
    {
        s.erase(0, 1);
        s.erase(i = s.find(')'), 1);
    }
    while((i=s.find('(', i)) != -1)
    {
        if(s[i-1]=='+')
        {
            if(isdigit(s[i+1])) s.erase(i, 1);
            else s.erase(i-1, 2);
            j=s.find(')', i-1);
            s.erase(i=j, 1);
        }
        else
        {
            if(isdigit(s[i+1])) s.erase(i, 1);
            else 
            {
                s.erase(i-1, 2);
                s[i-1]='+'+'-'-s[i-1];
            }
            j=s.find(')', i-1);
            transform(s.begin()+i, s.begin()+j, s.begin()+i, [](char c) 
                                                            {
                                                                if(c=='+') return '-';
                                                                if(c=='-') return '+';
                                                                return c;
                                                            });
            s.erase(i=j, 1);
        }
    }
}

long long& find_res_problem(string s, long long &res)
{
    open_brackets(s);
    string separator_op="+-";
    string num;
    int pos=0;
    char op='+';
    if(s[0]=='-') op='-';
    res=-(op-',')*stoll(word(s, separator_op, pos));
    while(pos!=s.size())
    {
        op=s[pos];
        res-=(op-',')*stoll(word(s, separator_op, pos));
    }
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
        if(is_empty_problem(s))
            cout<<"NULL\n";
        else
        {
            find_res_problem(s, res);
            cout<<res<<'\n';
        }
    }
    return 0;
}
