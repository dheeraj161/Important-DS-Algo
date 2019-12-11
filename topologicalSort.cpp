#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back



vector<int> topological(vector<int> adj[], int n){
	vector<int> ans;
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			stack<int> st;
			st.push(i);
			vis[i]=1;
			while(!st.empty()){
				int x=st.top();
				int f=0;
				for(auto u:adj[x]){
					if(vis[u]==1){
						continue;
					}
					f=1;
					st.push(u);
					vis[u]=1;
				}
				if(f==1){
					continue;
				}
				ans.push_back(x);
				st.pop();
			}
		}
	}
	reverse(ans.begin(),ans.end());
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
		// adj[y].push_back(x);
	}
	vector<int> ans=dfs(adj,n);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;




	return 0;
}