#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int> adj[N];
vector<int> vis(N+1,0);

void dfs(int s, int p){
	vis[s]=1;
	cout<<s<<" ";
	for(auto u:adj[s]){
		if(vis[u]==1){
			continue;
		}
		vis[u]=1;
		dfs(u,s);
	}
}



int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,-1);
	cout<<endl;


	return 0;
}