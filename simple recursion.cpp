#include<iostream>
using namespace std;
int c=90;
int recursion(int w){
	 cout << c<<endl;
	 if(c ==9)return -1;
	 recursion(c--);
	
}
int main(){
	recursion(c);
	return 0;
}
