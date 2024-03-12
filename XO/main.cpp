#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include "mylib.h"

// Nhap ten 
// chon X hoac O
// chon o dien
// ket qua 

using namespace std;
int yhoi=5;
const char X = 'X';
const char O = 'O';
string player1;
string player2;
int ans;
char matran[3][3];

void welcome();

void choose();
void userChoose(char ans);

// ve hinh
void vehinh();
void tuongtren();
void tuongduoi();
void tuongtrai();
void tuongphai();
void doc1();
void doc2();
void ngang1();
void ngang2();
void danhso();

// dien X O vao bang va ma tran 
void hoi(string name,char a);
void dienbang(char a,int ans);
void dienmatran(int ans,char a);

//kiemtra
bool kiemtra(char a);
int main()
{
	welcome();
	choose();	
	system("cls");	
	vehinh();
	int i=1;
	while(i<=9)
	{
		if(i%2==1)
		{
			hoi(player1,X);
			dienbang(X,ans);
			dienmatran(ans,X);
		}
		hoi(player2,O);
		dienbang(O,ans);
		dienmatran(ans,O);
	}
	
	
	return 0;
}
bool kiemtra()
{
	
}
void dienmatran(int ans,char a)
{
	if(ans==1)
	matran[0][0]=a;
	if(ans==2)
	matran[0][1]=a;
	if(ans==3)
	matran[0][2]=a;
	if(ans==4)
	matran[1][0]=a;
	if(ans==5)
	matran[1][1]=a;
	if(ans==6)
	matran[1][2]=a;
	if(ans==7)
	matran[2][0]=a;
	if(ans==8)
	matran[2][1]=a;
	if(ans==9)
	matran[2][2]==a;
}
void dienbang (char a,int ans)
{
	if(ans==1)
	{
		gotoXY(7,12);
	cout<<a;
	}
	if(ans==2)
	{
		gotoXY(11,12);
	cout<<a;
	}
	if(ans==3)
	{
		gotoXY(15,12);
	cout<<a;
	}
	if(ans ==4)
	{
		gotoXY(7,16);
	cout<<a;
	}
	if(ans==5)
	{
		gotoXY(11,16);
	cout<<a;
	}
	if(ans==6)
	{
		gotoXY(15,16);
	cout<<a;
	}
	if(ans==7)
	{
		gotoXY(7,20);
	cout<<a;
	}
	if(ans==8)
	{
		gotoXY(11,20);
	cout<<a;
	}
	if(ans==9)
	{
		gotoXY(15,20);
	cout<<a;
	}
	
}
void hoi(string name, char a)
{
	gotoXY(20,yhoi);
	cout<<name<<" Ban dien "<<a<<" vao dau? ";
	cin>>ans;
	while(ans <1 || ans>9)
	{
		cout<<name<<" Ban chon lai di."<<endl;
		cout<<name<<" Ban dien "<<a<<" vao dau? ";
		cin>>ans;
	}
	yhoi++;
}
void vehinh()
{

	tuongtren();
	tuongtrai();
	tuongphai();
	doc1();
	doc2();
	ngang1();
	ngang2();
	danhso();
	tuongduoi();
}
void danhso()
{
	gotoXY(7,12);
	cout<<"1";
	gotoXY(11,12);
	cout<<"2";
	gotoXY(15,12);
	cout<<"3";
	gotoXY(7,16);
	cout<<"4";
	gotoXY(11,16);
	cout<<"5";
	gotoXY(15,16);
	cout<<"6";
	gotoXY(7,20);
	cout<<"7";
	gotoXY(11,20);
	cout<<"8";
	gotoXY(15,20);
	cout<<"9";

}
void ngang2()
{
	int x = 5, y = 18;
	for (int i = 0; i <= 11; i++)
	{
		x++;
		gotoXY(x, y);
		cout << "*";
	}
}
void ngang1()
{
	int x = 5, y = 14;
	for (int i = 0; i <= 11; i++)
	{
		x++;
		gotoXY(x, y);
		cout << "*";
	}
}
void doc2()
{
	int x = 13, y = 10;
	for (int i = 0; i <= 10; i++)
	{
		y++;
		gotoXY(x, y);
		cout << "*";
	}
}
void doc1()
{
	int x = 9, y = 10;
	for (int i = 0; i <= 10; i++)
	{
		y++;
		gotoXY(x, y);
		cout << "*";
	}
}
void tuongphai()
{
	int x = 17, y = 10;
	for (int i = 0; i <= 10; i++)
	{
		y++;
		gotoXY(x, y);
		cout << "*";
	}
}
void tuongtrai()
{
	int x = 5, y = 10;
	for (int i = 0; i <= 10; i++)
	{
		y++;
		gotoXY(x, y);
		cout << "*";
	}
}
void tuongduoi()
{
	int x = 4, y = 22;
	for (int i = 0; i <= 12; i++)
	{
		x++;
		gotoXY(x, y);
		cout << "*";
	}
	cout << endl;
}
void tuongtren()
{
	int x = 4, y = 10;
	for (int i = 0; i <= 12; i++)
	{
		x++;
		gotoXY(x, y);
		cout << "*";
	}
}


void choose()
{
    cout << "Player 1: ";
    cin >> player1;
    cout << "Player 2: ";
    cin >> player2;

    char choice;
    cout << player1 << ", choose X or O: ";
    cin >> choice;
    userChoose(choice);
}

void userChoose(char ans)
{
    if (ans == 'X' || ans == 'x')
    {
        cout << player1 << " chose "<<ans << endl;
        cout << player2 << " will be "<< O << endl;
    }
    else
    {
        cout << player1 << " chose "<<ans << endl;
        cout << player2 << " will be "<<X << endl;
    }
}

void welcome()
{
    gotoXY(10, 1);
    setColor(1);
    cout << "Welcome to Tic-Tac-Toe 3x3" << endl;
}

