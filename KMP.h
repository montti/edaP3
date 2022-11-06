#include <bits/stdc++.h>

using namespace std;

class KMP {
	private:
		vector<int> tabla;
		string w;
	public:
		KMP();
		~KMP();
		void generarTabla(const string &w);
		vector<int> busqueda(const string &s);
		int matches(const string &s);
		unsigned int memoria();
};