#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	node* next;
};

void printlist(node* head){
	node* ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

void insertbegin(node** head, int data){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	if((*head)==NULL){
		newnode->next=NULL;
		(*head)=newnode;
		return ;
	}
	newnode->next=(*head);
	(*head)=newnode;
}


void insertend(node* *head, int data){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	if((*head)==NULL){
		(*head)=newnode;
		return ;
	}
	node* ptr=(*head);
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=newnode;
}

void insertgivenposition(node** head, int data, int pos){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	int c=1;
	node* ptr=(*head);
	if(pos==0){
		newnode->next=*head;
		(*head)=newnode;
		return ;
	}
	while(c<pos && ptr->next!=NULL){
		ptr=ptr->next;
		c++;
	}
	node *p=ptr->next;
	ptr->next=newnode;
	newnode->next=p;
}

void deletebegin(node** head){
	if((*head)==NULL){
		cout<<"list is already empty"<<endl;
	}
	node *p=(*head);
	(*head)=p->next;
	free(p);
}

void deleteend(node** head){
	node* ptr=(*head);
	node* pre=NULL;
	while(ptr->next!=NULL){
		pre=ptr;
		ptr=ptr->next;
	}
	pre->next=NULL;
	free(ptr);
}

void deleteatgivenposition(node* *head, int pos){
	node* ptr=(*head);
	int c=0;
	if(pos==0){
		(*head)=ptr->next;
		free(ptr);
		return ;
	}
	while(c<pos-1 && ptr!=NULL){
		c++;
		ptr=ptr->next;
	}
	if(ptr==NULL || ptr->next==NULL){
		cout<<"node not exist"<<endl;
		return ;
	}
	ptr->next=ptr->next->next;
}



int main(){
	
	
	node *head=NULL;
	cout<<"linked list has been created"<<endl;
	while(1){
		cout<<"select the option"<<endl;

		cout<<"1. insert node at the begin"<<endl;
		cout<<"2. insert node at the end"<<endl;
		cout<<"3. insert node after nth node"<<endl;
		cout<<"4. delete the first node"<<endl;
		cout<<"5. delete the last node"<<endl;
		cout<<"6. delete the nth node"<<endl;
		cout<<"7. print the list"<<endl;
		cout<<"0. exit"<<endl;

		int option;
		cin>>option;
		if(option==0){
			break;

		}
		else if(option==7){
			printlist(head);
		}
		else if(option==1 || option==2 || option==3){
			int data;
			cout<<"enter the node to be inserted"<<endl;
			cin>>data;
			if(option==1){
				insertbegin(&head,data);
			}
			else if(option==2){
				insertend(&head, data);
			}
			else{
				cout<<"enter the position at which node has to be inserted"<<endl;
				int pos;cin>>pos;
				insertgivenposition(&head, data, pos-1);
			}
		}
		else{
			if(option==4){
				deletebegin(&head);
			}
			else if(option==5){
				deleteend(&head);
			}
			else{
				cout<<"enter the position to be deleted"<<endl;
				int pos;cin>>pos;
				deleteatgivenposition(&head, pos-1);
			}
		}
	}





	return 0;
}