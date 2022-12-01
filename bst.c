
#include<stdio.h>
#include<stdlib.h>

struct BTnode
{
    struct BTnode *left;
    int data;
    struct BTnode *right;
};
void insert(struct BTnode **sr,int data)
{
    struct BTnode *r, *current,*parent;
    char flag;
    r = (struct BTnode *)malloc(sizeof(struct BTnode));
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
void inorder(struct BTnode *sr)
{
	
	if(sr!=NULL){
		inorder(sr->right);
		printf("%d\n",sr->data);
		inorder(sr->left);
	}
}

void postorder(struct BTnode *sr)
{
	
	if(sr!=NULL){
		postorder(sr->left);
		postorder(sr->right);
		printf("%d\n",sr->data);
	}
}

void preorder(struct BTnode *sr)
{
	
	if(sr!=NULL){	printf("%d\n",sr->data);
		preorder(sr->left);
		preorder(sr->right);
	
	}
}

int main ()
{
	struct BTnode *root=NULL;
	int i,num,z;
	printf("enter the nmber of nodes");
	scanf("%d",&z);
	       for(i=1;i<=z;i++)
	       {
	       	printf ("enter data of nodes");
	       	scanf("%d",&num);
	       	insert(&root,num);
		   }
		
			
			printf("\n inorder\n");
			inorder(root);
			printf("\npostorder\n");
			postorder(root);
				printf("\npreorder\n");
	             preorder(root);
}
