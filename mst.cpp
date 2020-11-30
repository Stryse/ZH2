#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class MyQueue : public std::priority_queue<T, Container, Compare>
{
public:
    typedef typename
        std::priority_queue<
        T,
        Container,
        Compare>::container_type::const_iterator const_iterator;
	
	MyQueue(const Compare& comp) : std::priority_queue<T, Container, Compare>(comp)
	{}
    const_iterator find(const T&val) const
    {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first!=last) {
            if (*first==val) return first;
            ++first;
        }
        return last;
    }
	const_iterator end()
	{
		return this->c.cend();
	}
};


class Graph
{
public:
	int size;
	std::vector<std::vector<int>> matrix;
	
	Graph(int k)
	{
		size = k;
		matrix = *new std::vector<std::vector<int>>(k, std::vector<int>(k, std::numeric_limits<int>::min()));
	}
	void addEdge(int src, int dest, int weight = 1)
	{
		--src;
		--dest;
		matrix[src][dest] = weight;
		matrix[dest][src] = weight;
	}
	void print()
	{
		std::cout << "from/to\t";
		for (int i = 0; i < size;++i)
		{
			std::cout << i+1 << "\t";
		}
		std::cout << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << i+1 << "\t";
			for (int j = 0; j < size; ++j)
			{
				if (matrix[i][j] != std::numeric_limits<int>::min())
					std::cout << matrix[i][j] << "\t";
				else std::cout << "0\t";
			}
			std::cout << std::endl;
		}
	}
	void Prim(int r)
	{
		--r;
		std::vector<int> c(size, std::numeric_limits<int>::max());
		std::vector<int> p(size, 0);
		c[r] = 0;
		auto comp = [&](int lhs, int rhs) { return c[lhs] < c[rhs]; };
		MyQueue<int, std::vector<int>, decltype(comp)> q(comp);
		for (int i = 0; i < size; ++i)
		{
			if (i != r)
				q.push(i);
		}
		// while (!q.empty())
		// {
			// std::cout << q.top() + 1 << std::endl;
			// q.pop();
		// }
		int u = r;
		while (!q.empty())
		{
			for (auto v : matrix[u])
			{
				if (v != std::numeric_limits<int>::min())
				{
					if (q.find(v) != q.end())
					{
						if (c[v] > matrix[u][v])
						{
							c[v] = matrix[u][v];
							p[v] = u;
						}
					}
				}
			}
			u = q.top();
			q.pop();
		}
		for (int i = 0; i < size; ++i)
		{
			std::cout << "d[" << i + 1 << "]=" << c[i] << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << "Pi[" << i + 1 << "]=" << p[i] << std::endl;
		}
	}
};
int main()
{
	Graph g(6);
	g.addEdge(1,2,6);
	g.addEdge(1,3,1);
	g.addEdge(2,3,4);
	g.addEdge(2,4,6);
	g.addEdge(2,5,2);
	g.addEdge(2,6,3);
	g.addEdge(3,4,3);
	g.addEdge(3,5,1);
	g.addEdge(4,5,1);
	g.addEdge(4,6,6);
	g.addEdge(5,6,5);
	g.Prim(1);
}