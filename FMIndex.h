#include <bits/stdc++.h>

class FMIndex
{
private:
	int _offset;
	std::string_view _sv;
	//arreglo de columna F
	std::vector<std::pair<char, int>> F;
	//arreglo de columna L
	std::vector<char> L;
	//arrreglo c
	std::map<char, int> C;
	//matriz occ
	std::map<char, std::vector<int>> OCC;
	std::string _t;
	unsigned Occ(char c, int i);
public:
	FMIndex(const std::string &s, int _offset);
	~FMIndex();
	unsigned count(const std::string &pat);
};