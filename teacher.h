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
    //Ĭ�Ϲ���
    Teacher();
    //�вι���
    Teacher(int _id, string password, int _did, string _name);
    //ת������
    Teacher(Identity *a);
    //����
    ~Teacher();
    //��ȡԤԼ��¼�ļ�
    OrderFile& getOrderFile();
    //�û�����ѡ��
    void SelectTeacher(int _flag);
    //�鿴����ԤԼ
    void ShowAllOrder();
    //���ԤԼ
    void ValidOrder();
};