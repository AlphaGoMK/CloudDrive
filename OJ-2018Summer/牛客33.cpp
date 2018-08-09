//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int partion(int a[],int low,int high){
//	int pivot=a[low];
//	int pl=low,ph=high;
//	while(low<high){
//		while(low<high&&a[high]>=pivot) high--;	// ����ȡlow==high����Ϊ�����ȵĻ��������ͬһ��λ�û���low����low��Ȼ�� �ٱ�pivot�滻�������ݡ����Բ���ȡ�� 
//		a[low]=a[high];
//		while(low<high&&a[low]<=pivot) low++;
//		a[high]=a[low];
//	}
//	a[low]=pivot;
//	//cout<<pl<<" "<<ph<<": ";
//	//for(int i=pl;i<=ph;i++) cout<<a[i]<<" ";
//	//cout<<endl;
//	return low;
//}
//
//int quicksort(int a[],int low,int high){
//    if(low>=high) return 0;
//    int mid=partion(a,low,high);
//    quicksort(a,low,mid-1);
//    quicksort(a,mid+1,high);
//}
//
//int main(){
//	int n;
//	int a[1010];
//	while(cin>>n&&!cin.eof()){
//		for(int i=0;i<n;i++) cin>>a[i];
//		int query;
//		cin>>query;
//		quicksort(a,0,n-1);
//		//for(int i=0;i<n;i++) cout<<a[i]<<" ";
//		cout<<a[query-1]<<endl;
//	}
//	return 0;
//}
// 

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> s;

int partion(vector<int> &a,int low,int high){
	int pivot=a[low];
	int pl=low,ph=high;
	while(low<high){
		while(low<high&&a[high]>=pivot) high--;	// ����ȡlow==high����Ϊ�����ȵĻ��������ͬһ��λ�û���low����low��Ȼ�� �ٱ�pivot�滻�������ݡ����Բ���ȡ�� 
		a[low]=a[high];
		while(low<high&&a[low]<=pivot) low++;
		a[high]=a[low];
	}
	a[low]=pivot;
	//cout<<pl<<" "<<ph<<": ";
	//for(int i=pl;i<=ph;i++) cout<<a[i]<<" ";
	//cout<<endl;
	return low;
}

int quicksort(vector<int> &a,int low,int high){
    if(low>=high) return 0;
    int mid=partion(a,low,high);
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}

int solve(int a[],int len,int n){
	int visit[1005];
	memset(visit,0,sizeof(visit));
	for(int i=0;i<len;i++){
		if(!visit[a[i]]){
			s.push_back(a[i]);
			visit[a[i]]=1;
		}
	}
	quicksort(s,0,s.size()-1);
	return s[n-1];
	
}
int main(){
    int n;
    while(cin>>n&&!cin.eof()){
        int a[1005];
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int query;
        cin>>query;
        cout<<solve(a,n,query)<<endl;
        s.clear();
    }
}

