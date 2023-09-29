#pragma once
#include"identity.h"
#include"globe_file.h"
#include"student.h"
#include"teacher.h"
#include<vector>
#include<string>
#include"computer_room.h"
using namespace std;

class Manager:public Identity
{
private:
    //查重
    bool CheckIsRepeat(int _id);
    vector<Identity*> vUser; //用户数组
public:
    //默认构造
    Manager();
    //有参构造
    Manager(int _id,string password,int _did,string _name);
    //析构
    Manager(Identity *a); //转换函数,避免强制转换
    ~Manager();
    //增加账号
    void addPerson();
    //查看账号
    void ShowPerson();
    //查看机房信息
    void ShowComputer();
    //清空预约记录
    void CleanFile();
    //用户类型选择
    void SelectManager(int _flag);
    //初始化用户数组
    void InitialUser();
};