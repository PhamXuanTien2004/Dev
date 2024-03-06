#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char X='X';
const char O='O';
const char empty=' ';
const char Tie='T';
const char NO_ONE='N';

void introducation();
char askYesNo(string question);
int askNumber(string number, int hight, int low=0);
char humanpiece();
char opponent(char piece);
void disBoard(const vector<char>&board);
char winner (const vector<char>&board);
bool isLegal(const vector<char>&board,int move);
int humanMove(const vector<char>&board,char human);
int computerMove(const vector<char>&board,char computer);
void announcewinner(char winner, char human,char cumputer);
