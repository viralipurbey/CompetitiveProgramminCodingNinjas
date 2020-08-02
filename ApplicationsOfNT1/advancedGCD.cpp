#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }

    return gcd(b , a%b);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        ll a,b;
        cin >> a;
        cin >> s;
        if(a == 0)
            cout << s << "\n";
        else
        {
            b = 0;
            for(int i = 0; s[i] != '\0'; i++)
            {
                b = (b * 10 + s[i]-'0') % a;
            }
            cout << gcd(a,b) << "\n";
        }
        
    }
}