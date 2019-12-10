#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<pair<int, int> , int> pii;
#define F first
#define S second
#define pb push_back

struct compare{
	bool operator()(pii a, pii b){
		return a.second>b.second;
	}
};



vector<pi> prims(vector<pi> adj[], int n){
	vector<int> vis(n+1,0);
	vector<pi> ans;
	priority_queue<pii, vector<pii>, compare> pq;
	vis[1]=1;
	for(int i=0;i<adj[1].size();i++){
		pq.push({{1,adj[1][i].first},adj[1][i].second});
	}

	while(!pq.empty()){
		auto u=pq.top();pq.pop();
		if(vis[u.first.second]==1){
			continue;
		}
		vis[u.first.second]=1;
		ans.push_back(u.first);
		for(int i=0;i<adj[u.first.second].size();i++){
			if(vis[adj[u.first.second][i].first]==0){
				pq.push({{u.first.second,adj[u.first.second][i].first},adj[u.first.second][i].second});
			}
		}
	}
	return ans;
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	int n,m;
	cin>>n>>m;
	vector<pi> v[n];
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	vector<pi> mst = prims(v,n);

	for(int i=0;i<mst.size();i++){
		cout<<mst[i].first<<" "<<mst[i].second<<endl;
	}









	return 0;
}