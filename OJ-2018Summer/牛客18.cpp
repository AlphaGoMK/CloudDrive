#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int notprime[32000];
int main(){
	memset(notprime,0,sizeof(notprime));
	for(int i=2;i<32000;i++){
		for(int j=2;i*j<32000;j++){
			notprime[i*j]=1;
		}
	}
	notprime[1]=1;
	
	unsigned long long x;
	while(scanf("%ld",&x)!=EOF){
		int res=0,div=2;
		while(x!=1){
			while(div<32000&&(notprime[div]==1||x%div!=0)) div++;
			if(div>=32000) break;
			//cout<<x<<" "<<div<<endl;
			while(x!=1&&x%div==0){
				x=x/div;
				res++;
				//cout<<x<<endl;
			}
		}
		if(x!=1) res++;	// can't find a divider--> to a big prime. So the last number x a prime factor
						// ����һ�ܹؼ�. �������32000С��32000*32000�������������0-32000���Ҳ���divider��һ��Ϊ���� 
		printf("%ld\n",res);
	}
	return 0;
}
