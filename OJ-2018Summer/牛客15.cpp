#include<iostream>
#include<cstring>
using namespace std;

void Swap(char *a, char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
} 

void allrange(char *str, int start, int length){
	if(start==length-1){
		printf("%s\n",str);
	}
	else {
		for(int i=start;i<length;i++){
			Swap(&str[start],&str[i]);
			allrange(str,start+1,length);
			Swap(&str[start],&str[i]);	// ���±�start����ʼ�����Ŀ�ʼ�������ڽ�����һ���������������ٽ����ָ� 
		}
	}
}
// �����˳�򣬴�00����01����02�������Ӳ�����ʼ����b��ʼ����c��ʼ���Ӻ�ʼ��ǰ������������������������etc�� 
int main(){
	char a[10];
	cin>>a;
	allrange(a,0,strlen(a));
	return 0;
}
