// Código Ayudante
#include <bits/stdc++.h>
#include "KMP.h"
#include "FMIndex.h"
using namespace std;

// Imprime cada vez que se asigna memoria.
// (Se inicializa un vector o se expande.)
//void* operator new(size_t count){
//	cerr << "creo espacio " << count <<endl;
//	return malloc(count);
//}

class SuffixArray{
	private:	
	string _t;
	// La string view es una read-only string.
	string_view _sv;
	vector<unsigned> _arr;

	// No se utiliza este comparador, es la alternativa 2. 
	bool compareSuffix(unsigned l, unsigned r){
		// true si es que l va antes que r
		return _sv.substr(l) < _sv.substr(r);
	}

	public:
	SuffixArray(const string &s) : _t(s) , _arr(s.size()+1) {
		
		_t.push_back('$');
		// Inicializamos la read-only string.
		_sv  = string_view(_t);
		
		// Rellenamos el SA con 0, 1, 2 ... (n - 1).
		iota(_arr.begin(),_arr.end(),0);

		// Ordenamos la secuencia en SA según la prioridad de los suffix que cada numero representa. 
		//  Ej. a$ < ana$
		// Esto se logra con el comparador de la alternativa 1.
		sort(_arr.begin(), _arr.end(), 
//alternativa 1
			[this](unsigned l, unsigned r) -> bool{
				return this->_sv.substr(l)<this->_sv.substr(r);
			} 
//alternativa 2
/*
			bind(&SuffixArray::compareSuffix,
				this,placeholders::_1, placeholders::_2)	*/
				); 

		// Una vez ordenado se obtiene el SA. En peor caso esto seria O(n^2 log n). 
	}

	unsigned countMatches(const string &s){

		// lower es un iterador que apunta al primer elemento en el SA que aparece el string s.

		auto lower = lower_bound(_arr.begin(),_arr.end(),s,
			[this](unsigned l, const string &s) -> bool{
				// true si es que el string s no esta antes
				return _sv.substr(l) < s;
			} );

		// upper es un iterador que apunta al ultimo elemento en el SA que aparece el string s.

		auto upper = upper_bound(_arr.begin(), _arr.end(), s,

			[this](const string &s,unsigned l ) -> bool{
				// true si es que el string s no esta antes
				return _sv.substr(l,s.size()) > s;
				} );


		//cout << "AAAA "<<  *lower <<endl;

		//cout << "BBBB "<<  *upper<<endl;

		// La distancia entre estos los iteradores corresponde al numero de ocurrencias de un patrón. 

		return distance(lower,upper);
	}

	// Imprime el SA.

	void printArray(){
		for(unsigned i : _arr){
			cout << i << " " <<_sv.substr(i) <<endl;
		}
	}

};

void saludaYAlgo(const string &s, int n){
	cout << s << " y el int es " << n<<endl;
}

double promedio(const vector<double> &v) {
	double aux = 0;

	for (double i : v) {
		aux += i;
	}

	return (aux / (double) v.size()); 
}

int main(int argc, char const *argv[]){
	string filename(argv[1]);
	int w_size = stoi(argv[2]);
	string logfile(argv[3]);
	int size = stoi(argv[4]);

	int cSA;
	int cKMP;
	int cFM;

	ifstream t(filename);
	stringstream buffer;
	buffer << t.rdbuf();

	random_device rnd_device;
	mt19937 mersenne_engine {rnd_device()};
	uniform_int_distribution<long unsigned int> dist {0, (buffer.str()).size() - w_size - 1};
	auto gen = [&dist, &mersenne_engine](){return dist(mersenne_engine);};

	vector<int> vec(1);

	string w;

	//cout << vec[0] << endl;
	//cout << w << endl;

	auto start = chrono::high_resolution_clock::now();
	vector<double> tBusSA, tBusKMP, tBusFM, tConsSA, tConsKMP, tConsFM; 
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;

	for (int i = 0; i < 1; ++i) {

	generate(vec.begin(), vec.end(), gen);
	w = (buffer.str()).substr(vec[0], w_size);

	start = chrono::high_resolution_clock::now();
	SuffixArray SA(buffer.str());
	end = chrono::high_resolution_clock::now();
	diff = end - start;
	tConsSA.push_back(diff.count());


	start = chrono::high_resolution_clock::now();
	cSA = SA.countMatches(w);
	end = chrono::high_resolution_clock::now();
	diff = end - start;
	tBusSA.push_back(diff.count());

	//cout << cSA << " coincidencias"<<endl;

	start = chrono::high_resolution_clock::now();
	KMP test;
	test.generarTabla(w);
	end = chrono::high_resolution_clock::now();
	diff = end - start;
	tConsKMP.push_back(diff.count());

	start = chrono::high_resolution_clock::now();
	cKMP = test.matches(buffer.str());
	end = chrono::high_resolution_clock::now();
	diff = end - start;
	tBusKMP.push_back(diff.count());

	start = chrono::high_resolution_clock::now();
	FMIndex fm(buffer.str(), 1);
	end = chrono::high_resolution_clock::now();
	diff = end - start;
	tConsFM.push_back(diff.count());

	start = chrono::high_resolution_clock::now();
	cFM =  fm.count(w);
	end = chrono::high_resolution_clock::now();
	diff = end - start;
	tBusFM.push_back(diff.count());
	}

	cout << cKMP << "  KMP coincidencias" << endl;
	cout << cSA << "  SA coincidencias" << endl;
	cout << cFM << "  FM  coincidencias" << endl;
	
	//cout << "Memoria Utilizada: " << test.memoria() << endl;
	//cout << tBusSA << " " << tBusKMP << endl;
	//cout << tConsSA << " " << tConsKMP << endl;

	ofstream log(logfile, ios_base::app | ios_base::out);

	cout << "Imprimiendo... " << size << endl;

	log << size << "," << promedio(tBusSA) << "," << promedio(tBusKMP) << "," << promedio(tBusFM) << "," << promedio(tConsSA) << "," << promedio(tConsKMP) << promedio(tConsFM) << endl;

	log.close();
}
