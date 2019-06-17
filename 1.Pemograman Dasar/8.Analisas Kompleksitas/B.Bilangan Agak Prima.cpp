#include <iostream>
using namespace std;
int main()
{
	int n,arr,cek=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cek=0;
		cin>>arr;
		for(int j=1;j<=arr;j++)
		{
			if(arr%j==0)
			{
				cek=cek+1;
			}
		}
		if(cek>4)
		{
			cout<<"BUKAN"<<endl;
		}
		else
		{
			cout<<"YA"<<endl;
		}
	}
}

