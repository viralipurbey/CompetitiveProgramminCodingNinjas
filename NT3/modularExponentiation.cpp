#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int modExp(int a, int b, int c){

	if(a == 0){
		return 0;
	}

	if(b == 0){
		return 1;
	}

	// b is even
	long long ans;
	if(b % 2 == 0){
		long long smallAns = modExp(a, b/2, c);
		ans = (smallAns * smallAns)%c;
	}else{
		long long smallAns = modExp(a, b-1, c);
		ans = a % c;
		ans = (ans * smallAns) % c;
	}
	return int((ans + c)%c);
}

int main(){
	int a, b, c;
	cin >> a >> b >> c;

	cout << modExp(a, b, c) << endl;
}