#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
            long long int value;
            node* l , *r;

};

node* insrt(node* root, int x)
{
  node * temp=new node;
  temp->l=NULL;
  temp->r=NULL;
  temp->value=x;

  if(root==NULL)
  {
    root=temp;
    return root;

  }

  else
  {

    node * t , *q;
    t=root;

    while(t!=NULL)
    {
      q=t;
      if(x>t->value)
           t=t->r;
      else if( x<t->value)
           t=t->l;

    }

  if(x>q->value)
    q->r=temp;

  else
  q->l=temp;

  }
  return root;

}

node * find_min(node * t)
{
  while(t->l!=NULL)
    t=t->l;

    return t;




}

node * delet(node * root , int x)
{

  if(root==NULL)
    	return root;
    if(x<root->value)
        root->l=delet(root->l,x);
    else if (x>root->value)
        root->r=delet(root->r,x);
    else
    {
        if(root->l==NULL)
        {
            node *temp=root->r;
            free(root);
            return temp;
        }
        else if(root->r==NULL)
        {
            node *temp=root->l;
            free(root);
            return temp;
        }
        node *temp=find_min(root->r);
        root->value=temp->value;
        root->r=delet(root->r,temp->value);
    }
    return root;
}
void display(node * root)
{
if(root==NULL)

{
    cout<<"\n BST empty ";
    return ;
}
if(root->l!=NULL)
display(root->l);

cout<<root->value<<" ";

if(root->r!=NULL)
display(root->r);

}

bool srch(node * root , int x)
{ node * p;
  p=root;
   if(p==NULL)
   {
     return false;
   }

   else
   {

     while(p!=NULL)
     {
        if(p->value==x)
        return true;

        if(p->value>x)
        p=p->l;

        if(p->value<x)
        p=p->r;

     }

return false;
   }


}


void bfs(node * root)
{
  queue< node* > q;

  node * p;
  p=root;

  if(p==NULL)
  {cout<<"No element in BST";

  }

  else
  { q.push(p);
  while(!q.empty())
  {
     cout<<q.front()->value<<" ";

     if(q.front()->l!=NULL)
     q.push(q.front()->l);

     if(q.front()->r!=NULL)
     q.push(q.front()->r);

     q.pop();

  }


  }




}


node* mirror(node* root)
{
    node * temp=
    temp=NULL;
    if(root!=NULL)
    {
        temp=new node;
        temp->value=root->value;
        temp->r=mirror(root->l);
        temp->l=mirror(root->r);
    }

    return temp;
}

main()
{
  int n , k ,x;

  node * root=NULL;

cout<<"\n BINARY SEARCH TREE \n";
do{
cout<<"\n Press 1 to insert an element";
cout<<"\n Press 2 to delete an element";
cout<<"\n Press 3 to search for an element";
cout<<"\n Press 4 to find mirror image of BST";
cout<<"\n Press 5 to Display tree ";
cout<<"\n Press 6 to Display Tree Level wise";
cin>>k;

switch(k)
    {
        case 1: cout<<"\n Enter the value of the element that you want to insert";
                cin>>x;


                root=insrt(root , x);

                break;

        case 2: cout<<"Enter the number you want to delete:: ";
        		cin>>x;
        		if(srch(root,x))
        		{
        			root=delet(root,x);
        			cout<<x<<" has been deleted!!!";
        		}
        		else
        			cout<<"Element not Found!!!\n";
        		break;

        case 3: cout<<"\n Enter the element that you want to search for";
                cin>>x;

                if(srch(root,x))
                {cout<<"\n Element was found";
                }
                else
                cout<<"\n Element was not found in BST";
                break;

        case 4: {node *temp=NULL;
                temp=mirror(root);
                display(temp);
                break;
                }
        case 5: display(root);
                break;

        case 6: bfs(root);
                break;



    }cout<<"\n Press 1 to continue";
     cin>>n;
}while(n==1);




}
