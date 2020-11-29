#include <iostream>
#include <vector>
#include <list>
#include <stack>

enum class Colors
{
	WHITE,
	GREY,
	BLACK
};
class Graph
{
	public:
	std::vector<std::list<int>>  adj;
	int size;
	
	Graph(int k)
	{
		size = k;
		adj = *new std::vector<std::list<int>>(size, std::list<int>());
	}
	void addEdge(int src, int dest)
	{
		--src;
		--dest;
		auto it = adj[src].begin();
		while (it != adj[src].end() && *it < dest)
			++it;
		// adj[src].push_back(dest);
		adj[src].insert(it, dest);
	}
	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			std::cout << i + 1 << " --> ";
			for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
				std::cout << *it + 1 << " ; ";
			std::cout << std::endl;
		}
	}
	
	void DFSVisit(int u, int& time, std::vector<Colors>& color, std::vector<int>& pi, std::vector<int>& d,std::vector<int>& f, std::stack<int> * top = nullptr)
	{
		d[u] = ++time;
		color[u] = Colors::GREY;
		for (auto v : adj[u])
		{
			if (color[v] == Colors::WHITE)
			{
				pi[v] = u;
				DFSVisit(v,time, color,pi,d,f, top);
				std::cout << "Faél from " << u + 1 << " to " << v + 1 << std::endl;
			}
			else if (color[v] == Colors::GREY)
			{
				//BackEdge
				std::cout << "Backedge from " << u + 1 << " to " << v + 1 << std::endl;
			}
			else if (color[v] == Colors::BLACK && d[u] < d[v])
			{
				std::cout << "Előreél from " << u + 1 << " to " << v+1 << std::endl;
			}
			else if (color[v] == Colors::BLACK && d[u] > d[v])
			{
				std::cout << "Keresztél from " << u + 1 << " to " << v+1 << std::endl;
			}
		}
		f[u] = ++time;
		color[u] = Colors::BLACK;
		if (top)
			top->push(u);
	}
	
	void dfs(std::stack<int>* top = nullptr)
	{
		std::vector<Colors> colors(size, Colors::WHITE);
		std::vector<int> pi(size, -1);
		std::vector<int> d(size, -1);
		std::vector<int> f(size, -1);
		int time = 0;
		
		for (int r = 0; r < size; ++r)
		{
			if (colors[r] == Colors::WHITE)
			{
				pi[r] = -1;
				DFSVisit(r, time, colors,pi, d,f, top);
			}
			
		}
		std::cout << std::endl;
		for (int i = 0; i < pi.size();++i)
		{
			std::cout << "PI[" << i + 1 << "]=" << pi[i] << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < d.size();++i)
		{
			std::cout << "d[" << i + 1 << "]=" << d[i] << "\t\tf[" << i+1 << "]=" << f[i] << std::endl;
		}
	}
	
};




void topologikusszar(Graph g)
{
	std::stack<int> stack;
	g.dfs(&stack);
	
	while (!stack.empty())
	{
		std::cout << stack.top() + 1 << "  ";
		stack.pop();
	}
	std::cout << std::endl;
}

int main()
{
	Graph g(6);

	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(6,2);
	// g.addEdge(1,3);
	// g.addEdge(1,2);
	// g.addEdge(2,3);
	// g.addEdge(2,6);
	// g.addEdge(3,4);
	// g.addEdge(4,5);
	// g.addEdge(4,1);
	// g.addEdge(5,2);
	// g.addEdge(5,6);
	// g.print();
	// topologikusszar(g);
	g.dfs();
}