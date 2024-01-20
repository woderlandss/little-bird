#include<iostream>
#include<cstring>
using namespace std;

class String{
	char* stra;
	
	public:
		String(const char* str){
			stra = new char[strlen(str)+1];
			strcpy(stra,str);
		}
	friend bool operator>(String &a,String &b);
	friend ostream& operator<<(ostream &out,String &a);
};

bool operator>(String &a,String &b){
	if(strcmp(a.stra,b.stra)>0  )return true;
	else return false;
}

ostream& operator<<(ostream &out,String &a){
	cout<<a.stra;
	return out;
}
char* Min(char *a,char *b){
	if(strcmp(a,b)>0)return b;
	return a; 
}
template<typename T>
T& Min(T& a,T& b){
	if(a>b)return b;
	else return a;
}


int main()
{

  int x,y;

  double a,b;

  char c1[20],c2[20],c3[20],c4[20];

  cin>>x>>y;
    

  cout<<Min(x,y)<<endl;

  cin>>a>>b;

  cout<<Min(a,b)<<endl;

  cin>>c1>>c2;

  cout<<Min(c1,c2)<<endl;

  cin>>c3>>c4;

  String s1(c3),s2(c4);
  
  cout<<Min(s1,s2)<<endl;


  return 0;

}
