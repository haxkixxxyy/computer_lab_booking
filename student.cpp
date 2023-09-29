#include"student.h"

Student::Student(){

}

Student::Student(int _id,string password,int _did,string _name):Identity(_id,password,_did,_name){
}

Student::Student(Identity *a):Identity(*a)
{
}

Student::~Student(){
    
}

void Student::ApplyOrder(){
    int day,interval,room;
    cout<<"机房开放时间是周一至周五\n";
    cout<<"请输入你要预约的时间(周一: 1, 周二: 2, 周三: 3, 周四 : 4, 周五: 5,)\n";
    cin>>day;
    while(day<1||day>5){
        cout<<"输入错误!请重新输入:\n";
        cin>>day;
    }
    cout<<"请输入预约时间段:(1为上午,2为下午)\n";
    cin>>interval;
    while(interval<1||interval>2){
        cout<<"输入错误!请重新输入:\n";
        cin>>interval;
    }
    for(int i=0;i<GetRoom().size();i++){
        ComputerRoom* temp=GetRoom()[i];
        temp->ShowComputerInfo();
    }
    cout<<"选择机房:\n";
    int flag=0;
    while(true){
        cin>>room;
        int i;
        for(i=0;i<GetRoom().size();i++){
            ComputerRoom* temp=GetRoom()[i];
            if(temp->GetComID()==room){
                if(temp->GetMaxNum()==temp->GetUsingNum()){
                    cout<<"机房容量已满!请重新输入\n";
                }
                else{
                    flag=i;
                    break;
                }
            }
        }
        if(i!=GetRoom().size()) break;
        cout<<"不存在该机房!请重新输入:\n";
    }
    ComputerRoom* temp=GetRoom()[flag];
    ofstream os;
    os.open(ORDER_FILE,ios::app);
    //更新机房信息
    temp->UsingNumPlus();
    cout<<"预约成功!审核中!\n";
    os<<"data:"<<day<<" ";
    os<<"interval:"<<interval<<" ";
    os<<"id:"<<GetId()<<" ";
    os<<"姓名:"<<GetUseName()<<" ";
    os<<"room:"<<room<<" ";
    os<<"status:"<<1<<"\n";//1是审核中,2是审核成功,3是预约失败,0取消预约
    os.close();
}

void Student::ShowMyOrder(){
    vector<int> temp=OFile.findOrderById(this->GetId());
    if(temp.size()==0){
        cout<<"无记录信息\n";
        return;
    }
    for(int i=0;i<temp.size();i++){
        OFile.showOrder(temp[i]);
    }
}

void Student::ShowAllOrder(){
    if(OFile.getOrderNum()==0){
        cout<<"无记录信息\n";
        return;
    }
    for(int i=0;i<OFile.getOrderNum();i++){
        OFile.showOrder(i);
    }
}

void Student::CancelOrder(){
    ShowMyOrder();
    cout<<"请输入要取消预约的记录id:\n";
    int select;
    vector<int> temp=OFile.findOrderById(this->GetId());
    unordered_set<int> se;
    for(int x:temp) se.insert(x);
    while (true)
    {
        cin>>select;
        if(se.find(select)==se.end()){
            cout<<"输入有误请重新输入:\n";
        }
        else{
            if((*OFile.getOrderData())[select]["status"]=="0"||(*OFile.getOrderData())[select]["status"]=="3"){
                cout<<"该记录预约失败或者已经取消,请重新输入:\n";
            }
            else{
                (*OFile.getOrderData())[select]["status"]="0";
                cout<<"取消预约成功\n";
                //更新机房信息
                int comID=stoi((*OFile.getOrderData())[select]["room"]);
                auto temp=GetRoom();
                int i;
                for(i=0;i<temp.size();i++){
                    if(temp[i]->GetComID()==comID) break;
                }
                ComputerRoom* temp2=GetRoom()[i];
                temp2->UsingNumMinus();
                OFile.updateOrder();
                break;
            }
        }
    }
}

void Student::SelectStudent(int _flag)
{
    switch (_flag)
    {
    case 0:
        cout<<"注销成功!\n";
        break;
    case 1:
        cout<<"申请预约!\n";
        ApplyOrder();
        break;
    case 2:
        cout<<"查看自身预约!\n";
        ShowMyOrder();
        break;
    case 3:
        cout<<"查看所有预约!\n";
        ShowAllOrder();
        break;
    case 4:
        cout<<"取消预约!\n";
        CancelOrder();
        break;
    default:
        cout<<"输入有误!\n";
        break;
    }
    system("pause");
    system("cls"); 
}

OrderFile& Student::getOrderFile()
{
    return OFile;
}
