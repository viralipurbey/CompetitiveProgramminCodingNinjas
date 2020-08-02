#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void DFSUtils(vector<int>* edges, int root, bool* visited, stack<int> & finishedVertices){
	visited[root] = true;
	for(int i = 0; i < edges[root].size(); i++){
		int next = edges[root][i];
		if(!visited[next]){
			DFSUtils(edges, next, visited, finishedVertices);
		}
	}
	finishedVertices.push(root);
}

void DFSUtils2(vector<int>* edges, int root, bool* visited, unordered_set<int>* component){
	visited[root] = true;
	component->insert(root);
	for(int i = 0; i < edges[root].size(); i++){
		int next = edges[root][i];
		if(!visited[next]){
			DFSUtils2(edges, next, visited, component);
		}
	}

}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n){

	stack<int> finishedVertices;
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			DFSUtils(edges, i, visited, finishedVertices);
		}
	}
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	while(!finishedVertices.empty()){
		int curr = finishedVertices.top();
		finishedVertices.pop();
		if(visited[curr]){
			continue;
		}

		unordered_set<int>* component = new unordered_set<int>();
		DFSUtils2(edgesT, curr, visited, component);
		output->insert(component);
	}
	return output;
}

int main(){
	
	int n;
	cin >> n;

	vector<int> *edges = new vector<int>[n];
	vector<int> *edgesT = new vector<int>[n];

	int e;
	cin >> e;

	for(int i = 0; i < e; i++){
		int j, k;
		cin >> j >> k;
		edges[j-1].push_back(k-1);
		edgesT[k-1].push_back(j-1);
	}
	unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
	unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
	while(it1 != components->end()){
		unordered_set<int>* component = *it1;
		unordered_set<int>::iterator it2 = component->begin();
		while(it2 != component->end()){
			cout << *it2 + 1<< " ";
			it2++;
		}
		cout << endl;
		it1++;
		delete component;
	}
	//delete components;
	delete[] edges;
	delete[] edgesT;
}




