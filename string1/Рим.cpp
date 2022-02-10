#include <bits/stdc++.h>
using namespace std;

const pair<int, char> Rome_digs[7]
{
    {1, 'I'},
    {5, 'V'},
    {10, 'X'},
    {50, 'L'},
    {100, 'C'},
    {500, 'D'},
    {1000, 'M'}
};

class Rome_num
{
    int num;
    static int transform_to_arabic(char dig)
    {
        for(int i=0; i<7; ++i)
            if(dig==Rome_digs[i].second) return Rome_digs[i].first;
        cout<<"incorrect num";
        return 0;
    }
public:
    Rome_num(int n=0):num(n)
    {
    }
    operator int ()
    {
        return num;
    }

    friend istream& operator>> (istream& in, Rome_num &n);
};

istream& operator>> (istream& in, Rome_num &n)
{
    string s;
    cin>>s;
    n.num=0;
    for(int i=0; i<s.size()-1; ++i)
        if(Rome_num::transform_to_arabic(s[i]) < Rome_num::transform_to_arabic(s[i+1]))
            n.num-=Rome_num::transform_to_arabic(s[i]);
        else
            n.num+=Rome_num::transform_to_arabic(s[i]);
    n.num+=Rome_num::transform_to_arabic(s[s.size()-1]);
    return in;
}

int main()
{
    Rome_num num;
    cin>>num;
    cout<<(int)num;
    return 0;
}
