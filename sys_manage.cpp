#include"sys_manage.h"

SysManage::SysManage()
{
    nowUser=nullptr;
    flag=0;
}

SysManage::~SysManage()
{
    if(nowUser!=nullptr) delete nowUser;
}

void SysManage::MainMenu(){
	cout<<"==================��ӭ��½����ԤԼϵͳ==========="<<endl;
	cout<<"\t\t-------------------------"<<endl;
	cout<<"\t\t|\t1 ѧ����½\t|"<<endl;
	cout<<"\t\t|\t2 ��ʦ��½\t|"<<endl;
	cout<<"\t\t|\t3 ����Ա��½\t|"<<endl;
	cout<<"\t\t|\t0 �˳�ϵͳ\t|"<<endl;
	cout<<"\t\t-------------------------"<<endl;
	cout<<"�������½ѡ�";
}

bool SysManage::SelectUser(int _flag){
    switch (_flag)
    {
    case 0:
        cout<<"�˳�ϵͳ,��ӭ�´�ʹ��!\n";
        exit(EXIT_FAILURE);
        break;
    case 1:
        cout<<"����ѧ��ϵͳ!\n";
        flag=_flag;
        break;
    case 2:
        cout<<"������ʦϵͳ!\n";
        flag=_flag;
        break;
    case 3:
        cout<<"�������Աϵͳ!\n";
        flag=_flag;
        break;
    default:
        cout<<"��������!,����������\n";
        system("pause");
        system("cls");
        return false; //����������
    }
    system("pause");
    system("cls");
    return true;
}

void SysManage::StuMenu()
{
	cout<<"======================  ��ӭѧ������"<<nowUser->GetUseName()<<"��¼��  ======================"<<endl;
	cout<<"��ѡ�����Ĺ��ܣ�"<<endl;
	cout<<"\t\t --------------------------------------\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             1.����ԤԼ               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             2.�鿴����ԤԼ           |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             3.�鿴����ԤԼ           |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             4.ȡ��ԤԼ               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             0.ע����¼               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t --------------------------------------\n";
	cout<<"����������ѡ��"<<endl;
}

void SysManage::TeaMenu()
{
	cout<<"======================  ��ӭ��ʦ����"<<nowUser->GetUseName()<<"��¼��  ======================"<<endl;
	cout<<"��ѡ�����Ĺ��ܣ�"<<endl;
	cout<<"\t\t --------------------------------------\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             1.�鿴����ԤԼ           |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             2.���ԤԼ               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             0.ע����¼               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t --------------------------------------\n";
	cout<<"����������ѡ��"<<endl;
}

void SysManage::AddminMenu()
{
    cout<<"\t\t\t����Ա"<<nowUser->GetUseName()<<"��¼�ɹ�\n";
	cout<<"\t\t-------------------------------------------\n";
	cout<<"\t\t|                                          |\n";
    cout<<"\t\t|               1.����˺�                 |\n";
    cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               2.�鿴�˺�                 |\n";
	cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               3.�鿴����                 |\n";
	cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               4.���ԤԼ                 |\n";
	cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               0.ע����¼                 |\n";
	cout<<"\t\t-------------------------------------------\n";
	cout<<"���������ѡ��";
}

bool SysManage::Login()
{
    ifstream is;
    is.open(USER_FILE);
    int flag=true; //�жϵ�¼��û�гɹ�
    if(!is.is_open()){
        cout<<"�ļ������ڻ��ʧ��\n";
        flag=false;
    }
    else{   
        int _id;
        string _pwd,_name;
        cout<<"������id\n";
        cin>>_id;
        cout<<"����������\n";
        cin>>_pwd;
        if(Verify(_id,_pwd,is,_name)){
            if(flag==1){
                nowUser=new Student(_id,_pwd,flag,_name);
            }
            if(flag==2){
                nowUser=new Teacher(_id,_pwd,flag,_name);
            }
            if(flag==3){
                nowUser=new Manager(_id,_pwd,flag,_name);
            }            
        }
        else {
            cout<<"��¼ʧ��!\n";
            flag=false;
        }
    }
    system("pause");
    system("cls");
    is.close();
    return flag;
}

int SysManage::GetFlag()
{
    return flag;
}

Identity *SysManage::GetNowUser()
{
    return nowUser;
}

void SysManage::DeleteNowUser()
{
    delete nowUser;
    nowUser=nullptr;
}

//���id������,�������,��������,�Լ��Ľ�����
bool SysManage::Verify(int _id,string _pwd,ifstream &is,string &_name){
    int fid;
    string fpwd,fname;
    int fdid;
    while(is>>fid&&is>>fpwd&&is>>fdid&&is>>fname){
        if(fid==_id&&fpwd==_pwd){
            if(flag==fdid){
                _name=fname;
                cout<<"��֤�ɹ�\n";
                return true;
            }
            else cout<<"��¼Ȩ�޴���!\n";
        }
    }
    return false;
}