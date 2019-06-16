#include <iostream>
using namespace std;
int main()
{
	int n,m,sensor;
	cin>>n;
	cin>>m;
	sensor=m;
	for(int i=1;i<=n;i++)
	{
		if(i==m)
		{
			cout<<"* ";
			m=m+sensor;
		}
		else
		{
			cout<<i<<" ";
		}
	}
}
