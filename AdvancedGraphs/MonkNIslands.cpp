#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int> v[], int n, bool* visited){
	queue<int> q;
	int* level = new int[n]();
	level[0] = 0;
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int i = 0; i < v[curr].size(); i++){
			int next = v[curr][i];
			if(!visited[next]){
				q.push(next);
				visited[next] = true;
				level[next] = level[curr] + 1;
			}
		}
	}
	cout << level[n-1] << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> v[n];
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
        }
		bool* visited = new bool[n];
		for(int i = 0; i < n; i++){
			visited[i] = false;
		}

		BFS(v, n, visited);
	}
}