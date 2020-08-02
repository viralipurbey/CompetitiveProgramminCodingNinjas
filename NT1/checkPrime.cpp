#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int num){
	int countFactors = 0;
	for(int j = 1; j * j <= n; j++){
		if(n % j == 0){
			if(j*j == n){
				countFactors++;
			}else{
				countFactors += 2;
			}
		}
	}
	if(countFactors == 2){
		return true;
	}
	return false;
}

int main(){

	int n;
	cin >> n;

	int count = 0;

	for(int i = 1; i <= n; i++){
		if(checkPrime(i))
			count++;
	}
	
	cout << count << endl;
}