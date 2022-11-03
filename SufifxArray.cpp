#include <bits/stdc++.h>

using namespace std;

class SuffixArray{
private:
	string _t;
	string_view _sv;
	vector<unsigned> _arr;
public:
	SuffixArray(const string &s) : _t(s), _arr(s.size() + 1){
		//agregar el caracter $ como fin del string
		_t.push_back('$');
		//almacena referencias de todos los suffix
		_sv = string_view(_t);
		//Rellenar _arr con 0 , 1, 2 ...
		iota(_arr.begin(), _arr.end(), 0);
		//ordenar los indices dependiendo de los sufijos de esa posición 
		sort(_arr.begin(), _arr.end(),
			 // alternativa 1
			 [this](unsigned l, unsigned r) -> bool{
				 return this->_sv.substr(l) < this->_sv.substr(r);
			 }
		);
	}
	unsigned countMatches(const string &s){
		//se obtiene la posición en la cual se encuentra la primer coincidencia con el string
		auto lower = lower_bound(_arr.begin(), _arr.end(), s,
								 [this](unsigned l, const string &s) -> bool{
									 // true si es que el string s no esta antes
									 return _sv.substr(l) < s;
								 });
		//se obtiene la posición en la cual se encuentra un string "mayor"
		auto upper = upper_bound(_arr.begin(), _arr.end(), s,
								 [this](const string &s, unsigned l) -> bool{
									 // true si es que el string s no esta antes
									 return _sv.substr(l, s.size()) > s;
								 });
		//se calcula los distacia (elementos) que hay entre los punteros para saber cuantos strings coinciden con el patron
		return distance(lower, upper);
	}
};