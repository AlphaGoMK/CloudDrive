#include<iostream>
#include<cstring>
using namespace std;
//int p[100001],a[100001],t[100001];
//long long cnt;
//long long slen;
//int dfs(int nowpos,int len){
//	if(len==2){
//		int tmp=0;
//		for(int i=nowpos;i<slen;i++){
//			if(t[i]) tmp++;
//		}
//		cnt=(cnt+tmp%1000000007)%1000000007;
//		return 0;
//	}
//	else if(len==1){
//		for(int i=nowpos;i<slen;i++){
//			if(a[i]) dfs(i+1,2);
//		}
//	}
//	else {
//		for(int i=nowpos;i<slen;i++){
//			if(p[i]) dfs(i+1,1);
//		}
//	}
//	return 0;
//}
//
//int main(){
//	string s;
//	cin>>s;
//	slen=s.length();
//	memset(p,0,sizeof(p));
//	memset(a,0,sizeof(a));
//	memset(t,0,sizeof(t));
//	for(int i=0;i<s.length();i++){
//		if(s[i]=='P') p[i]=1;
//		else if(s[i]=='A') a[i]=1;
//		else t[i]=1;
//	}
//	dfs(0,0);
//	cout<<cnt<<endl;
//	
//}

// dfs �� TLE��ʹ����̨������ⷨ
// DP ÿ������P����P����++��
// ����A����pa����������P��������֮ǰ��p ���ϵ�ǰa�����µ�pa
// ����T��pat��������pa������֮ǰpa�����µ�t�����µ�pat
// local optim pa,p; global optim pat 
int main(){
	string s;
	cin>>s;
	long long p=0,pa=0,pat=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='P') p=(p+1)%1000000007;
		else if(s[i]=='A') pa=(pa+p%1000000007)%1000000007;
		else pat=(pat+pa%1000000007)%1000000007;
	}
	cout<<pat<<endl;
} 
