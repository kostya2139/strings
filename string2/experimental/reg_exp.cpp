#include <bits/stdc++.h>
using namespace std;

string word(const string &s, const string &separator, int &pos)
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

bool reg_exp(const string& s, const string& reg)
{
    string separator="?*";
    string symbols;
    int pos=0, pos1=-1;
    {
        symbols=word(reg, separator, pos);
        while(s.find(symbols, pos1+1)!=-1)
        {
            if(reg.find_first_not_of(separator)==-1)
            {
                if(count(reg.begin(), reg.end(), '*')==0 && count(reg.begin(), reg.end(), '?')==s.size()) return 1;
                if(count(reg.begin(), reg.end(), '*')!=0 && count(reg.begin(), reg.end(), '?')<=s.size()) return 1;
            }
            else
            {
                pos1=s.find(symbols, pos1+1);
                if(count(reg.begin(), reg.begin()+(pos-symbols.size()), '*')==0 && count(reg.begin(), reg.begin()+(pos-symbols.size()), '?') != pos1)
                    continue;
                if(count(reg.begin(), reg.begin()+(pos-symbols.size()), '?') > pos1) continue;
                else if (reg.find_first_not_of("?*", pos)==-1)
                     {
                         if(count(reg.begin()+pos, reg.end(), '*')==0) return (count(reg.begin()+pos, reg.end(), '?') == s.size()-pos1-symbols.size());
                         else return (count(reg.begin()+pos, reg.end(), '?') <= s.size()-pos1-symbols.size());
                     }
                     else if( reg_exp(s.substr(pos1+symbols.size()), reg.substr(pos)) ) return 1;
            }
        }
        return 0;
    }
}

int main()
{
    int n;
    string s, reg;
    cin>>n; cin.ignore(1);
    for(int i=0; i<n; ++i)
    {
        cin>>s>>reg;
        if(reg_exp(s, reg)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
