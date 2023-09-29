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
        cout<<"注销成功!\n";
        break;
    case 1:
        cout<<"查看所有预约!\n";
        ShowAllOrder();
        break;
    case 2:
        cout<<"审核预约!\n";
        ValidOrder();
        break;
    default:
        cout<<"输入有误!\n";
        break;
    }
    system("pause");
    system("cls"); 
}

void Teacher::ShowAllOrder(){
    if(OFile.getOrderNum()==0){
        cout<<"无记录信息\n";
        return;
    }
    for(int i=0;i<OFile.getOrderNum();i++){
        OFile.showOrder(i);
    }
}

void Teacher::ValidOrder(){
    vector<int> temp=OFile.showOrderAtWaiting();
    if(!temp.size()){
        cout<<"无待审的记录\n";
        return ;
    }
    cout<<"请输入要审核的记录id:\n";
    int select;
    unordered_set<int> se;
    for(int x:temp) se.insert(x);
    while (true)
    {
        cin>>select;
        if(se.find(select)==se.end()){
            cout<<"输入有误请重新输入:\n";
        }
        else{
            cout<<"请输入审核意见:(1为通过,2为不通过)\n";
            char s;
            while(true){
                cin>>s;
                if(s=='1'||s=='2') break;
                cout<<"输入有误请重新输入:\n";
            }
            (*OFile.getOrderData())[select]["status"]=s+1;
            cout<<"审核成功\n";
            //更新机房信息
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