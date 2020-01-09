#include<bits/stdc++.h>
using namespace std;

void makesegment(int seg_tree[], int a[], int l, int r, int ind){
	if(l==r){
		seg_tree[ind]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	makesegment(seg_tree, a, l, mid, 2*ind);
	makesegment(seg_tree, a, mid+1, r, 2*ind+1);
	seg_tree[ind]=seg_tree[2*ind]+seg_tree[2*ind+1];
}

int findsum(int seg_tree[], int l, int r, int low, int high, int ind){
	if(r<low || l>high){
		return 0;
	}
	if(l<=low && r>=high){
		return seg_tree[ind];
	}
	int mid=(low+high)/2;
	int s1=findsum(seg_tree, l, r, low, mid, 2*ind);
	int s2=findsum(seg_tree, l, r, mid+1, high, 2*ind+1);
	return s1+s2;
}

void updatesegment(int seg_tree[], int l, int r, int val, int low, int high, int ind){
	if(r<low || l>high){
		return ;
	}
	if(low==high){
		seg_tree[ind]+=val;
		return ;
	}
	int mid=(low+high)/2;
	updatesegment(seg_tree,l,r,val,low,mid,2*ind);
	updatesegment(seg_tree,l,r,val,mid+1,high,2*ind+1);
	seg_tree[ind]=seg_tree[2*ind]+seg_tree[2*ind+1];
}

int main(){


	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int seg_tree[3*n];
	memset(seg_tree,0,sizeof(seg_tree));
	makesegment(seg_tree,a,0,n-1,1);

	for(int i=0;i<3*n;i++){
		cout<<seg_tree[i]<<" ";
	}
	cout<<endl;
	int l,r,val;cin>>l>>r>>val;
	updatesegment(seg_tree,l,r,val,0,n-1,1);
	for(int i=0;i<3*n;i++){
		cout<<seg_tree[i]<<" ";
	}
	cout<<endl;
	cin>>l>>r;
	cout<<findsum(seg_tree,l,r,0,n-1,1)<<endl;




	return 0;
}