#include<bits/stdc++.h>
using namespace std;

class Triplet{
public:
	int x;
	int y;
	int gcd;
};

Triplet extendedEuclid(int a, int b){

	// Base Case
	if(b == 0){
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}

	// Extended Euclid Algorithm
	Triplet smallAns = extendedEuclid(b, a % b);
	Triplet ans;
	ans.gcd = smallAns.gcd;
	ans.y = smallAns.y;
	ans.x = smallAns.x - (a/b)* smallAns.y;
	return ans;
}

int mmInverse(int a, int m){
	Triplet ans = extendedEuclid(a, m);
	return ans.x;
}

int main(){
	int a = 5;
	int m = 17;
	int ans = mmInverse(a, m);
	cout << "Multiplicative modulo Inverse is " ans << endl;
}