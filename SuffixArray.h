#include <bits/stdc++.h>

class SuffixArray {
	private:
        std::string _t;
        string_view _sv;
        std::vector<unsigned> _arr;
	public:
		SuffixArray(const std::string &s);
		~SuffixArray();
		unsigned count(const std::string &pat);
};