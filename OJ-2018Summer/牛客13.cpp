#include<iostream>
using namespace std;

unsigned long long place(int m,int n){
	if(n==1||m==0){
		return 1;	// ������0������
					// �ŵ�1�����ӻ���0��ƻ��
					// ���ʹ��m-n���������Ϊm-n=0�����Բ���Ҫ����ƻ����Ϊ1����� 
	}
	if(m<n)
		return place(m,m);	// ƻ��������������һ��������n-m�����ӿգ����Բ���Ҫ������Щ����
	else return place(m,n-1)+place(m-n,n); 
}
int main(){
	int n,m;
	while(cin>>m>>n&&!cin.eof()){
		cout<<place(m,n)<<endl;
	}
	return 0;
} 
