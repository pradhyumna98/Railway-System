//Indian Railways - Ticket Reservation 
//Submitted By S.P.PRADHYUMNA
#include<fstream.h> 
#include<conio.h> 
#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<process.h> 
char from[30],to[30]; 
void detail() 
{ 
cout<<"From"<<endl; 
gets(to); 
cout<<"To"<<endl; 
gets(from); 
} 
class railways 
{ 
char station[30]; 
unsigned int distance; 
float fare; 
public: 
void ad_data() 
{ 
cout<<"Enter Railway Station name"<<endl; 
gets(station); 
cout<<"enter its distance from Jammu Tawi"<<endl; 
cin>>distance; 
} 
void amount(int a,int b,int c) 
{ 
cout<<"total distance="<<fabs((a-b))<<"\n charges per/km="<<c; 
fare=fabs((a-b))*c; 
cout<<"\nticket cost ="<<fare; 
} 
unsigned int dist() 
{ 
return distance; 
} 
char* station_v() 
{ 
return station ; 
} 
void modify() 
{ 
cout<<"\nEnter new railway station\n"; 
gets(station); 
cout<<"\nenter its distance from Jammu Tawi\n"; 
cin>>distance; 
} 
}tr; 
void main() 
{ 
clrscr(); 
unsigned int per_km=5,choice, d1=0,d2=0,i; 
char station_searched[30]; 
while(1) 
{ 
clrscr(); 
cout<<"\n\t\t\tWELCOME TO INDIAN RAILWAYS\n"; 
for(i=0;i<80;i++) 
{ 
cout<<"-"; 
} 
cout<<"Enter your choice \n\t1:->Add new railway station\n\t2:->Book ticket"<<endl; 
cout<<"\t3:->Change per km rates\n\t4:->modify database of train\n\t5:->exit\n"; 
for(i=0;i<80;i++) 
{ 
cout<<"-"; 
} 
cin>>choice; 
while(choice==1) 
{ 
ofstream of1("train.dat",ios::binary|ios::app); 
tr.ad_data(); 
of1.write((char*)&tr,sizeof(tr)); 
of1.close(); 
break; 
} 
while(choice==2) 
{ 
ifstream of1("train.dat",ios::binary); 
detail(); 
while(of1) 
{ 
of1.read((char*)&tr,sizeof(tr)); 
if(0==strcmp(from,tr.station_v())) 
{ 
d1=tr.dist(); 
} 
if(0==strcmp(to,tr.station_v())) 
{ 
d2=tr.dist(); 
} 
if(d1 && d2) 
{ 
tr.amount(d1,d2,per_km); 
getch(); 
break; 
} 
if(of1.eof()) 
{ 
cout<<"\nstations not found check your spelling\n"; 
getch(); 
} 
} 
of1.close(); 
break; 
} 
if(choice==3) 
{ 
cout<<"Enter new per km rates"; 
cin>>per_km; 
} 
if(choice==4) 
{ 
cout<<"enter the railway station to be changed"; 
gets(station_searched); 
ifstream f1("train.dat",ios::binary); 
while(f1 ) 
{ 
f1.read((char*)&tr,sizeof(tr)); 
long pos=f1.tellg(); 
if(0==strcmp(station_searched,tr.station_v())) 
{ 
f1.seekg((-1*sizeof(tr),ios::cur)); 
tr.modify(); 
f1.close(); 
ofstream f1("train.dat",ios::app); 
f1.seekp(pos,ios::beg); 
f1.write((char*)&tr,sizeof(tr)); 
cout<<"record modified"; 
f1.close(); 
break; 
} 
else if(f1.eof()) 
{ 
cout<<"\nStation not found\n"; 
getch(); 
} 
} 
} 
if(choice==5) 
{ 
cout<<"\nTHANK YOU FOR USING INDIAN RAILWAYS "; 
getch(); 
exit(0); 
} 
if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5) 
{ 
cout<<"entered wrong choice PROGRAM IS ABORTING!!!!!!"; 
getch(); 
exit(0); 
} 
} 
getch(); 
}

