#include <unistd.h> 
#include <cstdlib>
#include <iostream>
#include "mylib.h"
#define MAX 100
int sl=10;
using namespace std;
void welcome();
void khungngoai();

void veran(int toadox[], int toadoy[]);
void khoitaoran(int toadox[], int toadoy[]);
void xulyran(int toadox[],int toadoy[],int x,int y,int &xqua, int &yqua);
void them(int a[],int x);
void xoa(int a[],int vt);
void xoadulieucu(int toadox[], int toadoy[]);

bool ranchamduoi(int toadox[], int toadoy[]);
bool ranchamtuong(int x, int y);
bool ktra(int toadox[],int toadoy[]);

void taoqua(int &xqua, int &yqua, int toadox[],int toadoy[]);
bool randequa(int xqua, int yqua, int toadox[],int toadoy[]);
bool rananqua(int x, int y, int xqua, int yqua);
char ansUser();
int main()
{	
	welcome();
	char ch=ansUser();
	system("cls");
	if(ch=='y'||ch=='Y'||ch=='n'||ch=='N')
	{
	bool gameover=false;
	int toadox[MAX],toadoy[MAX];	
	khoitaoran(toadox,toadoy);
	veran(toadox,toadoy);
	khungngoai();
	srand(time(NULL));
	int xqua=0,yqua=0;
	
	taoqua( xqua,yqua,toadox, toadoy);
	int check=2,x=30,y=10;
	
	
	while(gameover==false)
	{	
		// 0 di len
		// 1 di xuong
		// 2 sang phai
		// 3 sang trai
		xoadulieucu(toadox, toadoy);
		// di chuyen
		if(_kbhit())
		{
			char kitu=_getch();
			if( kitu=-32)
			{
				kitu=_getch();
				if(kitu==72 && check !=1)
				check=0;
				else if(kitu==80 && check!=0)
				check=1;
				else if(kitu==77 && check != 3)
				check=2;
				else if(kitu==75 && check != 2)
				check=3;
			}
		}
		
		if(check==0)
		y--;
		else if(check==1)
		y++;
		else if(check==2)
		x++;
		else if(check==3)
		x--;
		// xu ly ran
		xulyran(toadox,toadoy,x,y,xqua,yqua);
		// kiem tra 
		gameover=ktra(toadox,toadoy);
		
		Sleep(150);
	}
	system("cls");
	
	
	setColor(3);
	gotoXY(50,50);
	cout<<"GAMEOVER";
	}
	else cout<<"CUT";
	return 0;
}
void welcome()
{
	gotoXY(5,5);
	cout<<"Chao mung den voi ran san moi"<<endl;
}
char ansUser()
{
	char ans;
	cout<<"Ban muon bat dau choi chu???"<<endl;
	cout<<"Y or N."<<endl;
	cin>>ans;
	return ans;
}

bool rananqua(int x, int y, int xqua, int yqua)
{
	if(x==xqua && y==yqua)
		return true;//ran an qua
	return false;
}
bool randequa(int xqua, int yqua, int toadox[],int toadoy[])
{
	for(int i=1;i<sl;i++)	
		if(toadox[i]==xqua && toadoy[i]==yqua)
			return true;	
	return false;
}
void taoqua(int &xqua, int &yqua, int toadox[],int toadoy[])
{	
	do
	{
		xqua=rand()%(59-2+1)+2;
		yqua=rand()%(19-2+1)+2;
	}
	while(randequa(xqua,yqua,toadox,toadoy)==true);
	gotoXY(xqua,yqua);
	cout<<"O";
}
bool ktra(int toadox[],int toadoy[])
{
	bool kt1=ranchamtuong(toadox[0], toadoy[0]);
	bool kt2=ranchamduoi(toadox, toadoy);
	if(kt1==true || kt2== true)
		return true;
	else return false;
	
}
bool ranchamtuong(int x,int y)
{
	if(x==1 || x==60 || y==1||y==20)
	return true;
	else return false;
}
bool ranchamduoi(int toadox[], int toadoy[])
{
	for(int i=1;i<sl;i++)
	{
		if(toadox[0]==toadox[i] && toadoy[0]==toadoy[i])
		return true;
		
	} return false;
}
void xulyran(int toadox[],int toadoy[],int x,int y,int &xqua, int &yqua)
{
	them(toadox,x);
	them(toadoy,y);
	
	if(rananqua(x, y,xqua, yqua)==false)
	
	{
		xoa(toadox,sl-1);
	xoa(toadoy,sl-1);
	}
	else
	{
		taoqua(xqua,yqua,toadox, toadoy);
	}
	veran(toadox,toadoy);
	
}
void them(int a[],int x)
{
	for(int i=sl;i>0;i--)
	{
		a[i]=a[i-1];
	}
	a[0]=x;
	sl++;
}
void xoa(int a[],int vt)
{
	for(int i=vt;i<sl;i++)
	{
		a[i]=a[i+1];
	}
	sl--;
}

void khoitaoran(int toadox[], int toadoy[])
{
	int x=30,y=10;
	for(int i=0;i<sl;i++)
	{
		toadox[i]=x;
		toadoy[i]=y;
		x--;
	}
}
void veran(int toadox[], int toadoy[])
{
	
	for(int i=0;i<sl;i++)
	{
		gotoXY(toadox[i],toadoy[i]);
		
		if(i==0)
		cout<<"X";
		else cout<<"x";
	}
}
void xoadulieucu(int toadox[], int toadoy[])
{
	
	for(int i=0;i<sl;i++)
	{
		gotoXY(toadox[i],toadoy[i]);
		
		
		cout<<" ";
		
	}
}
void khungngoai()// dai 60 rong 20
{
	int x=1,y=1;
	//ngang tren 
	for(int i=1;i<=60 ;i++)
	{
		x=i;
		y=1;
		gotoXY(x,y);
		cout<<"+";
	}
	//ngang duoi
	for(int i=1;i<=60;i++)
	{
		x=i;
		y=20;
		gotoXY(x,y);
		cout<<"+";
	}
	//doc trai
	for(int i=2;i<=19;i++)
	{
		x=1;
		y=i;
		gotoXY(x,y);
		cout<<"+";
	}
//doc phai
	for(int i=2;i<=19;i++)
	{
		x=60;
		y=i;
		gotoXY(x,y);
		cout<<"+";
	}	
}
