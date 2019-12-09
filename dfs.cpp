#include<bits/stdc++.h>
using namespace  std;
const int N=100;
vector<int> v[N];


int start[N],finish[N],vis[N],times=0,height[N],par[N];


void dfs(int s){
	start[s]=times++;
	vis[s]=1;
	for(int i=0;i<v[s].size();i++){
		if(vis[v[s][i]]==0){
			dfs(v[s][i]);
		}
	}
	finish[s]=times++;
}


void dfsforheight(int s, int c){
	vis[s]=1;
	height[s]=c;
	for(int i=0;i<v[s].size();i++){
		if(vis[v[s][i]]==0){
			dfsforheight(v[s][i],c+1);
		}
	}
}


int d[N];
void findcutedges(int s){
	d[s]=height[s];
	vis[s]=1;
	for(int i=0;i<v[s].size();i++){
		if(vis[v[s][i]]==0){
			par[v[s][i]]=s;
			findcutedges(v[s][i]);
			d[s]=min(d[s],d[v[s][i]]);
			if(d[v[s][i]]>d[s]){
				cout<<s<<" "<<v[s][i]<<endl;
			}
		}
		else if(v[s][i]!=par[s]){
			d[s]=min(d[s],height[v[s][i]]);
		}
	}
}

int32_t main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(start,0,sizeof(start));
	memset(finish,0,sizeof(finish));
	memset(vis,0,sizeof(vis));

	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<start[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<finish[i]<<" ";
	}
	cout<<endl;
	memset(height,0,sizeof(height));
	memset(vis,0,sizeof(vis));
	dfsforheight(1,0);
	for(int i=1;i<=n;i++){
		cout<<height[i]<<" ";
	}
	cout<<endl;
	par[1]=-1;
	memset(vis,0,sizeof(vis));
	findcutedges(1);



	return 0;
}