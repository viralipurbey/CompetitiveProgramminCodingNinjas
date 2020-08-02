#include<bits/stdc++.h>
using namespace std;

int modExp(int a, int b, int c){

	if(a == 0){
		return 0;
	}

	if(b == 0){
		return 1;
	}

	long long ans = 1;
	while(b != 0){
		if(b & 1 == 1){
			ans = (ans * (a % c))%c;
		}

		a = (a * a)%c;
		b = b/2; 
	}
	return int((ans + c) % c);
}

int main(){
	int a, b, c;
	cin >> a >> b >> c;

	cout << modExp(a, b, c) << endl;
}