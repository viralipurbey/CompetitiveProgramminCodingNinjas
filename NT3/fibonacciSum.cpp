#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;


void multiply(unsigned long long A[2][2],unsigned long long M[2][2]){

	unsigned long long firstValue = (((A[0][0]%mod) * (M[0][0]%mod))%mod + ((A[0][1]%mod) * (M[1][0]%mod))%mod)%mod;
	unsigned long long secondValue = (((A[0][0]%mod) * (M[0][1]%mod))%mod + ((A[0][1]%mod) * (M[1][1]%mod))%mod)%mod;
	unsigned long long thirdValue = (((A[1][0]%mod) * (M[0][0]%mod))%mod + ((A[1][1]%mod) * (M[1][0]%mod))%mod)%mod;
	unsigned long long fourthValue = (((A[1][0]%mod) * (M[0][1]%mod))%mod + ((A[1][1]%mod) * (M[1][1]%mod))%mod)%mod;

	A[0][0] =firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;

}

void power(unsigned long long A[2][2],unsigned long long n){

	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		unsigned long long F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}

}

unsigned long long getFibonacci(unsigned long long n){

	if(n==0 || n==1){
		return n;
	}
	unsigned long long A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0]%mod;
	
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
    unsigned long long answer = (((getFibonacci(n+2)%mod) - (getFibonacci(m+1)%mod) + mod)%mod);
    return answer;
}