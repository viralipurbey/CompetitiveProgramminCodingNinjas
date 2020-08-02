#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Triplet{
public:
	ll x;
	ll y;
	ll gcd;
};

Triplet gcdextendedEuclid(ll a, ll b){

	// Base Case
	if(b == 0){
		Triplet ans;
		ans.gcd = a;
		ans.y = 0;
		ans.x = 1;
		return ans;
	}

	// Extended Euclid says
	Triplet smallAns = gcdextendedEuclid(b, a % b);
	Triplet ans;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	ans.gcd = smallAns.gcd;
	return ans;
}

ll modInverse(ll A, ll M){

	ll x = gcdextendedEuclid(A, M).x;
	return (x % M + M)%M; // Because it can be negative also
}

int main(){

	int t;
	cin >> t;
	while(t--){
		ll a, b, d;
		cin >> a >> b >> d;

		ll g = __gcd(a,b);

		// Special Cases
		if(d % g){
			cout << 0 << endl;
			continue;
		}

		if(d == 0){
			cout << 1 << endl;
			continue;
		}

		a /= g;
		b /= g;
		d /= g;

		ll y1 = ((d % a) * modInverse(b,a))%a;
		ll firstValue = d/b;

		if(d < b * y1){
			cout << 0 << endl;
			continue;
		}

		ll n = (firstValue - y1)/a;
		ll ans = n + 1;

		cout << ans << endl;
	}
}