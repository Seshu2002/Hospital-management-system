#include<iostream>
#include<string>
using namespace std;
int size1 = 0;
int size2 = 0;
class DOCTOR;
class PATIENT
{
protected:
static int patid;
string PatientName,Disease,PatientId,DoctorId;;
int Age;
public:
PATIENT()
{
PatientName = " ";
Disease = " ";
}
PATIENT(string Patname,int age,string dis,string docId)
{
PatientName = Patname;
Age = age;
Disease = dis;
DoctorId = docId;
PatientId = "P"+to_string(getpID());
}
static int getpID()
{
return ++patid;
}
void getname()
{
cout<<PatientName<<endl;
}
string getdocId()
{
return DoctorId;
}
string setname()
{
return PatientName;
}
friend void display(PATIENT* , DOCTOR* , int , int );
};
int PATIENT::patid = 10000;
class DOCTOR
{
protected:
string DoctorName;
string Specialization;
static int d;
string DoctorId;
public:
DOCTOR()
{
DoctorName = "";
Specialization = "";

}
DOCTOR(string name,string spec)
{
DoctorName = name;
Specialization = spec;
DoctorId = "D"+to_string(getid());
}
static getid()
{
return ++d;
}
string getDoctorID()
{
return DoctorId;
}
void docDetails()
{
cout<<"The name of the doctor is: "<<DoctorName<<endl;
cout<<"The specialisation of the doctor is: "<<Specialization<<endl;
cout<<"the identity number of the DOCTOR is: "<<DoctorId<<endl;
}
void getdocname()
{
cout<<DoctorName<<endl;
}
friend void display(PATIENT* , DOCTOR* , int , int );
};
int DOCTOR::d=5000;
void display(PATIENT* p, DOCTOR* d,int size1,int size2)
{
for(int i=0; i<size1;i++)
{
cout<<"The details of the patients are :-"<<endl;
cout<<"The Patient name is: "<<p[i].PatientName<<endl;
cout<<"The Patient age is: "<<p[i].Age<<endl;
cout<<"The Patient disease is: "<<p[i].Disease<<endl;
cout<<"The identity number of Patient is: "<<p[i].PatientId<<endl;
}
for(int i=0;i<size2;i++)
{
cout<<"The details of the doctors are :-"<<endl;
cout<<"The doctor name is: "<<d[i].DoctorName<<endl;
cout<<"The Specialization made by doctor is: "<<d[i].Specialization<<endl;
cout<<"The identity number of doctor is: "<<d[i].DoctorId<<endl;
}
}
class hospital
{
PATIENT p[100]; DOCTOR d[100];
public:
void getinputPatient()
{
string patname,dise,docid;
int age,d;
cout<<"Enter the Patient name: ";
cin>>patname;
cout<<"Enter the age of the Patient: ";

cin>>age;
cout<<"Enter the disease suffered by the Patient: ";
cin>>dise;
while(1)
{
cout<<"Enter the Id of doctor who treated patient: (Doctor Id should start from 5001)"<<endl;
cin>>d;
if(d>5000&&d<5100)
{
docid="D"+to_string(d);
p[size1]=PATIENT(patname,age,dise,docid);
break;
}
else
{
cout<<"Invalid Doctor Id! Check again"<<endl;
continue;
}
}
}
void getinputDoctor()
{
string name,spec;
cout<<"Enter the name of the Doctor: ";
cin>>name;
cout<<"Enter the specalization of the Doctor done: ";
cin>>spec;
d[size2]=DOCTOR(name,spec);
}
void displaydetails()
{
display(p,d,size1,size2);
}
void searchPatient(string name)
{
for(int i=0;i<size1;i++)
{
if(name==p[i].setname())
{
for(int j=0;j<size2;j++)
{
if(p[i].getdocId()==d[j].getDoctorID())
{
cout<<"The Doctor who treated the Patient is: ";
d[j].getdocname();
}
}
}
else
{
continue;
}
}
}
void searchDoctorID(string id)
{
for(int j=0;j<size2;j++)

{
if(id==d[j].getDoctorID())
{
d[j].docDetails();
for(int i=0;i<size1;i++)
{
if(id==p[i].getdocId())
{
cout<<"The name of the Patient treated by doctor is: ";
p[i].getname();
}
}
}
else
{
continue;
}
}
}
};
string name()
{
string n;
cout<<"Please enter the Patient name: ";
cin>>n;
return n;
}
string id()
{
string i;
cout<<"Please enter the Doctor Id: "<<endl;
cin>>i;
return i;
}
int main()
{
hospital h;
while(1)
{
int s;
cout<<"*******Welcome to Hospital management*******"<<endl;
cout<<"1.Enter the Doctor details"<<endl;
cout<<"2.Enter the Patient details"<<endl;
cout<<"3.Search for the Patient"<<endl;
cout<<"4.Search for the Doctor"<<endl;
cout<<"5.List of doctors and patients in the hospital"<<endl;
cout<<"6.Exit from menu "<<endl;
cout<<"Please enter your choice: ";
cin>>s;
switch(s)
{
case 1:
h.getinputDoctor();
size2++;
break;

case 2:
cout<<"Present doctors in Hospital are: "<<size2<<endl;
h.getinputPatient();
size1++;
break;
case 3:
h.searchPatient(name());
break;
case 4:
h.searchDoctorID(id());
break;
case 5:
h.displaydetails();
break;
case 6:
exit(0);
break;
default:
cout<<"Select only valid option."<<endl;
break;
};
}
return 0;
}
