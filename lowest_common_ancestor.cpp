#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;

vector<int> v[N];
int dp[N][20];
int level[N];
int n,m;


void dfs(int s, int pre){
	for(int i=0;i<v[s].size();i++){
		if(v[s][i]==pre){
			continue;
		}
		int x=v[s][i];
		int y=s;
		dp[x][0]=s;
		for(int j=1;j<20;j++){
			if(dp[y][j-1]==-1){
				break;
			}
			dp[x][j]=dp[y][j-1];
			y=dp[x][j];
		}
		dfs(x,s);
	}
}

void bfs(int s){
	queue<pair<int, int> > q;
	q.push({1,0});
	int vis[n+1];
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		level[x]=y;
		for(int j=0;j<v[x].size();j++){
			if(vis[v[x][j]]==0){
				vis[v[x][j]]=1;
				q.push({v[x][j],y+1});
			}
		}
	}
}

int LCA(int u, int v){
	// int x=level[u];
	// int y=level[v];
	// if(x>y){

	// }
	int d=level[u]-level[v];
	if(d<0){
		int t=u;u=v;v=t;
		d=abs(d);
	}
	for(int j=19;j>=0;j--){
		if((1<<j)&d){
			u=dp[u][j];
		}
	}

	if(u==v){
		return u;
	}
	int ans;
	for(int j=19;j>=0;j--){
		if(dp[u][j]==dp[v][j]){
			ans=dp[u][j];
		}
		else{
			u=dp[u][j];
			v=dp[v][j];
		}
	}
	return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin>>n;
    for(int i=1;i<n;i++){
    	int x,y;cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    memset(level,0,sizeof(level));

    dfs(1,0);
    bfs(1);
    

    int q;cin>>q;
    for(int i=0;i<q;i++){
    	int x,y;cin>>x>>y;
    	cout<<LCA(x,y)<<endl;
    }
    return 0;
}
