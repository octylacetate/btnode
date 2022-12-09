
#include<stdio.h>
#include<stdlib.h>

struct btreeNode
{
    struct btreeNode *left;
    int data;
    struct btreeNode *right;
};
void insert(struct btreeNode **sr,int data)
{
    struct btreeNode *r, *current,*parent;
    char flag;
    r = (struct btreeNode *)malloc(sizeof(struct btreeNode));
    r->left = NULL;
    r->data = data;
    r->right = NULL;
    if(*sr == NULL)
    {
        *sr = r;
    }
    else
    {
        current = *sr;
        parent = NULL;
        
        while(current != NULL)
        {
            if(data > current->data)
            {
                parent = current;
                current = current -> right;
                flag = 'r';
            }
            else
            {
                parent  = current;
                current = current->left;
                flag = 'l';
            }
        }
        if(flag == 'r')
        {
            parent -> right =r;
        }
        else
        {
            parent ->left = r;
        }
    }
    
}
void inorder(struct btreeNode *sr)
{
	
	if(sr!=NULL){
		inorder(sr->right);
		printf("%d\n",sr->data);
		inorder(sr->left);
	}
}

void postorder(struct btreeNode *sr)
{
	
	if(sr!=NULL){
		postorder(sr->left);
		postorder(sr->right);
		printf("%d\n",sr->data);
	}
}

void preorder(struct btreeNode *sr)
{
	
	if(sr!=NULL){	printf("%d\n",sr->data);
		preorder(sr->left);
		preorder(sr->right);
	
	}
}

void search(struct btreeNode *root,int num, struct btreeNode **parent,struct btreeNode **x){
	struct btreeNode *current;
	current = root;
	*parent=NULL;
	while(current != NULL){
		if(current->data== num){
			printf("\nFound it");
			return;
		}
		else if(num > current->data){
			*parent=current;
			current=current->right;
		}
		else{
			*parent = current;
			current = current->left;
		}
	}
	*x=NULL;
}

void deletion(struct btreeNode *sr,int num){
	
	struct btreeNode *parent,*x;
	
	
	if(sr==NULL){
		printf("\nTree is empty");
		return;
	}
	search(sr,num,&parent,&x);
	if(x==NULL){
		printf("\nNode nishta");
		return;
	}
//case 1
			if(x->left==NULL && x->right==NULL){
				if(parent->left==x){
					parent->left==NULL;
				}
				else{
					parent->right==NULL;
				}
				free(x);
				return;
			}
			
	//case2
				if(x->left!=NULL && x->right==NULL){
					if(parent->left==x){
						parent->left=x->left;
						
					}
					else{
						parent->right=x->left;
					}
				}					
				//case 2 part 2
				if(x->right!=NULL && x->left==NULL){
					if(parent->right==x){
						parent->right=x->right;
					}
					else{
						parent->left=x->right;
					}
				}
				//case3
				char flag;
				if(x->left!=NULL && x->right!=NULL){
					struct btreeNode *xSuccesor;
					xSuccesor = x->right;
					parent = x;
					while(xSuccesor->left!=NULL){
						parent = xSuccesor;
						xSuccesor = xSuccesor->left;
						flag='l';					
					}
					if(flag=='l'){
						x->data=xSuccesor->data;
						parent->left=xSuccesor->right;
					}
					else{
						x->data=xSuccesor->data;
						parent->right=xSuccesor->right;
					}
					
					
					
					x->data= xSuccesor->data;
					parent->right=xSuccesor->right;
					
				}
}

int main ()
{
	struct btreeNode *root=NULL;
	int i,num,z;
	printf("enter the nmber of nodes");
	scanf("%d",&z);
	       for(i=1;i<=z;i++)
	       {
	       	printf ("enter data of nodes");
	       	scanf("%d",&num);
	       	insert(&root,num);
		   }
		
		deletion(root,2);
			
			printf("\n inorder\n");
			inorder(root);
			printf("\npostorder\n");
			postorder(root);
				printf("\npreorder\n");
	             preorder(root);
}
