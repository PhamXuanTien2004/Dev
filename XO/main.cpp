#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "mylib.h"
using namespace std;

void welcome();
char choose();
void userChoose(char ans);
void vehinh();
void tuongtren();
void tuongduoi();
void tuongtrai();
void tuongphai();
void doc1();
void doc2();
void ngang1();
void ngang2();
int main()
{
	welcome();
	char ans = choose();
	userChoose(ans);
	system("cls");
	vehinh();

	return 0;
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
	tuongduoi();
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
void userChoose(char ans)
{

	if (ans == 'X' || ans == 'x')
	{
		cout << "Ban chon X" << endl;
		cout << "Chung toi chon O" << endl;
	}
	else
	{
		cout << "Ban chon O" << endl;
		cout << "Chung toi chon X" << endl;
	}
}
char choose()
{
	cout << "Ban chon X hay O???   ";
	char ans;
	cin >> ans;
	while (ans != 'O' && ans != 'X' && ans != 'x' && ans != 'o')
	{
		cout << "Ban hay chon lai di." << endl;
		cout << "Ban chon X hay O???  ";
		cin >> ans;
	}
	return ans;
}
void welcome()
{
	gotoXY(10, 1);
	setColor(1);
	cout << "Chao mung da den voi X-O 3x3" << endl;
}
