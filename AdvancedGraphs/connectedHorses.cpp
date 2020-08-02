#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define p int(1e9 + 7)
int mat[1001][1001], n, m;

int r[] = {2, 1, -2, -1, -2, -1, 2, 1};
int c[] = {1, 2, -1, -2, 1, 2, -1, -2};

bool isValid(int i, int j){
	if(i >= 1 && i <= m && j >= 1 && j <= n){
		return true;
	}
	return false;
}

ll BFSUtils(int R, int C){
	
	ll count = 1;
	mat[R][C] = 2;

	for(int i = 0; i < 8; i++){
		int dx = R+r[i];
		int dy = C+c[i];
		if(isValid(dx,dy) && mat[dx][dy] == 1){
			count += BFSUtils(dx, dy);
		}
	}
	return count;
}

ll fact(ll t){
	ll ans = 1;
	for(ll i = 1; i <= t; i++){
		ans = (ans * i)%p;
	}
	return ans;
}

void func(){
	ll ans = 1, t;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(mat[i][j] == 1){
				t = BFSUtils(i, j);
				ans = (ans * fact(t))%p;
			}
		}
	}
	cout << ans << endl;
}

int main(){

	int t;
	cin >> t;
	while(t--){
		int q;
		cin >> m >> n >> q;
		for(int i= 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				mat[i][j] = 0;
			}
		}

		int x, y;
		while(q--){
			cin >> x >> y;
			mat[x][y] = 1;
		}
		func();
	}
}
