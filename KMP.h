#include <bits/stdc++.h>

class KMP {
	private:
		std::string _t;
		void computeLPSArray(string pat, int M, int* lps);
	public:
		KMP(const string &s);
		~KMP();
		unsigned count(const std::string &pat);
};