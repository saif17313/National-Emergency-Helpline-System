#include<iostream>
#include<bits/stdc++.h>
#define MAX_cnt 100
#define LOCAtion 100
static int p=98543;
static int q=896;
static int z=423;
using namespace std;
class AmbulanceManagement;
class PoliceManagementSystem;
class FSManagement;
class Ambulance
{
    string location;
    int vehicle_no;
    bool avail;
public:
    Ambulance(string a=" ")
    {
        location=a;
        avail=1;
    }
    string getLocation()
    {
        return location;
    }
    bool getavail()
    {
        return avail;
    }
    void setavail(bool b)
    {
        avail=b;
    }
    void showAmbdetails()
    {
        cout<<"Location:"<<location<<' '<<"Vehicle No.:"<<vehicle_no<<' '<<"Availability status:"<<avail<<endl;
    }
    int getno()
    {
        return vehicle_no;
    }
    void setno()
    {
        vehicle_no=p++;

    }
    friend void a_status(AmbulanceManagement a);
};
class AmbulanceManagement
{
    int vehicle_count;
    Ambulance A1[MAX_cnt];
public:
    AmbulanceManagement()
    {
        vehicle_count=0;
    }
    void add()
    {
        string a;
        cout<<"Enter Location:";
        cin>>a;
        A1[vehicle_count]=Ambulance(a);
        A1[vehicle_count].setno();
        cout<<"Your allocated Vehicle No. is : "<<A1[vehicle_count].getno()<<endl;
        vehicle_count++;
    }

    void rent()
    {
        string l;
        int ctr=0;
        if(vehicle_count==0)
            cout<<"No Ambulance is registered Yet"<<endl;

        else
        {
            cout<<"Enter Your Location:";
            cin>>l;
            for(int i=0; i<vehicle_count; i++)
            {
                if(A1[i].getLocation()==l)
                {
                    if(A1[i].getavail()==1)
                    {
                        cout<<"An Ambulance of "<<A1[i].getno()<<" will be at your service soon"<<endl;
                        ctr++;
                        A1[i].setavail(0);
                        break;
                    }
                }
            }
            if(ctr==0)
            {
                int c=0;
                for(int i=0; i<vehicle_count; i++)
                {
                    if(A1[i].getavail()==1)
                    {
                        cout<<"An ambulance from "<<A1[i].getLocation()<<"Vehicle No.:"<<A1[i].getno()<<" will be on service."<<endl;
                        A1[i].setavail(0);
                        c++;

                    }
                }
                if(c==0)
                {
                    cout<<"No ambulance  is available right now.";
                }

            }
        }
    }
    void showdet()
    {
        if(vehicle_count==0)
            cout<<"No Ambulance is registered Yet";
        else
        {
            int n;
            cout<<"Enter the vehicle.no you want to see details of:";
            cin>>n;
            for(int i=0; i<vehicle_count; i++)
            {

                if(n==A1[i].getno())
                {
                    A1[i].showAmbdetails();
                    break;
                }
            }
        }
    }
    void repair()
    {
        int n,m1=0;
        if(vehicle_count==0)
            cout<<"No Ambulance is registered Yet";
        else
        {
            cout<<"Enter Ambulance Vehicle No.:";
            cin>>n;
            for(int i=0; i<vehicle_count; i++)
            {
                if(n==A1[i].getno() && A1[i].getavail()==1)
                {

                    A1[i].setavail(0);
                    cout<<"The Ambulance is taken for repairing."<<endl;
                    m1++;
                    break;
                }
            }
            if(m1==0)
                cout<<"The expected ambulance is not currently available for repairing"<<endl;
        }
    }
    friend void a_status(AmbulanceManagement a);
};
void a_status(AmbulanceManagement a)
{
    int i;
    if(a.vehicle_count==0)
        cout<<"No Ambulance is registered yet."<<endl;
    else
    {
    for(i=0;i<a.vehicle_count;i++)
        a.A1[i].showAmbdetails();
    }
}
class police
{
    string area;
    int pers;
    int unit_no;
    bool avail;
public:
    police(string s=" ",int a=0)
    {
        area=s;
        pers=a;
        avail=1;
    }
    string getarea()
    {
        return area;
    }
    bool getavail()
    {
        return avail;
    }
    void setavail(bool b)
    {
        avail=b;
    }
    int get_unit()
    {
        return unit_no;
    }
    int get_pers()
    {
        return pers;
    }
    void setno()
    {
        unit_no=q;
        q++;
    }
    void policeDetails()
    {
        cout<<"Police unit No.:"<<unit_no<<" of "<<pers<<" persons in the area of "<<area<<" Availability status:"<<avail<<endl;
    }
    friend void p_status(PoliceManagementSystem a);
};
class PoliceManagementSystem
{
public:
    int total_un;
    police p1[LOCAtion];

    PoliceManagementSystem()
    {
        total_un=0;
    }
    void add()
    {
        string s;
        int n;
        cout<<"Enter the police area:";
        cin>>s;
        cout<<"Enter member no:";
        cin>>n;
        p1[total_un]=police(s,n);
        p1[total_un].setno();
        cout<<"Police unit no:"<<p1[total_un].get_unit()<<" Of "<<p1[total_un].get_pers()<<" man is allocated for "<<p1[total_un].getarea()<<endl;
        total_un++;

    }
    void clpolice()
    {
        string s;
        int n;
        cout<<"Give your Area:";
        cin>>s;
        cout<<"Type of emergency:"<<endl;
        cout<<"Press 1 for Robbery/theft type case"<<endl;
        cout<<"Press 2 for Murder or similar type case"<<endl;
        cout<<"Press 3 for Molesting type case"<<endl;
        cout<<"Press 4 for Bomb attack"<<endl;
        cout<<"Press 5 for National Level Threat"<<endl;
        cout<<"Now Give your choice:";
        cin>>n;
        if(n==4)
        {
            cout<<"Special Bomb Disposal unit will contact you immediately.";
        }
        else if(n==5)
        {
            cout<<"Its a national level threat go to a safe location immediately NDS will come to your Location as soon as possible";
        }
        else
        {for(int i=0; i<total_un; i++)
        {
            if(p1[i].getarea()==s)
            {
                if(p1[i].getavail()==1)
                {
                    cout<<"There is "<<p1[i].get_unit()<<" Of "<<p1[i].get_pers()<<" person will be on service"<<endl;
                    p1[i].setavail(0);
                }
                else if(n==1||n==3) cout<<"The unit of "<<s<<" is little busy right now keep safe and wait for a bit "<<endl;
                else if(n==2)
                {
                    int r=0;
                    for(int j=0; j<total_un; j++)
                    {
                        if(p1[j].getavail()==1)
                        {
                            p1[j].setavail(0);
                            cout<<"The unit of "<<s<<" is little busy right now but as your situation is a emergency another unit from "<<p1[j].getarea()<<" will help you"<<endl;
                            r++;
                            break;

                        }
                    }
                    if(r==0)
                    {
                        cout<<"A police unit will contact you as soon as they are available...May allah save you!";
                    }
                }
            }
        }
    }
    }
    void showdet()
    {
        if(total_un==0)
        {
            cout<<"No Unit is registered yet";
        }
        else
        {
            int n,z=0;
            cout<<"Give the Unit No.:";
            cin>>n;
            for(int i=0; i<total_un; i++)
            {
                if(n==p1[i].get_unit())
                {
                    p1[i].policeDetails();
                    z++;
                    break;
                }
            }
            if(z==0)
            {
                cout<<"Not Found!"<<endl;
            }
        }
    }
    void repair()
    {
        int n,c=0;
        if(total_un==0)
        {
            cout<<"No Unit is registered yet";
        }
        else
        {
            cout<<"Give the Unit No. of the Police:";
            cin>>n;
            for(int i=0; i<total_un; i++)
            {
                if(n==p1[i].get_unit()&&p1[i].getavail()==1)
                {
                    p1[i].setavail(0);
                    c++;
                    cout<<"The police unit is now sent out of the service system."<<endl;
                }
            }
            if(c==0)
                cout<<"This Unit is currently busy";
        }
    }
    friend void p_status(PoliceManagementSystem a);
};
void p_status(PoliceManagementSystem a)
{
     int i;
    if(a.total_un==0)
        cout<<"No Ambulance is registered yet."<<endl;
    else
    {
    for(i=0;i<a.total_un;i++)
        a.p1[i].policeDetails();
    }
}

class Fire_service
{

    string area;
    int unit_no;
    bool avail;
public:
    Fire_service(string s="None")
    {
        area=s;
        avail=1;
    }
    string getarea()
    {
        return area;
    }
    bool getavail()
    {
        return avail;
    }
    void setavail(bool a)
    {
        avail=a;
    }
    int get_unit()
    {
        return unit_no;
    }
    void showdetl()
    {
        cout<<"Area:"<<area<<' '<<"Availability status: "<<avail<<endl;
    }
    void setno()
    {
        unit_no=z;
        z++;
    }
    string getlocation()
    {
        return area;
    }
    friend void f_status(FSManagement a);
};
class FSManagement
{
    int unit_cn;
    Fire_service F1[MAX_cnt];
public:
    FSManagement()
    {
        unit_cn=0;
    }
    void addunit()
    {
        string a;
        cout<<"Enter area of the recruiting unit:";
        cin>>a;
        F1[unit_cn]=Fire_service(a);
        F1[unit_cn].setno();
        cout<<"An unit of fire service no:"<<F1[unit_cn].get_unit()<<" got allocated in "<<F1[unit_cn].getarea();
        unit_cn++;
    }
    void rescue()
    {
        if(unit_cn==0)
            cout<<"No Unit is registered yet";
        else
        {
            int ctr=0;
            string l;
            cout<<"Give The Location:";
            cin>>l;
            for(int i=0; i<unit_cn; i++)
            {
                if(F1[i].getarea()==l)
                {
                    if(F1[i].getavail()==1)
                    {
                        cout<<"A Fire Bigrade of "<<F1[i].get_unit()<<" will reach very shortly"<<endl;
                        ctr++;
                        F1[i].setavail(0);
                        break;
                    }
                }
            }
            if(ctr==0)
            {
                int c=0;
                for(int i=0; i<unit_cn; i++)
                {
                    if(F1[i].getavail()==1)
                    {
                        cout<<"Another Fire Bigrade from "<<F1[i].getarea()<<"Vehicle NO:"<<F1[i].get_unit()<<" will come"<<endl;
                        F1[i].setavail(0);
                        c++;
                    }
                }
                if(c==0)
                {
                    cout<<"No Fire Bigrades is Available right now";
                }
            }
        }
    }
    void showdet()
    {
        int n;
        if(unit_cn==0)
            cout<<"No Unit is registered yet";
        else
        {
            cout<<"Give unit no:";
            cin>>n;
            for(int i=0; i<unit_cn; i++)
            {
                if(n==F1[i].get_unit())
                {
                    F1[i].showdetl();
                }
            }
        }
    }

    void repair()
    {
        int n,c=0;
        if(unit_cn==0)
            cout<<"No Unit is registered yet";
        else
        {
            cout<<"Give unit no:";
            cin>>n;
            for(int i=0; i<unit_cn; i++)
            {
                if(n==F1[i].get_unit()&&F1[i].getavail()==1)
                {
                    F1[i].setavail(0);
                    c++;
                    cout<<"The unit "<<n<<"will be go out of service due to maintenance."<<endl;
                    break;
                }
            }
            if(c==0)
                cout<<"The Unit is unavailable."<<endl;

        }
    }
    friend void f_status(FSManagement a);
};
void f_status(FSManagement a)
{
     int i;
    if(a.unit_cn==0)
        cout<<"No Ambulance is registered yet."<<endl;
    else
    {
    for(i=0;i<a.unit_cn;i++)
        a.F1[i].showdetl();
    }
}
int main()
{
    int n;
    AmbulanceManagement a1;
    FSManagement f1;
    PoliceManagementSystem p1;
    cout<<"\t\t\t\tWelcome to NATIONAL EMERGENCY HELPLINE"<<endl;
    cout<<"\n\n"<<endl;
    do
    {

        cout<<"**  For Ambulance Press 1   **"<<endl<<"**    For Police Press 2    **"<<endl<<"** For Fire Service Press 3 **\n"<<endl<<"==>Enter your choice:";
        cin>>n;
        if(n==1)
        {
            cout<<"\n#Press 1 for calling an ambulance "<<endl<<"#Press 2 for entering management system"<<endl<<"==>Enter your choice:";
            int m;
            cin>>m;
            if(m==1)
            {
                a1.rent();
            }
            if(m==2)
            {
                int n1;
                cout<<"#Press 1 to add\n#Press 2 to show details for a specific unit\n#Press 3 to repair\n#Press 4 to show all data\n==>Enter your choice:";
                cin>>n1;
                if(n1==1)
                {
                    a1.add();
                }
                if(n1==2)
                {

                    a1.showdet();
                }
                if(n1==3)
                {
                    a1.repair();
                }
                if(n1==4)
                {
                    a_status(a1);
                }
            }

        }
        if(n==2)
        {

            cout<<"#Press 1 for calling Police force"<<endl<<"#Press 2 for entering management system"<<endl<<"==>Enter your choice:";
            int m;
            cin>>m;
            if(m==1)
            {
                p1.clpolice();
            }
            if(m==2)
            {
                cout<<"#Press 1 to add\n#Press 2 to show details\n#Press 3 to send out of service\n#Press 4 to show all data\n==>Enter your choice:";
                int n1;
                cin>>n1;
                if(n1==1)
                {
                    p1.add();
                }
                if(n1==2)
                {
                    p1.showdet();
                }
                if(n1==3)
                {
                    p1.repair();
                }
                 if(n1==4)
                {
                    p_status(p1);
                }
            }
        }
        if(n==3)
        {
            cout<<"#Press 1 for calling Fire Service"<<endl<<"#Give 2 for entering management system"<<endl<<"==>Enter your choice:";
            int m;
            cin>>m;
            if(m==1)
            {
                f1.rescue();
            }
            if(m==2)
            {
                cout<<"#Press 1 to add\n#Press 2 to show details of a unit\n#Press 3 to repair\n#Press 4 to show all data\n==>Enter your choice:";
                int n1;
                cin>>n1;
                if(n1==1)
                {
                    f1.addunit();
                }
                if(n1==2)
                {
                    f1.showdet();
                }
                if(n1==3)
                {
                    f1.repair();
                }
                 if(n1==4)
                {
                    f_status(f1);
                }
            }
        }
        char c;
        cout<<"\n==>>Do you want to continue this program ?[Y/N]:";
        A:
        cin>>c;
        if(c=='N'||c=='n')
            break;
        else if (c=='Y' || c=='y')
           cout<<"You are continuing this program..."<<endl;
        else
        {
            cout<<"Invalid Input! Please give the correct input again."<<endl;
            goto A;
        }

    }
    while(true);
    return 0;
}

