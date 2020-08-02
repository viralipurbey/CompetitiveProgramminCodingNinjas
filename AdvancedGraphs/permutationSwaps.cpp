#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void dfs(int sv, vector<int>* edges, unordered_set<int>* component, bool* visited){
	visited[sv] = true;
	component->insert(sv);

	for(int i = 0; i < edges[sv].size(); i++){
		int next = edges[sv][i];
		if(!visited[next]){
			dfs(next, edges, component, visited);
		}
	}
}

unordered_set< unordered_set<int>*>* getComponents(int n, vector<int>* edges){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	unordered_set< unordered_set<int>*>* output = new unordered_set< unordered_set<int>*>();
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			unordered_set<int>* component = new unordered_set<int>();
			dfs(i, edges, component, visited);
			output->insert(component);
		}
	}
	delete[] visited;
	return output;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int e;
		cin >> e;

		int* P = new int[n];
		int* Q = new int[n];

		for(int i = 0; i < n; i++){
			cin >> P[i];
		}

		for(int i = 0; i < n; i++){
			cin >> Q[i];
		}

		vector<int>* edges = new vector<int>[n];
		for(int i = 0; i < e; i++){
			int j, k;
			cin >> j >> k;
			edges[j-1].push_back(k-1);
			edges[k-1].push_back(j-1);
		}

		unordered_set< unordered_set<int>*>* components = getComponents(n, edges);
		unordered_set< unordered_set<int>*>::iterator it1 = components->begin();
		bool flag = true;

		while(it1 != components->end()){
			 unordered_set<int>* component = *it1;
			 unordered_set<int> p, q;
			 unordered_set<int>::iterator it2 = component->begin();
			 while(it2 != component->end()){
			 	p.insert(P[*it2]);
			 	q.insert(Q[*it2]);
			 	it2++;
			 }
			 if(p.size() != q.size()){
			 	flag = false;
			 	break;
			 }
			 it2 = p.begin();
			 while(it2 != p.end()){
			 	if(q.find(*it2) == q.end()){
			 		flag = false;
			 		break;
			 	}
                 it2++;
			 }
			 if(!flag){
			 	break;
			 }
			 delete component;
			 it1++;
		}
		if(flag){
			cout <<"YES" << endl;
		}
		else{
			cout <<"NO" << endl;
		}

		//delete components;
		delete[] edges;
		delete[] P;
		delete[] Q;
	}
}