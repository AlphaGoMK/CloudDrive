#include<iostream>
#include<cstring>
using namespace std;

unsigned long long dp[100010];
unsigned long long x[100010];
unsigned long long l1,l2,l3,c1,c2,c3;

unsigned long long getp(unsigned long long l){
	if(l<=l1) return c1;
	else if(l<=l2) return c2;
	else if(l<=l3) return c3;
	else return 0;
}
int main(){
	memset(dp,0,sizeof(dp));
	memset(x,0,sizeof(x));
	while(cin>>l1>>l2>>l3>>c1>>c2>>c3&&!cin.eof()){
		unsigned long long a,b,n;
		cin>>a>>b>>n;
		x[0]=0;
		for(int i=1;i<n;i++) cin>>x[i];
		// ��dp[a-1]����aλ�õĿ�����Ϊ0����aλ�ÿ�ʼ����dp������ͬʱ��ֹʹ��a֮ǰ�ĵ��dp����ֵ����֤һ���ǹ�a�㣬��a��ʼ��b 
		for(int i=a;i<=b-1;i++){
			unsigned long long min=1e9+1;
			for(int j=i-1;j>=a-1;j--){
				if(x[i]-x[j]>l3) break;
				if(getp(x[i]-x[j])+dp[j]<min) min=getp(x[i]-x[j])+dp[j];
				//cout<<i<<" "<<j<<" "<<min<<endl;
			}
			dp[i]=min;
		}
		cout<<dp[b-1]<<endl;
		
	}	
	return 0;
}
