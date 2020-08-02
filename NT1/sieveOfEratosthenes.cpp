#include<bits/stdc++.h>
using namespace std;

int sieveOfEratosthenes(int n){

	bool* primes = new bool[n+1];
	primes[0] = false;
	primes[1] = false;
	for(int i = 2; i <= n; i++){
		primes[i] = true;
	}

	for(int i = 2; i * i<= n; i++){
		
		if(primes[i]){
			for(int j = i * i; j <= n; j += i){
				primes[j] = false;
			}
		}
		
	}
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(primes[i]){
			count++;
		}
	}
	return count;
}

int main(){

	int n;
	cin >> n;

	int count = sieveOfEratosthenes(n);
	
	cout << count << endl;
}