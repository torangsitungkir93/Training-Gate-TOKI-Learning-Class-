#include <iostream>
using namespace std;
int main()
{
	int n[5];
	
	for(int i=0;i<5;i++)
	{
		cin>>n[i];
	}
	
	cout<<endl;
	
	for(int i=4;i>=0;i--)
	{
		cout<<n[i]<<endl;
	}
}
