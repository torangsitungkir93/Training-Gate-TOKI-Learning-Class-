#include <iostream>
using namespace std;
int main(){

		int arr,modus,modusterbesar;
		cin>>arr;
		int n[arr],cek[arr];
		for(int i=0;i<arr;i++)
		{
			cek[i]=0;
			cin>>n[i];
			for(int j=0;j<arr;j++)
			{
				if(n[i]==n[j])
				{
					cek[i]=cek[i]+1;
				}
			}
			cek[0]=modus;
			if(modus<cek[i])
			{
				modus=cek[i];
				modusterbesar=n[i];
			}
			else if(modus==cek[i])
			{
				if(n[i]>modusterbesar)
				{
					modusterbesar=n[i];
				}
			}
		}
		
		cout<<modusterbesar;		
		return 0;
	}
