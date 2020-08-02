#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph, int &sum, bool vis[], int root, int arr[]){
	vis[root] = true;
	sum += arr[root];
	for(int i = 0; i < graph[root].size(); i++){
		
		if(!visited[graph[root][i]]){
			DFS(graph, sum, vis, graph[root][i], arr);
		}
	}
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
	    int n,m;
	    long long ans=0;
	    cin>>n>>m;

	    vector<int> graph[n];
	    for(int i=0;i<m;i++)
	    {
	    	int a, b;
		    cin>>a>>b;
		    a--;b--;
		    graph[a].push_back(b);
		    graph[b].push_back(a);
	    }

	    int arr[n];
	    for(int i=0;i<n;i++)
		    cin>>arr[i];

		bool vis[n] = {false};
	    for(int i=0;i<n;i++)
	    {
		    if(!vis[i])
		    {
			    int sum = 0;
			    DFS(graph, sum, vis, i, arr);
			    ans=max(ans,sum);
		    }
	    }

	    cout<<ans<<"\n";
    }
}