#include <iostream>
using namespace std;
int main(){
		
		int n,m;
		int matriks[100][100];
		cin>>n;
		cin>>m;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>matriks[i][j];
			}
		}
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<matriks[j][i]<<" ";
			}
			cout<<endl;
		}
		
		return 0;
	}
