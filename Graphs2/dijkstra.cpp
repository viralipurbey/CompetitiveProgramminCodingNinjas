#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* weight, bool *isVisited, int n){
	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!isVisited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int n, int** input){
	int* weight = new int[n];
	bool *isVisited = new bool[n];

	for(int i = 0; i < n; i++){
		isVisited[i] = false;
		weight[i] = INT_MAX;
	}

	weight[0] = 0;

	for(int i = 0; i < n-1; i++){
		int minVertex = findMinVertex(weight, isVisited, n);
		isVisited[minVertex] = true;

		for(int j = 0; j < n; j++){
			if(input[minVertex][j] > 0 && !isVisited[j]){
				if(weight[j] > weight[minVertex] + input[minVertex][j]){
					weight[j] = weight[minVertex] + input[minVertex][j];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
        cout << i << " " << weight[i] << endl;
    }
}

int main(){
	int n;
	cin >> n;
	int e;
	cin >> e;
	int **adj = new int*[n];
	for(int i = 0; i < n; i++){
		adj[i] = new int[n]();
	}
	
    int **input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[n];
        for(int j = 0; j < n; j++) input[i][j] = -1;
    }

    for(int i = 0; i < e; i++){
        int ei, ej, w;
        cin >> ei >> ej >> w;
        input[ei][ej] = w;
        input[ej][ei] = w;
    }
	dijkstra(n, input);
}