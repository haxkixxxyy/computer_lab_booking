#include"teacher.h"

Teacher::Teacher(){

}

Teacher::Teacher(int _id,string password,int _did,string _name):Identity(_id,password,_did,_name){

}

Teacher::Teacher(Identity *a):Identity(*a)
{
}

Teacher::~Teacher(){

}

OrderFile &Teacher::getOrderFile()
{
    return OFile;
}

void Teacher::SelectTeacher(int _flag)
{
    switch (_flag)
    {
    case 0:
        cout<<"ע���ɹ�!\n";
        break;
    case 1:
        cout<<"�鿴����ԤԼ!\n";
        ShowAllOrder();
        break;
    case 2:
        cout<<"���ԤԼ!\n";
        ValidOrder();
        break;
    default:
        cout<<"��������!\n";
        break;
    }
    system("pause");
    system("cls"); 
}

void Teacher::ShowAllOrder(){
    if(OFile.getOrderNum()==0){
        cout<<"�޼�¼��Ϣ\n";
        return;
    }
    for(int i=0;i<OFile.getOrderNum();i++){
        OFile.showOrder(i);
    }
}

void Teacher::ValidOrder(){
    vector<int> temp=OFile.showOrderAtWaiting();
    if(!temp.size()){
        cout<<"�޴���ļ�¼\n";
        return ;
    }
    cout<<"������Ҫ��˵ļ�¼id:\n";
    int select;
    unordered_set<int> se;
    for(int x:temp) se.insert(x);
    while (true)
    {
        cin>>select;
        if(se.find(select)==se.end()){
            cout<<"������������������:\n";
        }
        else{
            cout<<"������������:(1Ϊͨ��,2Ϊ��ͨ��)\n";
            char s;
            while(true){
                cin>>s;
                if(s=='1'||s=='2') break;
                cout<<"������������������:\n";
            }
            (*OFile.getOrderData())[select]["status"]=s+1;
            cout<<"��˳ɹ�\n";
            //���»�����Ϣ
            int comID=stoi((*OFile.getOrderData())[select]["room"]);
            auto temp=GetRoom();
            int i;
            for(i=0;i<temp.size();i++){
                if(temp[i]->GetComID()==comID) break;
            }
            ComputerRoom* temp2=GetRoom()[i];
            if(s=='2') temp2->UsingNumMinus();
            OFile.updateOrder();
            break;
        }
    }    
}