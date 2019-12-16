#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int bit[N];

void update(int x, int val){
	while(x<=N){
		bit[x]+=val;
		x+=x&(-x);
	}
}
int findsum(int x){
	int s=0;
	while(x>0){
		s+=bit[x];
		x-=x&(-x);
	}
	return s;
}

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		update(i+1,x);
	}
	int l,r;cin>>l>>r;
	// sum of elements from index range l to r
	cout<<findsum(r)-findsum(l-1)<<endl; 

	return 0;
}