#pragma once
#include"identity.h"
#include"order_file.h"
#include<unordered_set>
using namespace std;

class Teacher:public Identity
{
private:
    OrderFile OFile;
public:
    //默认构造
    Teacher();
    //有参构造
    Teacher(int _id, string password, int _did, string _name);
    //转换函数
    Teacher(Identity *a);
    //析构
    ~Teacher();
    //获取预约记录文件
    OrderFile& getOrderFile();
    //用户操作选择
    void SelectTeacher(int _flag);
    //查看所有预约
    void ShowAllOrder();
    //审核预约
    void ValidOrder();
};