#include <iostream>
#include <vector>


void warshall(std::vector<std::vector<int>> A)
{
	int size = A.size();
	std::vector<std::vector<bool>> T(A.size(), std::vector<bool>(A.size()));
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			T[i][j] = A[i][j];
		}
		T[i][i] = 1;
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << "T0[" << i + 1 << "," << j+1 << "]=" << T[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	
	
	for (int k = 0; k < size; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				T[i][j] = T[i][j] || (T[i][k] && T[k][j]);
				std::cout << "T" << k+1 << "[" << i + 1 << "," << j+1 << "]=" << T[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << "T[" << i + 1 << "," << j+1 << "]=" << T[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
int main()
{
	std::vector<std::vector<int>> graph = 
	{
		{0,1,0,0},
		{0,0,0,1},
		{0,1,0,0},
		{0,0,1,0}
	};
	warshall(graph);
	
	return 0;
}