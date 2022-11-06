#include <bits/stdc++.h>

class FMIndex
{
private:
	int _offset;
	std::string_view _sv;
	std::vector<std::pair<char, int>> F;
	std::vector<char> L;
	std::map<char, int> C;
	std::map<char, std::vector<int>> OCC;
	// std::vector<int> SA_Sample; //no es necesaria para realizar count
	// std::vector<int> Checkpoits;
	std::string _t;

public:
	FMIndex(const std::string &s, int _offset);
	~FMIndex();
	unsigned count(const std::string &pat);
};