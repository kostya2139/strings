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

bool integer(double a)
{
    return floor(a)==a;
}

int main()
{
    freopen("expression_1.in", "r", stdin);
    freopen("expression_1.out", "w", stdout);
    string s;
    string separator="+-*/";
    string word_in_line;
    double a,b;
    char oper;
    int pos=0;
    cout.setf(ios::fixed);
    while(getline(cin, s))
    {
        word_in_line=word(s, separator, pos);
        a=stod(word_in_line);
        oper=s[pos];
        word_in_line=word(s, separator, pos);
        b=stod(word_in_line);
        switch(oper)
        {
        case '+':
            cout<< ((integer(a+b)) ? setprecision(0) : setprecision(4)) <<a+b;
            break;
        case '-':
            cout<< ((integer(a-b)) ? setprecision(0) : setprecision(4)) <<a-b;
            break;
        case '*':
            cout<< ((integer(a*b)) ? setprecision(0) : setprecision(4)) <<a*b;
            break;
        case '/':
            if(b==0) cout<<"Error";
            else
            {
                cout<< ((integer(a/b)) ? setprecision(0) : setprecision(4)) <<a/b;
            }
            break;
        }
        cout<<'\n';
        pos=0;
    }
    return 0;
}
