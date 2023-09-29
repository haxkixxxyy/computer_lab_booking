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
    map<int,map<string,string> > orderData; //ԤԼ�ļ���¼
    int orderNum;
    pair<string,string> getPair(string str);
public:
    OrderFile();
    ~OrderFile();
    void initMap();//���ļ���ʼ����¼����
    void updateOrder();//���¼�¼�ļ�
    void showOrder(int i);
    vector<int> showOrderAtWaiting();//չʾ��������˵�ԤԼ,����ȡid
    map<int,map<string,string> >* getOrderData();//��ȡ��¼����
    int getOrderNum();//��ȡ��¼�����С
    vector<int> findOrderById(int id);//ͨ���û�id��ȡ��¼
};