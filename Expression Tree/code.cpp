#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
public :
    node * left;
    node * right;
    char data;
};
node * btree1(string st)
{
    int i;
    stack<node*> s;
    for(i=0;i<st.size();i++)
    {
        if(isalnum(st[i]))
        {
            node * temp = new node;
            temp->data=st[i];
            temp->right=NULL;
            temp->left=NULL;
            s.push(temp);
        }

        else
        {
            node * temp = new node;
            temp->data=st[i];
            temp->right=s.top();
            s.pop();
            temp->left=s.top();
            s.pop();
            s.push(temp);
        }
   }
    node * root=s.top();
    s.pop();
return root;
}

void preorder(node * root)
{
    cout<<root->data<<" ";
    if(root->left!=NULL)
        preorder(root->left);

    if(root->right!=NULL)
        preorder(root->right);
}

void nrinorder(node * root)
{ stack<node*> t;
   while(root!=NULL)
   {
       t.push(root);
       root=root->left;
   }

   while(!t.empty())
   {
       node * temp=t.top();
       t.pop();
       cout<<temp->data<<" ";
       temp=temp->right;
       while(temp!=NULL)
       {
           t.push(temp);
           temp=temp->left;
       }
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

void postorder(node * root)
{
   if(root->left!=NULL)
        postorder(root->left);

    if(root->right!=NULL)
        postorder(root->right);

         cout<<root->data<<" ";

}

void nrpreorder(node* root)
{
    stack <node * > t;

    while(root!=NULL)
    {
        cout<<root->data<<" ";
        t.push(root);
        root=root->left;
    }

    while(!t.empty())
    {
        root=t.top();
        t.pop();
        root=root->right;

        while(root!=NULL)
        {
            cout<<root->data<<" ";
            t.push(root);
            root=root->left;
        }
    }
}

node * btree2(string st)
{
    int i;
    stack<node*> s;
    for(i=st.size()-1;i>=0;i--)
    {

        if(isalnum(st[i]))
        {
            node * temp = new node;
            temp->data=st[i];
            temp->right=NULL;
            temp->left=NULL;
            s.push(temp);
        }

          else
        {
            node * temp = new node;
            temp->data=st[i];
            temp->left=s.top();
            s.pop();
            temp->right=s.top();
            s.pop();
            s.push(temp);
        }
    }

     node * root=s.top();
    s.pop();
return root;
}
main()
{ int n,k,response;
node * root;
  string st;

    cout<<"\nEXPRESSION TREE ";
    cout<<"\n Press 1 to enter postfix string";
    cout<<"\n Press 2 to enter prefix string";
    cin>>n;

    switch(n)
    {
    case 1: cout<<"\n Enter string";
            cin>>st;
            root=btree1(st);
         do{cout<<"\n Press 1 for recursive preorder traversal";
            cout<<"\n Press 2 for recursive inorder traversal";
            cout<<"\n Press 3 for non recursive preorder traversal";
            cout<<"\n Press 4 for non recursive inorder traversal";
            cin>>k;
            if(k==1)
            {
                preorder(root);
            }
            else if(k==2)
            {
                inorder(root);
            }
            else if(k==3)
            {
                nrpreorder(root);
            }
            else if(k==4)
            {
                nrinorder(root);
            }
            cout<<"\n Press 1 if you want to continue";
            cin>>response;
         }while(response==1);
            break;

    case 2: cout<<"\n Enter string";
            cin>>st;
            root=btree2(st);
            do{cout<<"\n Press 1 for recursive postorder traversal";
            cout<<"\n Press 2 for recursive inorder traversal";
            cout<<"\n Press 3 for non recursive inorder traversal";
            cin>>k;
            if(k==1)
            {
                postorder(root);
            }
            else if(k==2)
            {
                inorder(root);
            }
            else if(k==3)
            {
                nrinorder(root);
            }
            cout<<"\n Press 1 if you want to continue";
            cin>>response;
         }while(response==1);
    }
return 0;
}
