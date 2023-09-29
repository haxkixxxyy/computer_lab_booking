#include"identity.h"

Identity::Identity(){
    name="none";
    id=-1;
    did=-1;
    password="none";
}

Identity::Identity(int _id,string _password,int _did,string _name):id(_id),password(_password),did(_did),name(_name)
{}

Identity::~Identity()
{
    for(int i=0;i<CRoom.size();i++){
        delete CRoom[i];
    }
}

inline string Identity::GetPassword()
{
    return password;
}

void Identity::ShowInfo()
{
    cout<<"id: "<<id<<"\t";
    cout<<"����: "<<password<<"\t";
    if(did==1) cout<<"Ȩ��: ѧ��\t";
    else if(did==2) cout<<"Ȩ��: ��ʦ\t";
            else cout<<"Ȩ��: ����Ա\t";
    cout<<"����: "<<name<<"\n";
}

void Identity::InitialRoom()
{
    ifstream is;
    is.open(COMPUTER_FILE);
    while(!is.is_open()){
        cout<<"�����ļ�������!\n";
        return;
    }
    int _comId,_MaxNum,_UsingNum;
    CRoom.clear();
    while(is>>_comId&&is>>_MaxNum&&is>>_UsingNum){
        ComputerRoom* temp=new ComputerRoom(_comId,_MaxNum,_UsingNum);
        CRoom.push_back(temp);
    }
    is.close();
}

vector<ComputerRoom *> &Identity::GetRoom()
{
    return CRoom;
}

ComputerRoom Identity::GetRoomInfo(int i)
{
    return *CRoom[i];
}
