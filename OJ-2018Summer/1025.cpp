/*
���������ǽ�ÿ�������������뵽һ�����������У�ʵʱ���򣬴ӳ���Ϊ1����n��n+1���������У�������չ���ȣ���һ����һ�����м�ǰ�벿�������벿������ ����������ж��Ƿ�Ϊ�������� 
�鲢������ÿk��������������ٵ�������Ȼ��k*=2�����k>nֹͣ 
ֻҪģ��������̣�֪��������������к�b������ȣ��ڽ���һ������ ���ǽ�� 
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int N;
	while(cin>>N&&!cin.eof()){
		int a[101],b[101];
		for(int i=0;i<N;i++) cin>>a[i];
		for(int i=0;i<N;i++) cin>>b[i];
		int ordlen=1;
		for(int i=0;i<N-1;i++){
			if(b[i]<=b[i+1]) ordlen++;
			else break;
		}
		
		int flag=0;
		for(int i=ordlen;i<N;i++) {
			if(a[i]!=b[i]) {
				flag=1;
				break;
			}
		}
		
		if(flag==0) cout<<"Insertion Sort"<<endl;
		else cout<<"Merge Sort"<<endl;
		
		if(flag==0){
			sort(a,a+ordlen+1,cmp);
		}
		else{
			
			int ok=0,len=2;
			while(!ok){
				ok=1;
				for(int i=0;i<N;i++){
					if(a[i]!=b[i]) ok=0;
				}
				
				// one more time
				for(int i=0;i<N/len;i++){
					sort(a+i*len,a+(i+1)*len,cmp);
				}
				sort(a+N-N%len,a+N,cmp);	
				len*=2;
			}
			
			
		}
		
		
		for(int i=0;i<N;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}


