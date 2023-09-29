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
    //����
    bool CheckIsRepeat(int _id);
    vector<Identity*> vUser; //�û�����
public:
    //Ĭ�Ϲ���
    Manager();
    //�вι���
    Manager(int _id,string password,int _did,string _name);
    //����
    Manager(Identity *a); //ת������,����ǿ��ת��
    ~Manager();
    //�����˺�
    void addPerson();
    //�鿴�˺�
    void ShowPerson();
    //�鿴������Ϣ
    void ShowComputer();
    //���ԤԼ��¼
    void CleanFile();
    //�û�����ѡ��
    void SelectManager(int _flag);
    //��ʼ���û�����
    void InitialUser();
};