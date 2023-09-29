#pragma once
#include"identity.h"
#include"fstream"
#include"globe_file.h"
#include"order_file.h"
#include<unordered_set>
using namespace std;

class Student:public Identity
{
private:
    OrderFile OFile;
public:
    //默认构造
    Student();
    // 有参构造
    Student(int _id, string password, int _did, string _name);
    //转换函数
    Student(Identity *a);
    //析构
    ~Student();
    //申请预约
    void ApplyOrder();
    //查看我的预约
    void ShowMyOrder();
    //查看所有预约
    void ShowAllOrder();
    //取消预约
    void CancelOrder();
    //用户操作选择
    void SelectStudent(int _flag);
    //获得当前记录表
    OrderFile& getOrderFile();
};