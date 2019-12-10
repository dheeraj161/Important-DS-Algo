#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};


node* rightrotate(node* x){
	node* y=x->left;
	x->left=y->right;
	y->right=x;
	return y;
}

node* leftrotate(node* x){
	node* y=x->right;
	x->right=y->left;
	y->left=x;
	return y;
}


node *splay(node* root, int key){
	if(root==NULL || root->data==key){
		return root;
	}
	if(root->data>key){
		if(root->left==NULL){
			return root;
		}
		if(root->left->data>key){
			root->left->left=splay(root->left->left,key);
			root=rightrotate(root);
		}
		else if(root->left->data<key){
			root->left->right=splay(root->left->right,key);
			if(root->left->right!=NULL){
				root->left=leftrotate(root->left);
			}
		}
		return (root->left==NULL)? root:rightrotate(root);
	}
	else{
		if(root->right==NULL){
			return root;
		}
		if(root->right->data>key){
			root->right->left=splay(root->right->left,key);
			if(root->right->left!=NULL){
				root->right=rightrotate(root->right);
			}
		}
		else if(root->right->data<key){
			root->right->right=splay(root->right->right,key);
			root=leftrotate(root);
		}
		return (root->right==NULL)? root: leftrotate(root);
	}

}

node* insert(node* root, int data){

	if(root==NULL){
		node* newnode=(node*)malloc(sizeof(struct node));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	root=splay(root, data);
	if(root->data==data){
		return root;
	}
	node* newnode=(node*)malloc(sizeof(struct node));
	newnode->data=data;
	if(root->data>data){
		newnode->right=root;
		newnode->left=root->left;
		root->left=NULL;
	}
	else{
		newnode->left=root;
		newnode->right=root->right;
		root->right=NULL;
	}
	return newnode;
	
}

void inorder(node* root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

node* find(node* root, int data){
	return splay(root,data);
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
			root=find(root,data);
			if(root->data==data){
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
		cout<<"root node "<<root->data<<endl;

	}


	return 0;
}