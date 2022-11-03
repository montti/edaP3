#include <bits/stdc++.h>

using namespace std;

class FMIndex {
	private:
		string _t;
	public:
		FMIndex(const string &s);
		~FMIndex();
		unsigned count(string pat);
};