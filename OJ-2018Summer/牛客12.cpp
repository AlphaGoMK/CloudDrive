#include<iostream>
using namespace std;
int main(){
	long long n;
	while(cin>>n&&!cin.eof()){
		long long dp=0,x,global=-0x7fffffffffffffff;
		cin>>x;
		dp=x;
		global=dp;
		for(int i=1;i<n;i++){
			cin>>x;
			if(x>dp+x) dp=x;	// dp ��ʾ��n��β��������кͣ�һ������n���ֲ����ţ���ʹ��global��¼���ȫ���������к� 
			else dp=dp+x;
			
			if(dp>global) global=dp;
		}
		cout<<global<<endl;
	}
	return 0;
}
