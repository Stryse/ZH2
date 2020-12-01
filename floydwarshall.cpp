#include <iostream>
#include <vector>
#include <limits>
#include <string>

#define V 4
#define INF 9999

template<typename T>
void printMatrix(const T& M, const std::string& name = "", int k = -1)
{
	std::cout << name << ((k != -1) ? std::to_string(k+1) : "")  << std::endl;
	for (int i = 0; i < M.size(); ++i)
		{
			std::cout << "[\t";
			for (int j = 0; j < M.size(); ++j)
			{
				if (M[i][j] != INF)
					std::cout << M[i][j] << "\t";
				else 
					std::cout << "INF\t";
			}
			std::cout << "]" << std::endl;
		}
	std::cout << std::endl;
}

int FloydMarshall(std::vector<std::vector<int>> A)
// int FloydMarshall(int A[][V])
{
	int n = A.size();
	std::vector<std::vector<int>> D(V,std::vector<int>(V));
	std::vector<std::vector<int>> pi(V,std::vector<int>(V));

	//SETUP
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			D[i][j] = A[i][j];
			if (i != j && A[i][j] < INF)
			{
				pi[i][j] = i + 1;
			}
			else
				pi[i][j] = 0;
		}
	}
	
	//F-W
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
					{
						std::cout << "Neg cycle with node: " << i+1 << std::endl;
						return i;
					}
				}
			}
		}
		std::cout << "================== K: " << k+1 << " ==================" << std::endl << std::endl;
		printMatrix<>(D,"D",k);
		printMatrix<>(pi,"Pi",k);
		std::cout << std::endl;
	}
	std::cout << "============= FINISH RESULT ==============" << std::endl << std::endl;
	printMatrix<>(D,"D");
	printMatrix<>(pi,"Pi");
	
	return -1;
}
  

int main()
{										   // a    b     c   d
    std::vector<std::vector<int>> graph = { { 0,   1,   INF, 3  }, //a
											{ INF, 0,   INF, 1  }, //b
											{ 1,   2,   0,   INF}, //c
											{ INF, INF, 2,   0}    //d
										  };  
	
    // Print the solution  
    int res = FloydMarshall(graph);  
	// std::cout << res << std::endl;
}