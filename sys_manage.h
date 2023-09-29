#pragma once
#include<iostream>
#include<vector>
#include"fstream"
#include"globe_file.h"
#include"manager.h"
#include"teacher.h"
#include"student.h"
#include"identity.h"
using namespace std;

class SysManage
{
private:
    int flag;  //标记当前用户类型 1学生 2老师 3管理员
    //密码验证
    bool Verify(int _id,string _pwd,ifstream &is,string &_name);
    Identity* nowUser; //当前用户
public:
    //初始化
    SysManage();
    //析构
    ~SysManage();
    //主菜单
    void MainMenu();
    //用户类型选择
    bool SelectUser(int _flag);
    //学生菜单
    void StuMenu();
    //老师菜单
    void TeaMenu();
    //管理员菜单
    void AddminMenu();
    //登录
    bool Login();
    //获得当前的权限
    int GetFlag();
    //获得当前用户
    Identity* GetNowUser();
    //退出当前用户
    void DeleteNowUser();
};