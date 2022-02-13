#include <bits/stdc++.h>
using namespace std;

string word(string &s, const string &separator, int &pos)
{
    int pos_start=s.find_first_not_of(separator, pos);
    if (pos_start==-1)
    {
        pos=s.size();
        return "";
    }
    pos=s.find_first_of(separator, pos_start);
    if(pos==-1) pos=s.size();
    return s.substr(pos_start, pos-pos_start);
}

bool is_num(const string &s)
{
    if(s.size()==0) return 0;
    for(int i=0; i<s.size(); ++i)
        if(!isdigit(s[i])) return 0;
    return 1;
}

bool Armstrong(const string &s)
{
    unsigned long long sum=0, num=0;
    for(int i=0; i<s.size(); ++i)
    {
        sum=sum+int(pow((s[i]-'0'), s.size()));
        num=num*10;
        num=num+s[i]-'0';
    }
    if (sum==0) return 0;
    return sum==num;
}

int main()
{
    freopen("armstrong.in", "r", stdin);
    freopen("armstrong.out", "w", stdout);
    string s;
    string separator=".,;:!?\"[] \n\t\v\f\r";
    string word_in_line;
    bool exist=0;
    int pos=0;
    while(getline(cin, s))
    {
        while(pos!=s.size())
        {
            word_in_line=word(s, separator, pos);
            if(is_num(word_in_line) && Armstrong(word_in_line))
            {
                cout<<word_in_line<<'\n';
                exist=1;
            }
        }
        pos=0;
    }
    if(!exist) cout<<-1;
    return 0;
}
