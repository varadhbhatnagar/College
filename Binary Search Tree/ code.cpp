#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class node
{

public :
    node* left;
    node * right;
    int data;
};
node * delet(node * root , int x)
{

  if(root==NULL)
    	return root;
    if(x<root->data)
        root->left=delet(root->left,x);
    else if (x>root->data)
        root->right=delet(root->right,x);
    else
    {
        if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root->left;
            free(root);
            return temp;
        }
        node *temp=find_min(root->right);
        root->data=temp->data;
        root->right=delet(root->right,temp->data);
    }
    return root;
}
    node * insert(node * root , int x)
    {

        if(root==NULL)
        {
            root->data=x;
            root->left=NULL;
            root->right=NULL;
             return root;
        }

        else if(x>root->data)
        {

            root->right=insert(root->right,x);
        }
        else if(x<=root->data)
        {

            root->left=insert(root->left,x);
        }


    }




void inorder(node * root)
{
    if(root->left!=NULL)
    inorder(root->left);

    cout<<root->data<<" ";

    if(root->right!=NULL)

        inorder(root->right);


}

int flag =0;
node * search(node * root, int x)
{
  if(root==NULL)
  return NULL;

  if(root->data==x)
  {
     cout<<"Node found";
     flag=1;
     return root;

  }

  else if(root->data>x)
  {

     return(search(root->right,x));

  }

  else
  {
  return(search(root->left,x));
  }


}

node* mirror(node* root)
{
    node * temp=
    temp=NULL;
    if(root!=NULL)
    {
        temp=new node;
        temp->data=root->data;
        temp->right=mirror(root->left);
        temp->left=mirror(root->right);
    }

    return temp;
}

main()
{
   int n,x,k;
   node * root =NULL;

    node * temp=NULL;
  cout<<"\n Binary Search Tree";
 do{ cout<<"\n Press 1 to insert Node";
  cout<<"\n Press 2 to delete Node";
  cout<<"\n Press 3 to search for Node";
  cout<<"\n Press 4 to make mirror image of BST";
  cout<<"\n Press 5 to display BST";
  cout<<"\n Press 6 to display BST level wise";
  cin>>n;

  switch(n)
   {
       case 1: cout<<"\n Enter the data of node you want to insert";
               cin>>x;
               root=insert(root,x);
               break;
       case 2: cout<<"\n Enter the data of node that you want to delete";
                cin>>x;
                root=delet(root,x);;
                break;
       case 3: cout<<"\n Enter the node that you want to search";
               cin>>x;
               temp=search(root,x);
               cout<<temp->data;
               break;
       case 4 : temp=mirror(root);
                inorder(temp);

       case 5: cout<<"\n Inorder traversal of BST is \n";
               inorder(root);
               break;


       //case 5: inorder(t.root);

   }
   cout<<"Press 1 to continue";
   cin>>k;
}while(k==1);

return 0;
}

