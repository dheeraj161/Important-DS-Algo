#include<bits/stdc++.h>
using namespace std;


void bfs(vector<int> adj[], int n, int s){
	queue<int> q;
	q.push(s);
	vector<int> vis(n+1,0);
	vis[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		cout<<x<<" ";
		for(auto u:adj[x]){
			if(vis[u]==0){
				vis[u]=1;
				q.push(u);
			}
		}
	}
	cout<<endl;
}


int main(){
	int n,m;cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(adj,n,1);


	return 0;
}