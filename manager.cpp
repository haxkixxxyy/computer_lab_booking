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
    cout<<"������id:\n";
    cin>>_id;
    while(CheckIsRepeat(_id)){
        cout<<"id�Ѿ�����,����������:\n";
        cin>>_id;
    }
    cout<<"����������:\n";
    cin>>_password;
    cout<<"����������:(1Ϊѧ��,2Ϊ��ʦ)\n";
    cin>>_did;
    while(_did!=1&&_did!=2){
        cout<<"��������,����������:(1Ϊѧ��,2Ϊ��ʦ)\n";
        cin>>_did;
    }
    cout<<"����������:\n";
    cin>>_name;
    os<<_id<<"\t"<<_password<<"\t"<<_did<<"\t"<<_name<<"\n";
    cout<<"��ӳɹ�!\n";
}

void Manager::ShowPerson(){
    cout<<"�����û���Ϣ����:\n";
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
    cout<<"�ļ������!\n";
}

void Manager::SelectManager(int _flag)
{
    switch (_flag)
    {
    case 0:
        cout<<"ע���ɹ�!\n";
        break;
    case 1:
        cout<<"����˺�!\n";
        addPerson();
        break;
    case 2:
        cout<<"�鿴�˺�!\n";
        ShowPerson();
        break;
    case 3:
        cout<<"�鿴����!\n";
        ShowComputer();
        break;
    case 4:
        cout<<"���ԤԼ!\n";
        CleanFile();
        break;
    default:
        cout<<"��������!\n";
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


//��ʼ���û���Ϣ��
void Manager::InitialUser()  //���ܷŵ����캯����,��Ϊ��;���ܻᴴ��ܶ���ʱ��manager����
{
    ifstream is;
    is.open(USER_FILE);
    if(!is.is_open()){
        cout<<"�û��ļ�������!\n";
        return;
    }
    string _name,_password;
    int _id,_did;
    vUser.clear(); //��������ᵼ���ڴ�й©,��˳��������
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