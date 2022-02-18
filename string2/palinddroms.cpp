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

bool is_palindrom(string s) {
	for (int i = 0; i < s.size(); ++i)
		if (!isalpha(s[i]))
			s.erase(i-- , 1);
    if (s.empty()) return 0;
	for (int i = 0; i < s.size(); ++i)
		if (tolower(s[i]) != tolower(s[s.size()-1-i]))
			return 0;
	return 1;
}

int main()
{
    freopen("palindrom.in", "r", stdin);
    freopen("palindrom.out", "w", stdout);
    string s;
    string separator=".!?";
    string phrase;
    bool exist=0;
    int pos=0;
    while(getline(cin, s))
    {
        while(pos!=s.size())
        {
            phrase=word(s, separator, pos);
            if(is_palindrom(phrase))
            {
                cout<<phrase<<'\n';
                exist=1;
            }
        }
        pos=0;
    }
    if(!exist) cout<<-1;
    return 0;
}
