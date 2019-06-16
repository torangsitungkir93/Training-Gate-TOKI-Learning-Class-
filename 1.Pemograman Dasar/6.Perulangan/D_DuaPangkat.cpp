#include <iostream>
using namespace std;
int main()
{
	int n,max=1000,temp=2;
	cin>>n;
	while(n<max)
	{
		if(temp==n)
		{
			cout<<"ya";
			n=max;
		}
		else
		{
			if(temp>n)
			{
				cout<<"tidak"<<endl;
				n=max;
			}
			else if(temp<n){
					temp=temp*2;
			}
		}
	}
}
