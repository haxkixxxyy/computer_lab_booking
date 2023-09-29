#include "order_file.h"

//构造皆获取预约记录
OrderFile::OrderFile()
{
}

//获取切片
pair<string,string> OrderFile::getPair(string str){
    int pos=str.find(':');
    string a=str.substr(0,pos);
    string b=str.substr(pos+1);
    return make_pair(a,b);      
}

OrderFile::~OrderFile()
{
    
}

void OrderFile::initMap()
{
    orderNum=0;
    ifstream is;
    is.open(ORDER_FILE);
    string data,interval,id,name,room,status;
    while(is>>data&&is>>interval&&is>>id&&is>>name&&is>>room&&is>>status){ 
        map<string,string> m;
        m.insert(getPair(data));
        m.insert(getPair(interval));
        m.insert(getPair(id));
        m.insert(getPair(name));
        m.insert(getPair(room));
        m.insert(getPair(status));
        orderData.insert(make_pair(orderNum++,m));
    }
}

void OrderFile::updateOrder()
{
    ofstream os;
    os.open(ORDER_FILE);
    for(auto it:orderData){
        for(auto its:it.second){
            os<<its.first<<':'<<its.second<<' ';
        }
        os<<endl;
    }
}

//展示一条记录
void OrderFile::showOrder(int i)
{
    if(i>=orderNum){
        cout<<"编号出错"<<endl;
        return;
    }
    map<string,string> m=orderData[i];
    cout<<"编号:"<<'\t'<<i<<endl;
    for(map<string,string>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<':'<<it->second<<'\t';
    }
    cout<<endl;
}

vector<int> OrderFile::showOrderAtWaiting()
{
    vector<int> temp;
    for(int i=0;i<orderData.size();i++){
        for(auto it:orderData[i]){
            if(it.first=="status"&&it.second=="1"){
                showOrder(i);
                temp.push_back(i);
            }
        }
    }
    return temp;
}

map<int, map<string, string>> *OrderFile::getOrderData()
{
    return &orderData;
}

int OrderFile::getOrderNum()
{
    return orderNum;
}

vector<int> OrderFile::findOrderById(int id)
{
    vector<int> temp;
    for(int i=0;i<orderNum;i++){
        if(orderData[i].find("id")->second==to_string(id)) temp.push_back(i);
    }
    return temp;
}
