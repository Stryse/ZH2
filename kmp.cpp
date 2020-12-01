#include <string>
#include <iostream>
#include <set>
#include <vector>


void init(std::vector<int>& lps, const std::string pat)
{
	   // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < pat.size()) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
void KMP(std::string str, std::string P, std::set<int>& S)
{
	int m = P.size();
	int n = str.size();
	std::vector<int> next(m);
	init(next, P);
	S.clear();
	
	for (int i = 0; i < m; ++i)
	{
		std::cout << "next[" << i + 1 << "] = " << next[i] << "\t";
	}

	std::cout << std::endl;
	

	int i, j;
	i = j = 0;
	std::cout << n << std::endl;
	while (i < n)
	{
		if (str[i] == P[j])
		{
			++i;
			++j;
			if (j == m)
			{
				S.insert(i-m + 1);
				j = next[j-1];
			}
		}
		else
		{
			// std::cout << j << std::endl;
			if (j == 0)
			{
				++i;
			}
			else 
			{
				j = next[j];
			}
		}
	}
}


int main()
{
	std::string str = "ABABABACA";
	std::string p = "ABABAC";
	std::set<int> S;
	KMP(str,p, S);
	for (auto it = S.begin(); it != S.end(); ++it)
	{
		auto k = S.extract(it);
		std::cout << k << "\t";
	}
	std::cout << std::endl;
}