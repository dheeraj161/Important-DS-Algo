#include<bits/stdc++.h>
using namespace std;
#define int long long



int seg_tree[100000],lazy[100000];

void makesegment(int a[], int l, int r, int ind){
	if(l==r){
		seg_tree[ind]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	makesegment(a,l,mid,2*ind);
	makesegment(a,mid+1,r,2*ind+1);
	seg_tree[ind]=min(seg_tree[2*ind],seg_tree[2*ind+1]);
}


void updatewithlazy(int l, int r, int val, int low, int high, int ind){
	if(r<low || l>high){
		return ;
	}
	
	
	int x=lazy[ind];
	lazy[2*ind]+=x;
	lazy[2*ind+1]+=x;
	lazy[ind]=0;
	seg_tree[ind]+=x;
	if(low>=l && high<=r){
		lazy[2*ind]+=val;
		lazy[2*ind+1]+=val;
		seg_tree[ind]+=val;
		return ;
	}
	
	int mid=(low+high)/2;
	updatewithlazy(l,r,val,low,mid,2*ind);
	updatewithlazy(l,r,val,mid+1,high,2*ind+1);
	seg_tree[ind]=min(seg_tree[2*ind],seg_tree[2*ind+1]);
}


int getminwithlazy(int l, int r, int low, int high, int ind){
	if(high<l || low>r){
		return 0;
	}
	int x=lazy[ind];
	lazy[2*ind]+=x;
	lazy[2*ind+1]+=x;
	lazy[ind]=0;
	seg_tree[ind]+=x;

	if(low>=l && high<=r){
		return seg_tree[ind];
	}
	int mid=(low+high)/2;
	int s1=getminwithlazy(l,r,low,mid,2*ind);
	int s2=getminwithlazy(l,r,mid+1,high,2*ind+1);
	return min(s1,s2);
}


int32_t main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(seg_tree,0,sizeof(seg_tree));
	memset(lazy,0,sizeof(lazy));
	makesegment(a,0,n-1,1);
	for(int i=0;i<2*n;i++){
		cout<<seg_tree[i]<<" ";
	}
	cout<<endl;
	updatewithlazy(0,2,5,0,n-1,1);

	cout<<getminwithlazy(0,n-1,0,n-1,1)<<endl;
	



	return 0;
}