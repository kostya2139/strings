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

int main()
{
    string s, word1, word2, word3;
    string separator="+=";
    long long a, b, c;
    int pos=0;
    bool flag_exist=0; int base=0;
    size_t *length_num1=new size_t;
    size_t *length_num2=new size_t;
    size_t *length_num3=new size_t;
    getline(cin, s);
    word1='0'+word(s, separator, pos);
    word2='0'+word(s, separator, pos);
    word3='0'+word(s, separator, pos);
    for(int i=2; i<=36; ++i)
    {
        a=stoll(word1, length_num1, i);
        b=stoll(word2, length_num2, i);
        c=stoll(word3, length_num3, i);
        if(*length_num1==word1.size()
           &&
           *length_num2==word2.size()
           &&
           *length_num3==word3.size()
           &&
           a+b==c)
        {
            cout<<i;
            delete length_num1, length_num2, length_num1;
            return 0;
        }
    }
    if(!flag_exist) cout<<-1;
    else cout<<base;
    delete length_num1, length_num2, length_num1;
    return 0;
}
