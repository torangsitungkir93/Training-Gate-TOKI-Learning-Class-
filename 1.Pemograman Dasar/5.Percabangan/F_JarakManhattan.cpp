#include<iostream>
using namespace std;
int main()
{
	int x1,x2,y1,y2,jarak;
	cin>>x1;
	cin>>y1;
	cin>>x2;
	cin>>y2;
	
	jarak=(x1-x2)+(y1-y2);
	if(jarak<0)
	{
		cout<<jarak*-1<<endl;
	}
	else
	{
		cout<<jarak<<endl;
	}
}
