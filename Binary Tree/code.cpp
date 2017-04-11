#include<iostream>
using namespace std;

class node
{
  public :
  char data;
  node * right;
  node *left;


};

  node * create()
  { char x;
      node* root;
      cout<<"\n Enter data (Press 0 for no data)\n";
      cin>>x;
      if(x=='0')
        {   return NULL ;
        }
          root = new node;
          root->data=x;

      cout<<"\nEnter data for left child of\n"<<x;
         root->left=create();

      cout<<"\n Enter data for right child of\n"<<x;
          root->right=create();

   cout<<"\nTree Created\n";
       return root;
  }


void inorder(node * root)
{
    if(root->left!=NULL)
        inorder(root->left);

    cout<<root->data<<" ";

    if(root->right!=NULL)
        inorder(root->right);

}
void postorder(node * root)
{
    if(root->left!=NULL)
        postorder(root->left);



    if(root->right!=NULL)
        postorder(root->right);
         cout<<root->data<<" ";

}
void preorder(node * root)
{
     cout<<root->data<<" ";
    if(root->left!=NULL)
        preorder(root->left);



    if(root->right!=NULL)
        preorder(root->right);

}

void modinorder(node *root)
{

    if(root->left!=NULL)
        modinorder(root->left);

    if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";





    if(root->right!=NULL)
        modinorder(root->right);


}

int depth(node * root)
{
    int l,r;
   if(root==NULL)
        return 0;
   else if(root->left==NULL && root->right==NULL)
        return 0;
   l=depth(root->left);
   r=depth(root->right);

   if(l>r)
    return(1+l);

   else return (1+r);

}

node* copy(node* root)
{
    node * temp=NULL;
    if(root!=NULL)
    {
        temp=new node;
        temp->data=root->data;
        temp->left=copy(root->left);
        temp->right=copy(root->right);
    }

    return temp;
}
main()

{  int n,k,ht;
   char x;

    node * root=NULL;
    node * temp;
    int s;
    cout<<"BINARY TREE MENU DRIVEN PROGRAM";
 do{   cout<<"\n PRESS 1 to Create a tree ";
    cout<<"\n PRESS 2 to Display Tree";
    cout<<"\n PRESS 3 to Depth of a Tree";
    cout<<"\n PRESS 4 to Display leaf nodes";
    cout<<"\n PRESS 5 to Create a copy of a tree";
    cin>>n;

    switch(n)
    {
        case 1: root=create();
                 break;

        case 2 : cout<<"\n Press 1 to display in preorder\n";
                 cout<<"\n Press 2 to display in in order\n";
                 cout<<"\n Press 3 to display in postorder\n";
                 cin>>s;
                 if(s==1)
                    preorder(root);
                 if(s==2)
                    inorder(root);
                 if(s==3)
                    postorder(root);
                 break;

        case 3:  ht=depth(root);
                 cout<<"Height of tree is \n"<<ht;
                 break;

        case 4:  modinorder(root);
                 break;

        case 5:  temp=copy(root);
                 cout<<"\n Copy successfully created\n";
                 inorder(temp);



    }
    cout<<"\nPress 1 to continue\n";
    cin>>k;
 }while(k==1);


return 0;
}
