#include<iostream>
#include<string.h>
using namespace std;
class bus
{
public:
    int bn,bta,bt,bt1,s;
    char d[50],l[50];
    virtual void getdata()
    {
        cout<<"Enter the bus number"<<endl;
        cin>>bn;
        cout<<"Enter the starting point(in CAPITAL LETTERS)"<<endl;
        cin>>l;
        cout<<"Enter the the destination(in CAPITAL LETTERS)"<<endl;
        cin>>d;
        cout<<"Enter 1 for AC bus and 2 for Non AC bus"<<endl;
        cin>>bta;
    }
    void show()
    {

    }
};
class passenger:public bus
{
public:
    char name[50],mn[50];
    void getdata()
    {
        cin.ignore();
        cout<<"Enter the name of passenger"<<endl;
        cin.getline(name,50);
        cout<<"Enter the 10 digit mobile number"<<endl;
        cin>>mn;
    }
};
class seat:public passenger
{
  public:
    int se[50][50],a,i,j,tn,n,sn[50];
    void getdata1()
    {
        int a=1;
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=5;j++)
            {
                se[i][j]=a;
                a++;
            }
        }
    }
    void getdata()
    {
        char l1[50]="AGRA";
        int len,sn[50],i,j,k,l,temp,p;p=1;len=0;
        if(strcmp(d,l1)==0)
        {
            for(i=1;i<=5;i++)
            {
                for(j=1;j<=5;j++)
                {
                    if(se[i][j]<10)
                    {
                        cout<<se[i][j]<<" "<<" ";
                    }
                    else
                    {
                        cout<<se[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
        }
        cout<<"Enter the number of seats you want to reserve";
        cin>>n;
        cout<<"Enter the seat numbers";
        for(i=1;i<=n;i++)
        {
            cin>>sn[i];
        }
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Seat numbers ";
        for(i=1;i<=n;i++)
        {
            cout<<sn[i]<<" ";
        }
        for(k=1;k<=n;k++)
        {
            for(l=1;l<=n-k-1;l++)
            {
                if(sn[l]>sn[l+1])
                {
                    temp=sn[l+1];
                    sn[l+1]=sn[l];
                    sn[l]=temp;
                }
            }
        }
        for(k=1;k<=n;k++)
        {
            len=len+1;
        }
        k=1;
        while(k<=len)
        {
            for(i=1;i<=5;i++)
            {
                for(j=1;j<=5;j++)
                {
                    if(sn[k]==se[i][j])
                    {
                        se[i][j]=0;
                        k++;
                    }
                }
            }
        }
        cout<<"\n\t\t\t\t\t\t  BUS SEAT PLAN\n"<<endl;
        for(i=1;i<=5;i++)
        {
            cout<<"\t\t\t\t\t\t  ";
            for(j=1;j<=5;j++)
            {
                if(se[i][j]<10)
                {
                    cout<<se[i][j]<<" "<<" ";
                }
                else
                {
                    cout<<se[i][j]<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<"\t\t\tIn this plan 0 represents booked seats and others are available\t"<<endl;
    }
};
class rent:public seat
{
public:
    int b;
    void bill()
    {
        if(bta==1)
        {
            b=n*100;
        }
        if(bta==2)
        {
            b=n*50;
        }
    }
};
class ticket:public rent
{
public:
    void getdata()
    {

    }
    void show(int tn)
    {
        cout<<"----------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t   BUS TICKET\t\t\t\t"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t   Ticket number: "<<tn<<"          \t\t"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t           Passenger's Information\t\t";
        cout<<"\t\t\t\t\t\t\t\t                                                       "<<endl;
        cout<<"\t\t\t\t\t            Name: "<<name<<"                             "<<endl;
        cout<<"\t\t\t\t\t            Mobile No.: "<<mn<<"\t\t\t"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t   Bus Information\t\t\t";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t           Bus Number: "<<bta<<"\t\t\t"<<endl;
        if(bta==1)
        {
            cout<<"\t\t\t\t\t           Bus Type: "<<"AC Bus\t\t\t"<<endl;
        }
        else
        {
            cout<<"\t\t\t\t\t           Bus Type: "<<"Non AC Bus\t\t\t                 "<<endl;
        }
        cout<<"\t\t\t\t\t           Depart:  "<<l<<       "                        "<<endl;
        cout<<"\t\t\t\t\t           Arrive:  "<<d<<       "                        "<<endl;
        cout<<"\t\t\t\t\t           Bill:   " <<b<<        "                          "<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    }
};
int main()
{
    int ch,tn;tn=0;
    cout<<"\n\n\t\t\t\t\t\tBUS RESERVATION SYSTEM"<<endl;
    cout<<" \t\t\t\t\tDeveloped By: MALKEET KAUR AND KRITI SHAHI"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<" \t\t\t\t---------------------------------------------------------\t\t\t"<<endl;
    cout<<"\t\t\t\t|\t\t\tWELCOME\t\t\t\t|"<<endl;
    cout<<"\t\t\t\t|\t\t\t\t\t\t        |";
    cout<<"\n\t\t\t\t|\t\t       BUS DETAILS\t\t\t|"<<endl;
    cout<<"\t\t\t\t|\t    BUS NUMBER"<<"\t\t"<<"DESTINATION\t\t"<<"|"<<endl;
    cout<<"\t\t\t\t|\t\t1"<<"\t\t    "<<"AGRA\t\t"<<"|"<<endl;
    cout<<" \t\t\t\t---------------------------------------------------------"<<endl;
    ticket t;
    t.bus::getdata();
    t.passenger::getdata();
    t.seat::getdata1();
    t.seat::getdata();
    t.rent::bill();
    t.show(tn);
    tn++;
    cout<<"Do you want to continue??"<<endl;
    cout<<"Press 1 for Yes and 2 for No";
    cin>>ch;
    while(ch==1)
    {
        cout<<" \t\t\t\t---------------------------------------------------------\t\t\t"<<endl;
        cout<<"\t\t\t\t|\t\t\t\t\t\t        |";
        cout<<"\n\t\t\t\t|\t\t       BUS DETAILS\t\t\t|"<<endl;
        cout<<"\t\t\t\t|\t    BUS NUMBER"<<"\t\t"<<"DESTINATION\t\t"<<"|"<<endl;
        cout<<"\t\t\t\t|\t\t1"<<"\t\t    "<<"AGRA\t\t"<<"|"<<endl;
        cout<<" \t\t\t\t----------------------------------------------------------"<<endl;
        t.bus::getdata();
        t.passenger::getdata();
        t.seat::getdata();
        t.rent::bill();
        t.show(tn);
        cout<<"Do you want to continue??"<<endl;
        cout<<"Press 1 for Yes and 2 for No";
        cin>>ch;
    }
}

