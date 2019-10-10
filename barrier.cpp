#include<bits/stdc++.h>
#include <mpi.h>
#include<string>

using namespace std;

void pr_barrier(int rank, int size);


int main(int argc, char *argv[])
{
	int size,rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    	MPI_Comm_size(MPI_COMM_WORLD, &size);
	cout<<"Hello I am rank "<<rank<<" processing before barrier."<<endl;
	pr_barrier(rank,size);
	cout<<"Hello I am rank "<<rank<<" processing after barrier."<<endl;
	MPI_Finalize();
	
}

void pr_barrier(int rank, int size)
{
	int d=5;
	int l,r;
	l = rank*2 +1;
	r = rank*2 +2;
	if(l<size)
	{
	MPI_Recv(&d, 1, MPI_INT, l, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);	
	}
	if(r<size)
	{
	MPI_Recv(&d, 1, MPI_INT, r, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);	
	}
	int p;
	if(rank!=0)
	{
		p=(rank-1)/2;
		MPI_Send(&d, 1, MPI_INT, p, 0, MPI_COMM_WORLD);
		MPI_Recv(&d, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	}
	else
	{
		for(int i=1;i<size;i++)
		{
			MPI_Send(&d, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		}
	}
}

