#pragma once
#include <stdio.h>
#include <conio.h>
#include <ctime> /*thư viện hỗ trợ tgian thực*/
#include "windows.h"
#define KEY_NONE -1
// tim toa do x cua con tro
int whereX()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi ))
    return csbi.dwCursorPosition.X;
    return -1;
}
// tim toa do y cua con tro
int whereY()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi ))
    return csbi.dwCursorPosition.X;
    return -1;
}
// dich con tro den toa do x y
void gotoXY(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos={x,y};
    hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,Cursor_an_Pos);
}
// dat mau chu
void setColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffet_info;
    GetConsoleScreenBufferInfo(hConsoleOutput,&screen_buffet_info);

    WORD wAttributes = screen_buffet_info.wAttributes;
    color &= 0x000F;
    wAttributes &=0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);

}
// lm an di con tro 
void showCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
// tra ve ma phim ng dung bam 
int inputKey()
{
    if(_kbhit())
    {
        int key=_getch();
        if(key=224)
        {
            key=_getch();
            return key+1000;
        }
        return key;
    } 
}
