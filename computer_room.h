#pragma once
#include<iostream>
#include<sstream>
#include"fstream"
#include"globe_file.h"
using namespace std;

class ComputerRoom
{
private:
    int ComId;
    int MaxNum;
    int UsingNum;
public:
    ComputerRoom(int _comId=-1,int _MaxNum=0,int _UsingNum=0);
    ~ComputerRoom();
    void ShowComputerInfo();
    int GetComID();
    int GetMaxNum();
    int GetUsingNum();
    void SaveComputer(int _Comid,int _MaxNum,int _UsingNum);
    //给机房计数加一
    void UsingNumPlus();
    //给机房计数减一
    void UsingNumMinus();
};