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
    cout<<"��������ʱ������һ������\n";
    cout<<"��������ҪԤԼ��ʱ��(��һ: 1, �ܶ�: 2, ����: 3, ���� : 4, ����: 5,)\n";
    cin>>day;
    while(day<1||day>5){
        cout<<"�������!����������:\n";
        cin>>day;
    }
    cout<<"������ԤԼʱ���:(1Ϊ����,2Ϊ����)\n";
    cin>>interval;
    while(interval<1||interval>2){
        cout<<"�������!����������:\n";
        cin>>interval;
    }
    for(int i=0;i<GetRoom().size();i++){
        ComputerRoom* temp=GetRoom()[i];
        temp->ShowComputerInfo();
    }
    cout<<"ѡ�����:\n";
    int flag=0;
    while(true){
        cin>>room;
        int i;
        for(i=0;i<GetRoom().size();i++){
            ComputerRoom* temp=GetRoom()[i];
            if(temp->GetComID()==room){
                if(temp->GetMaxNum()==temp->GetUsingNum()){
                    cout<<"������������!����������\n";
                }
                else{
                    flag=i;
                    break;
                }
            }
        }
        if(i!=GetRoom().size()) break;
        cout<<"�����ڸû���!����������:\n";
    }
    ComputerRoom* temp=GetRoom()[flag];
    ofstream os;
    os.open(ORDER_FILE,ios::app);
    //���»�����Ϣ
    temp->UsingNumPlus();
    cout<<"ԤԼ�ɹ�!�����!\n";
    os<<"data:"<<day<<" ";
    os<<"interval:"<<interval<<" ";
    os<<"id:"<<GetId()<<" ";
    os<<"����:"<<GetUseName()<<" ";
    os<<"room:"<<room<<" ";
    os<<"status:"<<1<<"\n";//1�������,2����˳ɹ�,3��ԤԼʧ��,0ȡ��ԤԼ
    os.close();
}

void Student::ShowMyOrder(){
    vector<int> temp=OFile.findOrderById(this->GetId());
    if(temp.size()==0){
        cout<<"�޼�¼��Ϣ\n";
        return;
    }
    for(int i=0;i<temp.size();i++){
        OFile.showOrder(temp[i]);
    }
}

void Student::ShowAllOrder(){
    if(OFile.getOrderNum()==0){
        cout<<"�޼�¼��Ϣ\n";
        return;
    }
    for(int i=0;i<OFile.getOrderNum();i++){
        OFile.showOrder(i);
    }
}

void Student::CancelOrder(){
    ShowMyOrder();
    cout<<"������Ҫȡ��ԤԼ�ļ�¼id:\n";
    int select;
    vector<int> temp=OFile.findOrderById(this->GetId());
    unordered_set<int> se;
    for(int x:temp) se.insert(x);
    while (true)
    {
        cin>>select;
        if(se.find(select)==se.end()){
            cout<<"������������������:\n";
        }
        else{
            if((*OFile.getOrderData())[select]["status"]=="0"||(*OFile.getOrderData())[select]["status"]=="3"){
                cout<<"�ü�¼ԤԼʧ�ܻ����Ѿ�ȡ��,����������:\n";
            }
            else{
                (*OFile.getOrderData())[select]["status"]="0";
                cout<<"ȡ��ԤԼ�ɹ�\n";
                //���»�����Ϣ
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
        cout<<"ע���ɹ�!\n";
        break;
    case 1:
        cout<<"����ԤԼ!\n";
        ApplyOrder();
        break;
    case 2:
        cout<<"�鿴����ԤԼ!\n";
        ShowMyOrder();
        break;
    case 3:
        cout<<"�鿴����ԤԼ!\n";
        ShowAllOrder();
        break;
    case 4:
        cout<<"ȡ��ԤԼ!\n";
        CancelOrder();
        break;
    default:
        cout<<"��������!\n";
        break;
    }
    system("pause");
    system("cls"); 
}

OrderFile& Student::getOrderFile()
{
    return OFile;
}
