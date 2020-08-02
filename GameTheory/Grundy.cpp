#include<bits/stdc++.h> 
using namespace std; 
  
// A Function to calculate Mex of all the values in 
// that set. 
int calculateMex(unordered_set<int> Set) 
{ 
    int Mex = 0; 
  
    while (Set.find(Mex) != Set.end()) 
        Mex++; 
  
    return (Mex); 
} 
  
// A function to Compute Grundy Number of 'n' 
// Only this function varies according to the game 
int calculateGrundy (int n) 
{ 
    if (n == 0) 
        return (0); 
  
    unordered_set<int> Set; // A Hash Table 
  
    Set.insert(calculateGrundy(n/2)); 
    Set.insert(calculateGrundy(n/3)); 
    Set.insert(calculateGrundy(n/6)); 
  
    return (calculateMex(Set)); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int n;
    cin>>n;
    printf("%d", calculateGrundy (n)); 
    return (0); 
}