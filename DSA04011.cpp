#include<iostream>
#include<cstring>
using namespace std;
long long tp(string s)
{
    int n=0;
    for (int i=0; i<s.size(); i++)
    {
        n=n*2 +(s[i]-'0');
    }
    return n;
}
int main()
{
    int t;
    cin >> t;
    cin >> ws;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        long long tmp=tp(a)*tp(b);
        cout << tmp << endl;
    }
}