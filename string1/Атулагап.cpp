#include <bits/stdc++.h>
using namespace std;

bool correct_brackets(string s)
{
    int i;
    while(!s.empty())
    {
        bool incorrect=1;
        while((i=s.find("~@"))!=-1 || (i=s.find("#$"))!=-1 || (i=s.find("%&"))!=-1)
        {
            s.erase(i, 2);
            incorrect=0;
        }
        if(incorrect) return 0;
    }
    return 1;
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(correct_brackets(s)) cout<<"OK\n";
        else cout<<"WRONG\n";
    }
    return 0;
}
