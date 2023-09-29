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
    int flag;  //��ǵ�ǰ�û����� 1ѧ�� 2��ʦ 3����Ա
    //������֤
    bool Verify(int _id,string _pwd,ifstream &is,string &_name);
    Identity* nowUser; //��ǰ�û�
public:
    //��ʼ��
    SysManage();
    //����
    ~SysManage();
    //���˵�
    void MainMenu();
    //�û�����ѡ��
    bool SelectUser(int _flag);
    //ѧ���˵�
    void StuMenu();
    //��ʦ�˵�
    void TeaMenu();
    //����Ա�˵�
    void AddminMenu();
    //��¼
    bool Login();
    //��õ�ǰ��Ȩ��
    int GetFlag();
    //��õ�ǰ�û�
    Identity* GetNowUser();
    //�˳���ǰ�û�
    void DeleteNowUser();
};