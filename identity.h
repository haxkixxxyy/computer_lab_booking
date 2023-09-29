#pragma once
#include<iostream>
#include<string>
#include"fstream"
#include"globe_file.h"
#include"computer_room.h"
#include<vector>
using namespace std;

class Identity
{
private:
    int id;
    string password;
    int did;
    string name;
    vector<ComputerRoom*> CRoom; //机房数组
public:
    Identity();
    Identity(int _id,string _password,int _did,string _name);
    ~Identity();
    virtual string GetPassword();
    virtual string GetUseName(){
        return name;
    }
    virtual int GetId(){
        return id;
    }
    //展示基本信息
    void ShowInfo();
    //初始化机房数组
    void InitialRoom();
    //获取所有机房信息
    vector<ComputerRoom*>& GetRoom();
    //获取单个机房信息
    ComputerRoom GetRoomInfo(int i);
};