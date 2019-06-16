#include<iostream>
using namespace std;
int main()
{
	int x;
	
	cin>>x;
	if(x>=100000)
	{
		cout<<"RatusRibuan"<<endl;
	}
	else if(x>10000&&x<=99999)
	{
		cout<<"Puluhribuan"<<endl;
	}
	else if(x>999&&x<=9999)
	{
		cout<<"Ribuan"<<endl;
	}
	else if(x>99&&x<=9999)
	{
		cout<<"Ratusan"<<endl;
	}
	else if(x>9&&x<=99)
	{
		cout<<"Puluhan"<<endl;
	}
	else if(x>0&&x<=9)
	{
		cout<<"Satuan"<<endl;
	}
	
}

