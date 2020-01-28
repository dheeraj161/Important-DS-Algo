#include<bits/stdc++.h>
using namespace std;
#define int long long



vector<vector<int> > sparse_table(vector<int> a){
	vector<vector<int> > v(a.size());
	int n=a.size();
	for(int i=n-1;i>=0;i--){
		vector<int> vv;
		vv.push_back(a[i]);
		int l=0,k=i+1,y=1,mn=a[i];
		while(k+y<=n){
			mn=min(mn,v[k][l]);
			vv.push_back(mn);
			l++;
			k+=y;
			y*=2;
		}
		v[i]=vv;
	}
	return v;
}



int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}


	vector<vector<int> > v=sparse_table(a);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	


	// query - find minimum in range [l,r]
	int l,r;cin>>l>>r;
	int x=r-l+1;
	int k=l;
	int mn=a[l];
	for(int i=20;i>=0;i--){
		if((1<<i)&x){
			mn=min(mn,v[k][i]);
			k+=1<<i;
		}
	}
	cout<<"the minimum value between the range "<<l<<" to "<<r<<endl;
	cout<<mn<<endl;



	return 0;
}