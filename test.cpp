#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class temp{
public:
    int x;
    temp(){
        x=1;
    }
};
class temp2:public temp{
private:
    vector<temp*> a;
public:
    void clear(){
        a.clear();
    }
};
int main(){
    temp* p;
    temp2* v=(temp2* )p;
    v->clear();
    int x;
    cin>>x;
    cout<<x;
    return 0;
}