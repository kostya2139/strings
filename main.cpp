#include <bits/stdc++.h>
using namespace std;

void do_test();
bool is_correct_date(int, int, int);

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
        do_test();
    return 0;
}

void do_test()
{
    string s;
    cin>>s;
    int year=0, month=0, day=0;
    for(int i=0; i<=3; ++i)
    {
        int index[4]={4, 3, 1, 0};
        year*=10;
        year+=s[index[i]]-'0';
    }
    for(int i=0; i<=1; ++i)
    {
        int index[2]={7, 6};
        month*=10;
        month+=s[index[i]]-'0';
    }
    for(int i=0; i<=1; ++i)
    {
        int index[2]={9, 8};
        day*=10;
        day+=s[index[i]]-'0';
    }
    if(is_correct_date(day, month, year)) cout<<"YES\n";
    else cout<<"NO\n";
}

inline bool is_leap_year(int year)
{
    if (year%400==0 || year%100!=0 && year%4==0) return 1;
    return 0;
}

bool is_correct_date(int day, int month, int year)
{
    if(month>12 || month<1) return 0;
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(day<=31 && day>=1) return 1;
        else return 0;
    case 4:
    case 6:
    case 9:
    case 11:
        if(day<=30 && day>=1) return 1;
        else return 0;
    default:
        if((day<=28 && day>=1) || (day==29 && is_leap_year(year))) return 1;
        else return 0;
    }
}
