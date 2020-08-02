#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void func(long long n)
{
	ll sum = 0;

	for (long long int i = 1; i <= n; i++) {

		// GCD of i and n
		long long int gcd = __gcd(i, n);

		// LCM of i and n i.e. (i * n) / gcd(i, n)
		long long int lcm = (i * n) / gcd;

		// Update sum
		sum = sum + lcm;
	}

	cout<< sum<<endl;
}