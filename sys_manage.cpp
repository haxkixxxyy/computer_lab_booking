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
	cout<<"==================欢迎登陆机房预约系统==========="<<endl;
	cout<<"\t\t-------------------------"<<endl;
	cout<<"\t\t|\t1 学生登陆\t|"<<endl;
	cout<<"\t\t|\t2 教师登陆\t|"<<endl;
	cout<<"\t\t|\t3 管理员登陆\t|"<<endl;
	cout<<"\t\t|\t0 退出系统\t|"<<endl;
	cout<<"\t\t-------------------------"<<endl;
	cout<<"请输入登陆选项：";
}

bool SysManage::SelectUser(int _flag){
    switch (_flag)
    {
    case 0:
        cout<<"退出系统,欢迎下次使用!\n";
        exit(EXIT_FAILURE);
        break;
    case 1:
        cout<<"进入学生系统!\n";
        flag=_flag;
        break;
    case 2:
        cout<<"进入老师系统!\n";
        flag=_flag;
        break;
    case 3:
        cout<<"进入管理员系统!\n";
        flag=_flag;
        break;
    default:
        cout<<"输入有误!,请重新输入\n";
        system("pause");
        system("cls");
        return false; //返回主界面
    }
    system("pause");
    system("cls");
    return true;
}

void SysManage::StuMenu()
{
	cout<<"======================  欢迎学生代表："<<nowUser->GetUseName()<<"登录！  ======================"<<endl;
	cout<<"请选择您的功能："<<endl;
	cout<<"\t\t --------------------------------------\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             1.申请预约               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             2.查看自身预约           |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             3.查看所有预约           |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             4.取消预约               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             0.注销登录               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t --------------------------------------\n";
	cout<<"请输入您的选择："<<endl;
}

void SysManage::TeaMenu()
{
	cout<<"======================  欢迎老师代表："<<nowUser->GetUseName()<<"登录！  ======================"<<endl;
	cout<<"请选择您的功能："<<endl;
	cout<<"\t\t --------------------------------------\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             1.查看所有预约           |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             2.审核预约               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t|             0.注销登录               |\n";
	cout<<"\t\t|                                      |\n";
	cout<<"\t\t --------------------------------------\n";
	cout<<"请输入您的选择："<<endl;
}

void SysManage::AddminMenu()
{
    cout<<"\t\t\t管理员"<<nowUser->GetUseName()<<"登录成功\n";
	cout<<"\t\t-------------------------------------------\n";
	cout<<"\t\t|                                          |\n";
    cout<<"\t\t|               1.添加账号                 |\n";
    cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               2.查看账号                 |\n";
	cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               3.查看机房                 |\n";
	cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               4.清空预约                 |\n";
	cout<<"\t\t|                                          |\n";
	cout<<"\t\t|               0.注销登录                 |\n";
	cout<<"\t\t-------------------------------------------\n";
	cout<<"请输入你的选择：";
}

bool SysManage::Login()
{
    ifstream is;
    is.open(USER_FILE);
    int flag=true; //判断登录有没有成功
    if(!is.is_open()){
        cout<<"文件不存在或打开失败\n";
        flag=false;
    }
    else{   
        int _id;
        string _pwd,_name;
        cout<<"请输入id\n";
        cin>>_id;
        cout<<"请输入密码\n";
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
            cout<<"登录失败!\n";
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

//解决id不存在,密码错误,输入问题,以及改进代码
bool SysManage::Verify(int _id,string _pwd,ifstream &is,string &_name){
    int fid;
    string fpwd,fname;
    int fdid;
    while(is>>fid&&is>>fpwd&&is>>fdid&&is>>fname){
        if(fid==_id&&fpwd==_pwd){
            if(flag==fdid){
                _name=fname;
                cout<<"验证成功\n";
                return true;
            }
            else cout<<"登录权限错误!\n";
        }
    }
    return false;
}