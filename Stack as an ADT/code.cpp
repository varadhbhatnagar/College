#include<iostream>
using namespace std;

class node
{ public:
   char data;
    string s;
    node* next;
};


class stack
{
   public :
       node * top;
       stack()
       {
             top=NULL;
       }

       int empty()
       {

           if(top==NULL)
            return 1;

           else return 0;

       }

       void push(node * p)
       {
           if(top==NULL)
           {
              top=p;

           }
           else
           {
               p->next=top;
               top=p;
           }

       }

       void pop()
       {

           if(top==NULL)
            cout<<"Stack is empty";

           else if (top->next==NULL)
           {

               node * p=top;
               top=NULL;
               delete p;

           }

           else
           {
               node *p =top;
               top=top->next;
               delete p;
           }



       }

};

int precedence(char a)
{   if(a=='^')
   return 3;

    if(a=='*' || a=='/' || a=='%')
    {
        return 2;
    }
    else if (a== '+' || a=='-')
    {
        return 1;
    }
    else return 0;
}

string convert(string st)
{
    string postfix;
    int i;
    stack s;
    for(i=0;i<st.size();i++)
    {

        if(isalnum(st[i]))
        {

            postfix.push_back(st[i]);

        }

        else if(st[i]=='(' )
        {
            node * temp= new node;
            temp->data=st[i];
            temp->next=NULL;
            s.push(temp);

        }

        else if( st[i]==')')
        {
            while(s.top->data!='(')
            {
                postfix.push_back(s.top->data);
                s.pop();
            }
            s.pop();


        }

        else
        {
             if(s.top==NULL)
           {
                node * temp=new node;
                temp->data=st[i];
                temp->next=NULL;
               s.push(temp);

              continue;
           }

           if(s.empty()==0 && precedence(st[i])==precedence(s.top->data) && st[i]=='^')
           {
            node * temp=new node;
            temp->data=st[i];
            temp->next=NULL;
            s.push(temp);
               continue ;
           }


            while(s.empty()==0 && precedence(st[i])<=precedence(s.top->data))
            {
                postfix.push_back(s.top->data);
                s.pop();

            }

            node * temp=new node;
            temp->data=st[i];
            temp->next=NULL;
            s.push(temp);

        }



        }

        while(s.empty()==0)
        {
            postfix.push_back(s.top->data);
            s.pop();
        }


return postfix;
    }

    string convert2(string st)
    {  int i;
        string temp,prefix,temp2;

        for(i=st.size()-1;i>=0;i--)
        {
            temp.push_back(st[i]);
        }

        for(i=0;i<temp.size();i++)
        {
            if(st[i]==')')
                st[i]='(';
            else if(st[i]=='(')
                st[i]=')';
        }

        prefix=convert(temp);

          for(i=prefix.size()-1;i>=0;i--)
        {
            temp2.push_back(prefix[i]);
        }
        return temp2;



    }

   string convert3(string st)
    {  int i;
        stack s;
      for(i=st.size()-1;i>=0;i--)
      {
          if(isalnum(st[i]))
          {
              node * temp=new node;
              temp->s=st[i];
              temp->next=NULL;
              s.push(temp);

          }

          else
          {
              string a , b;
              a=s.top->s;
              s.pop();
              b=s.top->s;
              s.pop();
              a.push_back(st[i]);
              a+=b;

              node * temp= new node;
              temp->s= a;
              temp->next=NULL;
              s.push(temp);

          }

      }

     string infix = s.top->s;
     s.pop();
     return infix;




    }

    string convert4(string st)
    {

     int i;
        stack s;
      for(i=0;i<st.size();i++)
      {
          if(isalnum(st[i]))
          {
              node * temp=new node;
              temp->s=st[i];
              temp->next=NULL;
              s.push(temp);

          }

          else
          {
              string a , b;
              a=s.top->s;
              s.pop();
              b=s.top->s;
              s.pop();
              b.push_back(st[i]);
              b+=a;

              node * temp= new node;
              temp->s = b;
              temp->next=NULL;
              s.push(temp);

          }

      }

     string infix = s.top->s;
     s.pop();
     return infix;








    }

main()

{   int n ,k;
    string infix,postfix,prefix;
  do{  cout<<"\n STRING MENU DRIVEN PROGRAM";
    cout<<"\n Press 1 to convert infix to postfix";
    cout<<"\n Press 2 to convert infix to prefix";
    cout<<"\n Press 3 to evaluate prefix expression";
    cout<<"\n Press 4 to evaluate postfix expression";
    cin>>n;

    switch(n)
    {
      case 1 : cout<<"\n Enter the string in infix \n";
               cin>>infix;
               postfix=convert(infix);
               cout<<postfix;
               break;

      case 2 : cout<<"\n Enter the string in infix form\n";
               cin>>infix;
               prefix=convert2(infix);
               cout<<prefix;
               break;

      case 3 : cout<<"\n Enter the prefix string";
               cin>>prefix;
               infix=convert3(prefix);
               cout<<infix;
               break;


      case 4 : cout<<"\n Enter the postfix string";
               cin>>postfix;
               infix=convert4(postfix);
               cout<<infix;


    }
cout<<"Press 1 to continue";
cin>>k;
}
   while(k==1);


    return 0;

}
