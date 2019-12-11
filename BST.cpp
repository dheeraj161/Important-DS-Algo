#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* insert(node* root, int data){
	if(root==NULL){
		node* newnode=(node*)malloc(sizeof(struct node));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	if(root->data>data){
		root->left=insert(root->left, data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}

void inorder(node* root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

bool find(node* root, int data){
	if(root==NULL){
		return false;
	}
	if(root->data==data){
		return true;
	}
	if(data<root->data){
		return find(root->left, data);
	}
	else{
		return find(root->right, data);
	}
}

int successor(node* root){
	if(root->left->left==NULL){
		int x=root->left->data;
		root->left=NULL;
		return x;
	}
	return successor(root->left);
}

node* deletenode(node* root, int data){
	if(root==NULL){
		return NULL;
	}
	
	if(root->data>data){
		root->left=deletenode(root->left, data);
	}
	else if(root->data<data){
		root->right=deletenode(root->right, data);
	}
	else{
		if(root->left==NULL && root->right==NULL){
			return NULL;
		}
		
		if(root->right==NULL){
			return root->left;
		}
		if(root->right->left==NULL){
			return root->right;
		}
		int x=successor(root->right->left);
		root->data=x;
		
	}
	return root;
}

int main(){
	node* root=NULL;
	while(1){
		cout<<"choose the option : "<<endl;
		cout<<"1. insert an element "<<endl;
		cout<<"2. find an element "<<endl;
		cout<<"3. delete an element "<<endl;
		cout<<"4. print the tree inorder "<<endl;
		cout<<"0. exit"<<endl;
		int option, data;cin>>option;
		if(option==1){
			cin>>data;
			root = insert(root, data);
		}
		else if(option==2){
			cin>>data;
			if(find(root, data)){
				cout<<"element is found in the BST"<<endl;
			}
			else{
				cout<<"element is not found in the BST"<<endl;
			}
		}
		else if(option==3){
			cin>>data;
			root=deletenode(root,data);
		}
		else if(option==4){
			inorder(root);
			cout<<endl;
		}

	}


	return 0;
}
