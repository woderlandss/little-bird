#include<iostream>
#include<cstring>
using namespace std;

class Student{
	char *name;
	int score;
	
	public:
	Student(){
		
	}
	Student(const char* names,int a){
		name = new char[strlen(names)+1];
		strcpy(name,names);
		score =a;
	}
		friend bool operator>(Student &a,Student &b);
		friend ostream& operator<<(ostream& out,Student &a);
};
bool operator>(Student &a,Student &b){
	if(a.score>b.score){
		return true;
	}
	else return false;
}
ostream& operator<<(ostream& out,Student &a){
	cout<<a.name<<" "<<a.score<<endl;
	return out;
}

template<typename T>
void Bubble_Sort(T a[],int n){
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				T temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1]= temp;
			}
		}
	}
}
template<typename T>
void outputArray(T a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}



int main( ) { //主函数

const int A_COUNT = 8, B_COUNT = 8, C_COUNT = 3;

int a[A_COUNT] = { 7, 8, 1, 6, 5, 4, 3, 2 };

double b[B_COUNT] = { 5.5, 2.2, 8.8, 4.4, 1.1, 6.6, 7.7, 3.3 }; 

Student c[C_COUNT]={{"Zhao",90},{"Qian",88},{"Sun",66}};  



cout << " a array contains:" << endl;

Bubble_Sort<int>(a, A_COUNT);

outputArray<int>(a, A_COUNT);//调用函数模板



cout << " b array contains:" << endl;

Bubble_Sort<double>(b, B_COUNT);

outputArray<double>(b, B_COUNT);//调用函数模板



cout << " c array contains:" << endl;

Bubble_Sort<Student>(c, C_COUNT);

outputArray<Student>(c, C_COUNT);cout<<endl;



return 0;

}
