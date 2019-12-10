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
	bool operator()(pi a, pi b){
		return a.second>b.second;
	}
};

int n,m;
vector<pi> v[1000];
vector<int> dijktras(int s){
	vector<int> vis(n+1,0);
	vector<int> d(n+1,LLONG_MAX);
	d[s]=0;
	priority_queue<pi, vector<pi>, compare> pq;
	pq.push({s,d[s]});
	while(!pq.empty()){
		auto u=pq.top();pq.pop();
		if(vis[u.first]==1){
			continue;
		}
		vis[u.first]=1;
		for(auto p:v[u.first]){
			if(d[p.first]>d[u.first]+p.second){
				d[p.first]=d[u.first]+p.second;
				pq.push({p.first,d[p.first]});
			}
		}
	}
	return d;
}

int32_t main(){

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	vector<int> d = dijktras(0);
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;


	return 0;
}