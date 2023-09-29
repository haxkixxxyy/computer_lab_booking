#include<iostream>
#include"sys_manage.h"
using namespace std;

int main(){
    SysManage sm;
    int select;
    while(true){
        sm.MainMenu();
        cin>>select;
        if(!sm.SelectUser(select)) {
            continue; //�������˵�
        }
        if(!sm.Login()){
            continue; //��¼ʧ�ܷ������˵�
        }
        if(sm.GetFlag()==1){    //ѧ��
            while(true){
                int select1;
                Student* now=new Student(sm.GetNowUser());
                now->InitialRoom();
                now->getOrderFile().initMap();//��ʼ����¼��
                sm.StuMenu();
                cin>>select1;
                now->SelectStudent(select1);
                if(select1==0){
                    sm.DeleteNowUser();
                    break;
                }
            }
        }
        if(sm.GetFlag()==2){//��ʦ
            while(true){
                int select2;
                Teacher* now=new Teacher(sm.GetNowUser());
                now->InitialRoom();
                now->getOrderFile().initMap();//��ʼ����¼��
                sm.TeaMenu();
                cin>>select2;
                now->SelectTeacher(select2);
                if(select2==0){
                    sm.DeleteNowUser();
                    break;
                }
            }            
        }
        if(sm.GetFlag()==3){    //����Ա
            while(true){
                int select3;
                Manager* now=new Manager(sm.GetNowUser());
                now->InitialUser();
                now->InitialRoom();
                sm.AddminMenu();
                cin>>select3;
                now->SelectManager(select3);
                if(select3==0){
                    sm.DeleteNowUser();
                    break;
                }
            }
        }                   
    }
    return 0;
}