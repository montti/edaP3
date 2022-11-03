#include <bits/stdc++.h>

using namespace std;

class KMP {
	private:
		string _t;
		void computeLPSArray(string pat, int M, int* lps);
	public:
		KMP(const string &s);
		~KMP();
		unsigned count(string pat);
};