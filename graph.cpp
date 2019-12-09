#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int, int>
#define vv vector<vector<int> >
#define pb push_back
const int N=100;
vector<pair<int, int> > v[N];


struct compare{
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.second>b.second;
	}
};

int n,m;
vector<int> dijktras(int s){
	vector<int> vis(n+1,0);
	vector<int> d(n+1,LLONG_MAX);
	d[s]=0;
	priority_queue<pi, vector<pi>, compare> pq;
	pq.push({s,d[s]});
	while(!pq.empty()){
		auto u=pq.top();
		pq.pop();
		if(vis[u.first]==1){
			continue;
		}
		vis[u.first]=1;
		for(auto p:v[u.first]){

			if(d[p.first]>d[u.first]+p.second){
				d[p.first]=d[u.first]+p.second;
				pq.push({d[p.first],p.first});
			}
		}
	}
	return d;

}



int32_t main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		v[x].pb({y,z});
		v[y].pb({x,z});
	}
	vector<int> d = dijktras(0);
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;




	return 0;
}