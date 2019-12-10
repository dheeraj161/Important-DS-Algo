#include<bits/stdc++.h>
using namespace std;

int n;

struct point{
	int x,y,w;
};


bool comp(const point &a, const point &b){
	return a.w<b.w;
}

int root[1000];
int ranks[1000];

int find(int x){
	if(root[x]==x){
		return x;
	}
	root[x]=find(root[x]);
	return root[x];
}

int unions(int a, int b){
	int x=find(a);
	int y=find(b);
	if(x==y){
		return 0;
	}
	if(ranks[x]>ranks[y]){
		ranks[x]++;
		root[y]=x;
	}
	else {
		ranks[y]++;
		root[x]=y;
	}
	return 1;

}


int main(){
	cout<<"enter the no. of nodes"<<endl;
	cin>>n;
	cout<<"enter the no. of edges"<<endl;
	int m;cin>>m;

	vector<point> v;
	for(int i=0;i<m;i++){
		point nd;
		cin>>nd.x>>nd.y>>nd.w;
		v.push_back(nd);
	}

	sort(v.begin(),v.end(),comp);
	memset(ranks,0,sizeof(ranks));
	memset(root,0,sizeof(root));
	for(int i=1;i<=n;i++){
		root[i]=i;
	}

	vector<pair<int, int> > ans;

	for(int i=0;i<v.size();i++){
		if(unions(v[i].x, v[i].y)==1){
			ans.push_back({v[i].x,v[i].y});
		}
	}

	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}








	return 0;
}