#include "computer_room.h"

ComputerRoom::ComputerRoom(int _comId, int _MaxNum, int _UsingNum):ComId(_comId),MaxNum(_MaxNum),UsingNum(_UsingNum)
{
}

ComputerRoom::~ComputerRoom()
{
}

void ComputerRoom::ShowComputerInfo()
{
    cout<<"����id: "<<ComId<<"\t"
        <<"�������: "<<MaxNum<<"\t"
        <<"��ǰʹ����: "<<UsingNum<<"\n";
}

int ComputerRoom::GetComID()
{
    return ComId;
}

int ComputerRoom::GetMaxNum()
{
    return MaxNum;
}

int ComputerRoom::GetUsingNum()
{
    return UsingNum;
}

void ComputerRoom::SaveComputer(int _Comid, int _MaxNum, int _UsingNum)
{
    string fComid,fMaxNum;
    int fUsingNum;
    fstream fs;
    fs.open(COMPUTER_FILE);
    string temp;//�ݴ��ַ���
    while(fs>>fComid&&fs>>fMaxNum&&fs>>fUsingNum){
        if(fComid==to_string(_Comid)) fUsingNum=_UsingNum; 
        temp=temp+fComid+'\t'+fMaxNum+'\t'+to_string(fUsingNum)+'\n';           
    }
    fs.close();
    ofstream os;
    os.open(COMPUTER_FILE);
    os<<temp;
    os.close();
}

void ComputerRoom::UsingNumPlus()
{
    UsingNum++;
    SaveComputer(ComId,MaxNum,UsingNum);
}

void ComputerRoom::UsingNumMinus()
{
    UsingNum--;
    SaveComputer(ComId,MaxNum,UsingNum);
}
