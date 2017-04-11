#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector < pair <ll, pair<string,ll> > > vp;

void has(string st , ll no)
{
 ll pos=0,org;
  pos=no%10;

if(vp[pos].second.second==-1)
{
  vp[pos].second.second=no;
  vp[pos].second.first=st;

}
else
{ org=pos;

  if(vp[pos].first==-1)
  {
    pos++;
    pos%=10;
    while(vp[pos].second.second!=-1)
    {
    pos++;
    pos%=10;
    if(pos==org)
    {cout<<"Hash table full";
    return;
    }
    }

    vp[pos].second.first=st;
    vp[pos].second.second=no;
    vp[org].first=pos;

  }
  else
  { pos=vp[pos].first;
     while(vp[pos].first!=-1)
     {
       pos=vp[pos].first;
     }
     org=pos;
     while(vp[pos].second.second!=-1)
    {
    pos++;
    pos%=10;
     if(pos==org)
    {cout<<"Hash table full";
    return;
    }
    }
     vp[pos].second.first=st;
    vp[pos].second.second=no;
    vp[org].first=pos;


  }



}
}

void display()

{ int i;
    for(i=0;i<10;i++)
    {
       cout<<vp[i].first<<" "<<vp[i].second.first<<" "<<vp[i].second.second<<endl;

    }



}
main()
{


 ll n , no , k,i,m;
 string name;

 //Initialising database with NULL values

 for(i=0;i<10;i++)
 {
   vp.push_back(make_pair(-1 ,make_pair(" ",-1)));

 }

 cout<<"\n\nHASHING\n\n";

do{


  cout<<"\n Press 1 to enter data";
           cout<<"\n Press 2 to display hash table";
           cout<<"\n Press 3 to search for a name";
           cin>>k;
           switch(k)
           {
             case 1: cout<<"\n Enter name";
                     cin>>name;
                     cout<<"\n Enter phone number";
                     cin>>no;
                     has(name,no);
                     break;
             case 2: display();





           } cout<<"\n Press 1 to continue";
             cin>>m;





 }while(m==1);


}
