#include <bits/stdc++.h>
using namespace std;

string get_word(string& s, const string& separator, int& pos)
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

int count_different_letters(string s)
{
    int res=0;
    for(char c='A'; c<='Z'; ++c)
    {
        if(count(s.begin(), s.end(), c) || count(s.begin(), s.end(), tolower(c)))
            ++res;
    }
    return res;
}

int main()
{
    freopen("maxsymbol.in", "r", stdin);
    freopen("maxsymbol.out", "w", stdout);
    string s;
    string answer;
    string separator=".,;:!?\"[] \r";
    string word;
    bool exist=0, empty=1;
    int pos=0;
    int etalon=0, count;
    while(getline(cin, s))
    {
        empty=0;
        while(pos!=s.size())
        {
            word=get_word(s, separator, pos);
            count=count_different_letters(word);
            if(count==etalon)
            {
                answer+=' '+word;
            }
            if(count>etalon)
            {
                etalon=count;
                answer=word;
                exist=1;
            }
        }
        pos=0;
    }
    if(empty)
    {
        cout<<"NULL";
        return 0;
    }
    if(!exist) cout<<-1;
    else cout<<answer;
    return 0;
}
