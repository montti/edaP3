#include <bits/stdc++.h>

class KMP {
	private:
		std::string _t;
		void computeLPSArray(std::string pat, int M, int* lps);
	public:
		KMP(const std::string &s);
		~KMP();
		unsigned count(const std::string &pat);
};