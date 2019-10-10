#include<iostream>
#include <omp.h>
#include<string>

using namespace std;

int main(){
	
	/*inputing dimensions of matrices*/
	int row1,col1,row2,col2;
	cout<<"Rows of Matrix 1"<<endl;
	cin>>row1;
	cout<<"Cols of Matrix 1"<<endl;
	cin>>col1;
	cout<<"Rows of Matrix 2"<<endl;
	cin>>row2;
	cout<<"Cols of Matrix 2"<<endl;
	cin>>col2;
	
	
	if(col1!=row2){
		cout<<"With given sizes matrix multiplication is not possible"<<endl;
		return 0;
	}
	
	
	int m1[row1][col1];
	int m2[row2][col2];
	int finalm[row1][col2];
	
	
	cout<<"Enter elements for matrix 1"<<endl;
	    for(int i =0;i<row1;i++)
		{
		for(int j = 0;j<col1;j++)
		{
			cin>>m1[i][j];
		}
	}
	
	
	cout<<"Enter elements in Matrix 2 "<<endl;
	    for(int i = 0;i<row2;i++)
		{
		for(int j = 0;j<row2;j++)
		{
			cin>>m2[i][j];
		}
	}
	
	
	    for(int i = 0;i<row1;i++)
		{
		for(int j = 0;j<col2;j++)
		{
			finalm[i][j]=0;
		}
		cout<<endl;
	}
	
	#pragma omp parallel for collapse(2)
	         for(int i = 0;i<row1;i++)
			 {
		     for(int j = 0;j<col2;j++)
			 {
			  for(int k = 0;k<col1;k++)
			  {
				finalm[i][j]=finalm[i][j]+m1[i][k]*m2[k][j];
			}
		    }
	        }
	
	/*printing matrix 1*/
	    for(int i = 0;i<row1;i++)
		{
		for(int j = 0;j<col1;j++)
		{
			cout<<m1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//printing matrix 2
	for(int i = 0;i<row2;i++)
	{
		for(int j = 0;j<col2;j++)
		{
			cout<<m2[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//printing resultant matrix
	for(int i = 0;i<row1;i++)
	{
		for(int j = 0;j<col2;j++)
		{
			cout<<finalm[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
