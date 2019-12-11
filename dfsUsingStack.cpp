#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back



vector<int> dfs(vector<int> adj[], int n, int s){
	vector<int> ans;
	stack<int> st;
	st.push(s);
	vector<int> vis(n+1,0);
	vis[s]=1;
	ans.push_back(s);
	while(!st.empty()){
		int x=st.top();
		int f=0;
		for(int i=0;i<adj[x].size();i++){
			if(vis[adj[x][i]]==1){
				continue;
			}
			vis[adj[x][i]]=1;
			st.push(adj[x][i]);
			ans.push_back(adj[x][i]);
			f=1;
			break;
		}
		if(f==1){
			continue;
		}
		else{
			st.pop();
		}
	}

	





	return ans;
}



int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n,m;cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> ans=dfs(adj,n,1);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;




	return 0;
}