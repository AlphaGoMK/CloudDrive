#include<iostream>
#include<cstring>
using namespace std;
int res[10000];

int main(){
	
	int N;
	while(cin>>N&&!cin.eof()){
		if(N==0) {
			cout<<1<<endl;
			continue;
		}
		memset(res,0,sizeof(res));
		int len=1;	// ��ʼ����Ϊ1 
		res[0]=1;	// ���λΪ1����ȻһֱΪ0 
		for(int i=1;i<=N;i++){
			int over=0;
			for(int j=0;j<len;j++){	//  ÿ�γ˻�������10��Ϊ10�������ͽ�λover ���ܲ�ֹһλ��>10�� 
				res[j]=res[j]*i+over;
				over=res[j]/10;		// ֮ǰ�Ķ�λ��λ����Ҫ����ȫ���ۼ��������һλ��ȥ���� 
				res[j]=res[j]%10;
			}
			while(over>0){	// ��λȫ���ۼӵ����һλ��Ȼ����ȥ�����ȱ仯 
				res[len]=over%10;
				over/=10;
				len++;
			}
		}
		
		for(int i=len-1;i>=0;i--){
			cout<<res[i];
		}
		cout<<endl;
	}
}
