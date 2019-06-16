#include<iostream>
using namespace std;
int main()
{
	float n;
	int cek;
	
	cin>>n;
	cek=n;
	if(n%cek==0)
	{
		cout<<cek<<" "<<cek<<endl;
	}
	else if(n%cek<=0.5&&n%cek>0)
	{
		cout<<cek<<" "<<n;
	}
	else if(n%cek>0.5)
	{
		cout<<n<<" "<<cek;
	}
}

