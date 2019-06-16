#include <iostream>
using namespace std;
int main()
{
	int n,m=10;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i==m)
		{
			m=m+10;
			continue;
		}
		else if(i==42)
		{
			cout<<"ERROR"<<endl;
			break;
		}
		else
		{
			cout<<i<<endl;
		}
	}
}
