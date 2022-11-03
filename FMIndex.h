#include <bits/stdc++.h>

class FMIndex {
	private:
		std::vector<char> F;
		std::vector<char> L;
		std::vector<int> SA_Sample;
		std::vector<int> Checkpoits; //no es necesaria para realizar count
		std::string _t;
	public:
		FMIndex(const std::string &s);
		~FMIndex();
		unsigned count(const std::string &pat);
};