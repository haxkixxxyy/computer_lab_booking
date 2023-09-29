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
    //Ĭ�Ϲ���
    Student();
    // �вι���
    Student(int _id, string password, int _did, string _name);
    //ת������
    Student(Identity *a);
    //����
    ~Student();
    //����ԤԼ
    void ApplyOrder();
    //�鿴�ҵ�ԤԼ
    void ShowMyOrder();
    //�鿴����ԤԼ
    void ShowAllOrder();
    //ȡ��ԤԼ
    void CancelOrder();
    //�û�����ѡ��
    void SelectStudent(int _flag);
    //��õ�ǰ��¼��
    OrderFile& getOrderFile();
};