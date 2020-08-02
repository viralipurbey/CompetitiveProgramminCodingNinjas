#include<bits/stdc++.h>
using namespace std;

int getParent(int* parent, int v){

	while(parent[v] != v){
		v = parent[v];
	}
	return v;
}


bool bipartite(vector<int> *edges, int n, int root, bool* visited){
	if(n == 0){
		return true;
	}
	unordered_set<int> sets[2];
	vector<int> pending;
	sets[0].insert(root);
	pending.push_back(root);
	visited[root] = true;
	while(pending.size() > 0){
		int curr = pending.back();
		pending.pop_back();
		int currSet = sets[0].count(curr) > 0 ? 0 : 1;
		for(int i = 0; i < edges[curr].size(); i++){
			int neighbor = edges[curr][i];
			visited[neighbor] = true;
			if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0){
				sets[1-currSet].insert(neighbor);
				pending.push_back(neighbor);
			}else if(sets[currSet].count(neighbor) > 0){
				return false;
			}
		}
	}
	return true;
}

bool FILLMTR(int** B, int n){
	int* parent = new int[n];
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}

	// Making Components
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int sourcePar = getParent(parent, i);
			int destPar = getParent(parent, j);
			if(B[i][j] == 0 && sourcePar != destPar){
				parent[sourcePar] = destPar;
			}
		}
	}

	// Making edges on basis of 1 
	vector<int>* edges = new vector<int>[n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(B[i][j] == 1){
				int sourcePar = getParent(parent, i);
				int destPar = getParent(parent, j);
				if(sourcePar == destPar){
					return false;
				}
				edges[sourcePar].push_back(destPar);
				edges[destPar].push_back(sourcePar);
			}
		}
	}

	// Checking for bipartite
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			bool ans = bipartite(edges, n, i, visited);
			if(!ans){
				return false;
			}
		}
	}
	return true;
}

int main(){
	
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n, q;
		
		int **B = new int*[n];
		for(int i = 0; i < n; i++){
			B[i] = new int[n];
			for(int j = 0; j < n; j++){
				B[i][j] = -1;
			}
		}

		for(int i = 0; i < q; i++){
			int j, k, val;
			cin >> j >> k >> val;
			B[j-1][k-1] = val; 
		}

		bool ans = FILLMTR(B, n);
		if(ans){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}

