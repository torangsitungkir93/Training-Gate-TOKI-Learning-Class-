#include <iostream>
using namespace std;
int main()
{
	int n,nilai=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" ";
		nilai=nilai+i+1;
	}
	cout<<endl;
	cout<<nilai<<endl;
}
