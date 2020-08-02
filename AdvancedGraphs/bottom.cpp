#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<set>
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

void DFSUtils2(vector<int>* edges, int root, bool* visited, set<int>* component, unordered_map<int,int> &comp, int count){
	visited[root] = true;
	component->insert(root);
	comp[root] = count;
	for(int i = 0; i < edges[root].size(); i++){
		int next = edges[root][i];
		if(!visited[next]){
			DFSUtils2(edges, next, visited, component, comp, count);
		}
	}

}

unordered_set<set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n, unordered_map<int,int> &comp){

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
	unordered_set<set<int>*>* output = new unordered_set<set<int>*>();
	int count = 0;
	while(!finishedVertices.empty()){
		int curr = finishedVertices.top();
		finishedVertices.pop();
		if(visited[curr]){
			continue;
		}

		set<int>* component = new set<int>();
		DFSUtils2(edgesT, curr, visited, component, comp, count++);
		output->insert(component);
	}
	return output;
}

int main(){
	
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}

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
		unordered_map<int,int> comp;
		unordered_set<set<int>*>* components = getSCC(edges, edgesT, n, comp);
		unordered_set<set<int>*>::iterator it1 = components->begin();
		while(it1 != components->end()){
			set<int>* component = *it1;
			set<int>::iterator it2 = component->begin();
			bool flag = true;
			while(it2 != component->end()){
				for(int i = 0; i < edges[*it2].size(); i++){
					int next = edges[*it2][i];
					if(comp[*it2] != comp[next]){
						flag =  false;
						break;
					}
				}
				it2++;
				if(!flag){
					break;
				}
			}
			if(flag){
				it2 = component->begin();
				while(it2!= component->end()){
					cout << *it2 + 1<< " ";
					it2++;
				}
				cout << endl;
			}
			
			it1++;
			delete component;
		}
		delete components;
		delete[] edges;
		delete[] edgesT;
	}
}




