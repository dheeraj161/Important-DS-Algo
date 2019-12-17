#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back


vvi ans;
vi vv;
int vis[1000005];
void dfs_1(int s, int p, vi v[]){
	for(int i=0;i<v[s].size();i++){
		if(vis[v[s][i]]==0){
			vis[v[s][i]]=1;
			dfs_1(v[s][i],s,v);
		}
	}
	vv.push_back(s);
}


void dfs_2(int s, int p, vi v[], vi &component){
	component.push_back(s);
	for(int i=0;i<v[s].size();i++){
		if(vis[v[s][i]]==0){
			vis[v[s][i]]=1;
			dfs_2(v[s][i],s,v,component);
		}
	}
}


int32_t main(){
	cout<<"no. of nodes: ";
	int n;cin>>n;
	cout<<"no. of edges: ";
	int m;cin>>m;
	vector<int> v[n+1];
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
	}
	vv.clear();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs_1(i,-1,v);
		}
	}
	for(int i=0;i<vv.size();i++){
		cout<<vv[i]<<" ";
	}
	cout<<endl;
	// reverse the edges of the graph and store them in g
	vector<int> g[n+1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			g[v[i][j]].push_back(i);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=vv.size()-1;i>=0;i--){
		if(vis[vv[i]]==0){
			vi component;
			vis[vv[i]]=1;
			dfs_2(vv[i],-1,g,component);
			ans.push_back(component);
		}
	}

	cout<<"connected components are"<<endl;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}





	return 0;
}