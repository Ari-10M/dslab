#include<stdio.h>
#include<stdlib.h>

struct BST{
  int data;
  struct BST *lchild;
  struct BST *rchild;
};

typedef struct BST * NODE;

NODE create() {
  NODE temp;
  temp=(NODE)malloc(sizeof(struct BST));
  printf("\nenter the value:");
  scanf("%d",&temp->data);
  temp->lchild=NULL;
  temp->rchild=NULL;
  return temp;
}

void insert(NODE root,NODE newnode) {
  if(newnode->data < root->data){
    if(root->lchild==NULL){
      root->lchild=newnode;
      }else{
      insert(root->lchild,newnode);
      }
  }else if(newnode->data>root->data){
    if(root->rchild==NULL){
      root->rchild=newnode;
      }else{
      insert(root->rchild,newnode);
      }
  }
}

void search(NODE root){
  int key;
  NODE cur;
  if(root==NULL){
    printf("\nBST is empty.");
    return;
  }
  printf("\nenter element to be searched:");
  scanf("%d",&key);
  cur=root;
  while (cur!=NULL) {
    if (cur->data==key) {
      printf("\nkey element is present in BST");
      return;
    }
    if(key<cur->data){
      cur=cur->lchild;
      }else{
      cur=cur->rchild;
      }
  }
  printf("\nkey element is not found in the BST");
}

void inorder(NODE root){
  if(root!=NULL) {
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
  }
}

void preorder(NODE root) {
  if(root!=NULL) {
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void postorder(NODE root) {
  if(root!=NULL) {
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
  }
}

int main() {
  int ch,n,i;
  NODE root = NULL,newnode;
  while(1) {
    printf("\n\n~~~~BST MENU~~~~");
    printf("\n1.create a BST");
    printf("\n2.display");
    printf("\n3.search");
    printf("\n4.exit");
    printf("\nenter your choice: ");
    scanf("%d",&ch);
    switch(ch) {
      case 1:
        printf("\nenter the number of element: ");
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
          newnode=create();
          if(root==NULL) {
            root = newnode;
              }else{
            insert(root,newnode);
              }
        }
        break;
      case 2:
        if(root==NULL) {
          printf("\ntree is not created");
            }else{
          printf("\nthe preorder display: ");
          preorder(root);
          printf("\nthe inorder display: ");
          inorder(root);
          printf("\nthe postorder display: ");
          postorder(root);
        }
        break;
      case 3:
        search(root);
        break;
      case 4:
        exit(0);
      default:
        printf("\ninvalid choice!please enter a valid option.");
    }
  }
  return 0;
}
          
    
  
    
    
    
    
    
    
    
