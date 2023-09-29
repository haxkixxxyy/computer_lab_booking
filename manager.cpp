#include"manager.h"

Manager::Manager(){
}

Manager::Manager(int _id,string password,int _did,string _name):Identity(_id,password,_did,_name)
{
}

Manager::Manager(Identity *a):Identity(*a)
{
}

Manager::~Manager()
{
    for(int i=0;i<vUser.size();i++){
        delete vUser[i];
    }
}

void Manager::addPerson()
{
    ofstream os;
    os.open(USER_FILE,ios::out|ios::app);
    string _name,_password;
    int _id,_did;
    cout<<"请输入id:\n";
    cin>>_id;
    while(CheckIsRepeat(_id)){
        cout<<"id已经存在,请重新输入:\n";
        cin>>_id;
    }
    cout<<"请输入密码:\n";
    cin>>_password;
    cout<<"请输入类型:(1为学生,2为老师)\n";
    cin>>_did;
    while(_did!=1&&_did!=2){
        cout<<"输入有误,请重新输入:(1为学生,2为老师)\n";
        cin>>_did;
    }
    cout<<"请输入姓名:\n";
    cin>>_name;
    os<<_id<<"\t"<<_password<<"\t"<<_did<<"\t"<<_name<<"\n";
    cout<<"添加成功!\n";
}

void Manager::ShowPerson(){
    cout<<"所有用户信息如下:\n";
    for(int i=0;i<vUser.size();i++){
        vUser[i]->ShowInfo();
    }
}

void Manager::ShowComputer()
{
    for(int i=0;i<GetRoom().size();i++){
       GetRoom()[i]->ShowComputerInfo();
    }
}

void Manager::CleanFile(){
    ofstream os;
    os.open(ORDER_FILE,ios::trunc);
    cout<<"文件已清空!\n";
}

void Manager::SelectManager(int _flag)
{
    switch (_flag)
    {
    case 0:
        cout<<"注销成功!\n";
        break;
    case 1:
        cout<<"添加账号!\n";
        addPerson();
        break;
    case 2:
        cout<<"查看账号!\n";
        ShowPerson();
        break;
    case 3:
        cout<<"查看机房!\n";
        ShowComputer();
        break;
    case 4:
        cout<<"清空预约!\n";
        CleanFile();
        break;
    default:
        cout<<"输入有误!\n";
        break;
    }
    system("pause");
    system("cls"); 
}

bool Manager::CheckIsRepeat(int _id)
{
    for(int i=0;i<vUser.size();i++){
        if(vUser[i]->GetId()==_id) return true;
    }
    return false;
}


//初始化用户信息表
void Manager::InitialUser()  //不能放到构造函数中,因为中途可能会创造很多临时的manager变量
{
    ifstream is;
    is.open(USER_FILE);
    if(!is.is_open()){
        cout<<"用户文件不存在!\n";
        return;
    }
    string _name,_password;
    int _id,_did;
    vUser.clear(); //这个东西会导致内存泄漏,因此程序会闪退
    while(is>>_id,is>>_password,is>>_did,is>>_name){
        if(_did==1){
            Identity *temp=new Student(_id,_password,_did,_name);
            vUser.push_back(temp);
        }
        if(_did==2){
            Identity *temp=new Teacher(_id,_password,_did,_name);
            vUser.push_back(temp);
        }
        if(_did==3){
            Identity *temp=new Manager(_id,_password,_did,_name);
            vUser.push_back(temp);
        }
    }
}