#include <iostream>
using namespace std;
int main()
{
	int n,value,min,max;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>value;
		if(i==0)
		{
			min=value;
			max=value;
		}
		if(max<value)
		{
			max=value;
		}
		if(min>value)
		{
			min=value;
		}
	}
	
	cout<<max<<" "<<min<<endl;
}
