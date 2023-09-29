#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include"globe_file.h"
using namespace std;

class OrderFile
{
private:
    map<int,map<string,string> > orderData; //预约文件记录
    int orderNum;
    pair<string,string> getPair(string str);
public:
    OrderFile();
    ~OrderFile();
    void initMap();//由文件初始化记录数组
    void updateOrder();//更新记录文件
    void showOrder(int i);
    vector<int> showOrderAtWaiting();//展示所有在审核的预约,并获取id
    map<int,map<string,string> >* getOrderData();//获取记录数组
    int getOrderNum();//获取记录数组大小
    vector<int> findOrderById(int id);//通过用户id获取记录
};