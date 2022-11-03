#include <bits/stdc++.h>

using namespace std;

class FMIndex {
	private:
		vector<char> F;
		vector<char> L;
		vector<int> SA_Sample;
		vector<int> Checkpoits; //no es necesaria para realizar count
		string _t;
	public:
		FMIndex(const string &s);
		~FMIndex();
		unsigned count(string pat);
};