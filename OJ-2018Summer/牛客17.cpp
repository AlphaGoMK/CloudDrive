#include<iostream>
#include<vector>
using namespace std;

vector<string> proxy;
vector<string> server;
vector<int> show[1010]; // ��һ�γ��ֵ�ʱ�� 
int main(){
	int n,m;
	while(cin>>n&&!cin.eof()){
		string s;
		while(n--){
			cin>>s;
			proxy.push_back(s);
		}
		n=proxy.size();
		cin>>m;
		while(m--){
			cin>>s;
			server.push_back(s);
		}
		m=server.size();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(server[j]==proxy[i]){
					show[i].push_back(j);
				}
			}
			show[i].push_back(6000);	//ÿ�����������������֮���ٳ��֣�����λ��Ϊ����� 
		}
		
		//for(int i=0;i<n;i++){
		//	cout<<" "<<proxy[i]<<": ";
		//	for(int j=0;j<show[i].size();j++) cout<<show[i].at(j)<<" ";
		//	cout<<endl;
		//}
		
		int sum=0,ans=0;
		while(sum<m){
			int max=-1;
			for(int i=0;i<n;i++){
				//cout<<i<<": "<<show[i].front()<<endl;
				if(show[i].front()>max) max=show[i].front();
			}
			if(max==sum) {	// ���Ϊ0����ֻ��һ��ѡ�� ����� proxy=1 server=11111 
				ans=0;
				break;
			}
			sum=max;
			
			//cout<<"sum: "<<sum<<endl;
			
			ans++;
			for(int i=0;i<n;i++){
				vector<int>::iterator last=show[i].begin()+(show[i].size()-1);	// end�����һ��Ԫ�ص���һ��λ�ã�����erase��begin��end����ȫɾ
																				// begin(+size()-1)�������һ��Ԫ�صĵ�����λ�� 
				for(vector<int>::iterator it=show[i].begin();it!=show[i].end();it++){
					if(*it>=sum) {	// �Ҵ��ڵ���sum�ġ�ÿ��sumֵ��ʾ���ڸ�ѡ�Ǹ�λ��֮ǰ��proxy�����ڱ�ʾ��Ԫ��������Ӧѡλ��֮ǰ���֣������Ԫ������Ҫ�滻��Ԫ��
									// ���ڼ���Ҫѡ��6֮ǰӦ��ʹ���ĸ�������6��frontҲӦ�ú�sum��ͬ����ʾ������ּ�Ӧѡλ�ã���Ҫ�ܿ�6. �����ѡ��6������һ��sumλ���ǲ���� 
						last=it;
						break;
					}
				}
				
				show[i].erase(show[i].begin(),last);	// delete from [begin() to last-1], last is not included
				
				//cout<<" "<<proxy[i]<<": ";
				//for(int j=0;j<show[i].size();j++) cout<<show[i].at(j)<<" ";
				//cout<<endl;
			}
			//cout<<sum<<endl;
			
		}
		ans--;	//��һ�� 
		
		cout<<ans<<endl;
		
		for(int i=0;i<n;i++){
			show[i].clear();
		}
		proxy.clear();
		server.clear();
	}
}
