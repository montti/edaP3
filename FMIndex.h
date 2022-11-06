#include <bits/stdc++.h>

struct comp
{
	template <typename T>

	// Comparator function
	bool operator()(const T &l, const T &r) const
	{
		return l.first > r.first;
	}
};

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