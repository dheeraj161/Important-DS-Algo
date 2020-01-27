#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
const int p=101;

int power(int a, int b){
	int r=1;
	int x=a;
	while(b){
		if(b&1){
			r=(r*x)%M;
		}
		b/=2;
		x=(x*x)%M;
	}
	return r;
}

vector<int> rabin_karp(string s, string ss){
	vector<int> v;
	int h=0;
	int n=s.length();
	int m=ss.length();
	int hh=power(p,m-1);
	if(n<m){
		return v;
	}
	int hashvalue=0;
	for(int i=0;i<m;i++){
		int x=(ss[i]-'a')+1;
		hashvalue=(hashvalue*p)%M;
		hashvalue=(hashvalue+x)%M;
	}

	for(int i=0;i<m;i++){
		int x=(s[i]-'a')+1;
		h=(h*p)%M;
		h=(h+x)%M;
	}
	int i=m;
	int j=0;
	if(h==hashvalue && (s.substr(i,m)==ss)){
		v.push_back(0);
	}
	while(i<n){
		int x=(s[j]-'a')+1;
		int xx=(s[i]-'a')+1;
		h=(h-x*hh+M)%M;
		h=(h*p)%M;
		h=(h+xx)%M;
		if(h==hashvalue && (s.substr(j+1,m)==ss)){
			v.push_back(j+1);
		}
		i++;j++;
	}
	return v;
}




int32_t main(){
	string text;cin>>text;
	string pattern;cin>>pattern;
	vector<int> ans=rabin_karp(text, pattern);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;





	return 0;
}