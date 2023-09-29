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
    vector<ComputerRoom*> CRoom; //��������
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
    //չʾ������Ϣ
    void ShowInfo();
    //��ʼ����������
    void InitialRoom();
    //��ȡ���л�����Ϣ
    vector<ComputerRoom*>& GetRoom();
    //��ȡ����������Ϣ
    ComputerRoom GetRoomInfo(int i);
};