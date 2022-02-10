#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string digs[10];
    int digs_in_password[8];
    bool exist=1;
    for(int i=0; i<10; ++i)
    {
        cin>>digs[i];
    }
    for(int j=0; j<8; ++j)
    {
        int dig=-1;
        for(int i=0; i<10; ++i)
        {
            if(digs[i]==string(s.begin()+j*10, s.begin()+j*10+10))
                dig=i;
        }
        if(dig==-1) exist=0;
        else digs_in_password[j]=dig;
    }
    if(exist)
        for(int i=0; i<8; ++i)
            cout<<digs_in_password[i];
    else cout<<-1;
    return 0;
}
