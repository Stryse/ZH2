#include <iostream>
#include <vector>
#include <limits>


#define V 4
#define INF 9999

int FloydMarshall(int A[][V])
{
	int n = V;
	std::vector<std::vector<int>> D(V,std::vector<int>(V));
	std::vector<std::vector<int>> pi(V,std::vector<int>(V));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			D[i][j] = A[i][j];
			if (i != j && A[i][j] < INF)
			{
				pi[i][j] = i;
			}
			else
				pi[i][j] = 0;
		}
	}
	
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (D[i][j] > (D[i][k] + D[k][j]))
				{
					D[i][j] = D[i][k] + D[k][j];
					pi[i][j] = pi[k][j];
					if (i == j && D[i][i] < 0)
						return i;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (D[i][j] != INF)
					std::cout << "D" << k + 1 << "[" << i << "," << j << "]=" << D[i][j] << "\t";
				else 
					std::cout << "D" << k + 1 << "[" << i << "," << j << "]=INF\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
					std::cout << "Pi" << k + 1 << "[" << i << "," << j << "]=" << pi[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl << std::endl << std::endl;
	for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (D[i][j] != INF)
					std::cout << "D" << "[" << i << "," << j << "]=" << D[i][j] << "\t";
				else 
					std::cout << "D" << "[" << i << "," << j << "]=INF\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
					std::cout << "Pi" << "[" << i << "," << j << "]=" << pi[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	
	return -1;
}
  

int main()
{
    int graph[4][4] = { {0, 2, INF, 5},  
                        {INF, 0, 1, INF},  
                        {3, INF, 0, 1},  
                        {INF, 2, INF, 0}  
                    };  
	
    // Print the solution  
    int res = FloydMarshall(graph);  
	std::cout << res << std::endl;
}