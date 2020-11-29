#include <iostream>
#include <vector>
#include <list>
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
		adj[src].push_back(dest);
	}
};
void DFSVisit(Graph g, int u, int& time, std::vector<Colors>& color, std::vector<int>& pi, std::vector<int>& d,std::vector<int>& f)
{
	d[u] = ++time;
	color[u] = Colors::GREY;
	for (auto v : g.adj[u])
	{
		if (color[v] == Colors::WHITE)
		{
			pi[v] = u;
			DFSVisit(g,v,time, color,pi,d,f);
		}
		else if (color[v] == Colors::GREY)
		{
			//BackEdge
			std::cout << "Backedge from " << u << " to " << v << std::endl;
		}
	}
	f[u] = ++time;
	color[u] = Colors::BLACK;
}

void dfs(Graph g)
{
	std::vector<Colors> colors(g.size, Colors::WHITE);
	std::vector<int> pi(g.size, -1);
	std::vector<int> d(g.size);
	std::vector<int> f(g.size);
	int time = 0;
	
	for (int r = 0; r < g.size; ++r)
	{
		if (colors[r] == Colors::WHITE)
		{
			pi[r] = -1;
			DFSVisit(g, r, time, colors,pi, d,f);
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
		std::cout << "d[" << i + 1 << "]=" << d[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < f.size();++i)
	{
		std::cout << "f[" << i + 1 << "]=" << f[i] << std::endl;
	}
}


int main()
{
	Graph g(6);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(2,6);
	g.addEdge(3,4);
	g.addEdge(4,1);
	g.addEdge(4,5);
	g.addEdge(5,2);
	g.addEdge(5,6);
	dfs(g);
}