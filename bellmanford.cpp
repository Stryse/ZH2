#include <queue>
#include <iostream>
#include <vector>
#include <limits>
#define INF std::numeric_limits<int>::max()

int QBasedBellmanFord(std::vector<std::vector<int>>& M, int s)
{
	int n = M.size();
	std::vector<int> D(M.size());
	std::vector<int> Pi(M.size());
	std::vector<int> E(M.size());
	std::vector<bool> InQ(M.size());
	
	for (int i = 0; i < n; ++i)
	{
		D[i] = INF;
		pi[i] = 0;
		InQ[i] = false;
	}
	D[s] = 0;
	E[s] = 0;
	std::queue<int> Q;
	Q.add(s);
	
	while (!Q.empty())
	{
		int u = Q.top();
		Q.pop();
		InQ[s] = false;
		for (int i = 0; i < n; ++i)
		{
			
		}
	}
	return -1;
} 


int main()
{
	
}
