#include<iostream>
using namespace std;

class node
{
    public :
    int priority;
    string name;
    node * next;

};

class pqueue
{
    public :
    node* front ;
    node * rear;

    pqueue()
    {
        front=NULL;
        rear=NULL;
    }
// Function to insert a patient into the priority queue
    void enqueue(string a , int b)
    {
             node * temp=new node;
             temp->priority=b;
             temp->name=a;
             temp->next=NULL;

        if(rear==NULL)
        {
            front=rear=temp;
        }

        else if(temp->priority>front->priority)
        {
            if(temp->priority>front->priority)
            {
                temp->next=front;
                front=temp;
            }
            else
            {
                front->next=temp;
                rear=temp;

            }
        }

        else
        {
            node * t =front;
            while(t->next!=NULL && t->next->priority>=temp->priority)
            {
                t=t->next;
            }
            temp->next=t->next;
            t->next=temp;
        }

    }

//Function to treat a patient according to priority
    void deque()
    {

        if(front==NULL)
        {
            cout<<"The queue is empty";
        }
        else if (front->next==NULL)
        {

            front=NULL;
            rear=NULL;
        }

        else

        {
            node* p=front;
            front=front->next;
            delete p;
        }



    }
// Function to display the current status of the queue
    void display()
    {
        node * p =front;

        while(p!=NULL)
        {
            cout<<"Name : "<<p->name<<"     "<<"Priority : "<<p->priority;
            cout<<endl;
            p=p->next;
        }

    }


};


main()
{   int n,k;
    string st;
    int pt;
    pqueue q;
    cout<<"\n PRIORITY QUEUE FOR HOSPITALS ";
   do{ cout<<"\n Press 1 add patient ";
    cout<<"\n Press 2 to treat patient";
    cout<<"\n Press 3 to display queue";
    cin>>n;

    switch(n)
    {
        case 1: cout<<"\n Enter the patient's name and priority status";
                cout<<"\n 3: Max priority \n 2: Medium Priority \n 1: Min Priority ";
                cin>>st>>pt;
                q.enqueue(st,pt);
                break;

        case 2: cout<<"\n Patient with highest priority has been treated";
                q.deque();
                break;

        case 3: cout<<"\n The hospital queue is as follows :\n";
                q.display();
    }

    cout<<"\n Press 1 to continue";
        cin>>k;
   }while(k==1);


 return 0;

}
