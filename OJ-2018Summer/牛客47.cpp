#include<iostream>
using namespace std;

struct node{
	int k;
	node* l;
	node* r;
};

int main(){
	int N;
	while(cin>>N&&!cin.eof()){
		node *t,*fa,*now;
		t=NULL,fa=NULL,now=NULL;
		while(N--){
			int tmp;
			cin>>tmp;
			if(t==NULL){
				t=new node;
				t->k=tmp;
				t->l=t->r=NULL;
				cout<<-1<<endl;
			}
			else {
				now=t;
				while(now!=NULL) {	// �ǵó�ʼ��ΪNULL����ʹ��now!=NULL�жϣ�����Ϊ����ֵ 
					if(tmp<now->k) {
						fa=now;
						now=now->l;
					}
					else {
						fa=now;
						now=now->r;
					}
				}
				now=new node;
				now->k=tmp;
				now->l=now->r=NULL;
				if(tmp>fa->k){
					fa->r=now;
				}
				else fa->l=now;
				
				cout<<fa->k<<endl;
			}
			
		}
	}
	return 0;
}
