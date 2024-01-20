#include<iostream>
#include<cstring>
using namespace std;

class RunAroundLake{
	public:
		RunAroundLake(){
			firstplace = new char[13];
			secondplace = new char[9];
			date = new char[8];
			strcpy(firstplace,"StudentCenter");
			strcpy(secondplace,"SouthLake");
			strcpy(date,"2014/1/1");
			time = 0;
		}
		RunAroundLake(const char *a,const char *b,const char *c,int d){
			firstplace = new char[strlen(a)+1];
			secondplace = new char[strlen(b)+1];
			date = new char[strlen(c)+1];
			strcpy(firstplace,a);
			strcpy(secondplace,b);
			strcpy(date,c);
			time = d;
		}
		void show(){
			cout<<firstplace<<" "<<secondplace<<" "<<date<<" "<<time<<endl;
		}
		~RunAroundLake(){
			delete[] firstplace;
			delete[] secondplace;
			delete[] date;
		}
	friend bool operator<(RunAroundLake &a,RunAroundLake &b);
	friend ostream& operator<<(ostream &out,RunAroundLake &a);
		
	private:
		char* firstplace;
		char* secondplace;
		char* date;
		int time;
};
bool operator<(RunAroundLake &a,RunAroundLake &b){
	if(a.time < b.time)return true;
	else return false;
}
ostream& operator<<(ostream &out,RunAroundLake &a){
	cout<<a.firstplace<<" "<<a.secondplace<<" "<<a.date<<" "<<a.time;
	return out;
}




int main(){

    char address1[40],address2[40],date[40];

    int second; //跑步总时长，用秒计算

    cin>>address1>>address2>>date>>second;

    RunAroundLake run1,run2(address1,address2,date,second); //创建run1和run2对象

    cin>>address1>>address2>>date>>second;

    RunAroundLake run3(address1,address2,date,second);   //创建run3对象

    run1.show();         //请设计show()成员函数，输出run1的相关信息

    cout<<run2<<endl;    //请重载<<运算符，输出run2的相关信息

    if(run3<run2)  //请重载<运算符，比较run3的跑步时长和run2的跑步时长，输出win的一方。

        cout<<"run3 win";

    else cout<<"run2 win";

    return 0;

}
