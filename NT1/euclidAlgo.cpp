#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){

	// Special Case
	if(a < b){
		return gcd(b,a);
	}

	// Base Case
	if(b == 0){
		return a;
	}

	// Answer step applying Euclid's algorithm
	return gcd(b, a % b);
}