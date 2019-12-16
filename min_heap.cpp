#include<bits/stdc++.h>
using namespace std;


class minheap{
	int heap[1000000];
	int sz=0;
public:
	int parent(int i){return i/2;}
	int leftChild(int i){return i*2;}
	int rightChild(int i){return 2*i+1;}
	void shift_up(int i){
		if(i==1)return ;
		int p=parent(i);
		if(heap[p]>heap[i]){
			swap(heap[p],heap[i]);
		}
		shift_up(p);
	}
	void shift_down(int i){
		if(i==1)return ;
		int min_i=i;
		int l=leftChild(i);
		int r=rightChild(i);
		if(l<=sz && heap[l]<heap[min_i]){
			min_i=l;
		}
		if(r<=sz && heap[r]<heap[min_i]){
			min_i=r;
		}
		if(min_i==i){
			return ;
		}
		shift_down(min_i);
	}
	void insert(int a){
		heap[++sz]=a;
		shift_up(sz);
	}
	int top(){return heap[1];}
	int size(){return sz;}
	void pop(){
		int minimum=heap[1];
		heap[1]=heap[sz-1];
		sz--;
		shift_down(1);
	}
};



int main(){
	int n;cin>>n;
	minheap h;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		h.insert(x); //inserting element in the min heap
	}
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.size()<<endl;


	return 0;
}