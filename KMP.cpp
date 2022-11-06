// Basado en la explicacion y pseudocodigo de https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
#include <bits/stdc++.h>
#include "KMP.h"

using namespace std;

unsigned int mem = 0;

KMP::KMP() {}
KMP::~KMP() {}

// Imprime cada vez que se asigna memoria.
// (Se inicializa un vector o se expande.)
void* operator new(size_t count){
	mem += count;
	return malloc(count);
}

// Para cada substring del patrón se revisa cual es prefijo que a su vez es sufijo mas largo.
// (Se ignora la substring misma como prefijo/sufijo)
//
// Si no hay prefijo/sufijo se guarda 0 en la tabla.
// Si el prefijo/sufijo mas grande es de longitud 1 (es el primer carácter) se guarda -1 en la tabla. 
// Si se encuentra el prefijo/sufijo mas grande, con longitud >= 2, se guarda la posición post prefijo
// (La longitud del prefijo/sufijo)

void KMP::generarTabla(const string &w) {
	tabla.clear();
	mem = 0;
	vector<int> aux(w.size() + 1);
    tabla = aux;
	tabla[0] = -1;
	int candidata = 0;

	for (int i = 1; i < w.size(); ++i) {
		if (w[i] == w[candidata]) {
			tabla[i] = tabla[candidata];
		} else {
			tabla[i] = candidata;
			while (candidata >= 0 && w[i] != w[candidata]) {
				candidata = tabla[candidata];
			}
		}
		candidata++;
	}

	tabla[w.size()] = candidata;
	this->w = w;
}

vector<int> KMP::busqueda(const string &s) {
	int sIndex = 0; 
	int wIndex = 0;
	vector<int> match;

	while (sIndex < s.size()) {
		// Si los caracteres son iguales, avanzamos en el texto y el patrón.
		if (this->w[wIndex] == s[sIndex]) {
			sIndex++;
			wIndex++;

			// Si hemos avanzado por el patron completo significa que tenemos un match. 
			if (wIndex == this->w.size()) {
				// sIndex - wIndex es el inicio del match en el texto.
				match.push_back(sIndex - wIndex);

				// En el caso que un sufijo del patrón sea también su prefijo Ej. ABACABABA
				// Se deja wIndex en la posición post prefijo (En el caso del ejemplo esto seria C)
				// Si no hay sufijo = prefijo, simplemente wIndex sera 0. 
				// (En este caso el patrón en si no cuenta como prefijo o sufijo de si mismo)
				wIndex = tabla[wIndex];
			}
		} else {
			// En el caso que el sufijo del substring del patrón sea también su prefijo
			// Se deja wIndex en la posición post prefijo.
			// Si no hay sufijo = prefijo, simplemente wIndex sera 0. 
			wIndex = tabla[wIndex];

			// En el caso especial de -1 (El carácter es igual al primer carácter del patrón)
			// sabemos que el carácter del texto no va a ser igual al primero del patrón 
			// así que se avanza el indice del texto una vez y wIndex queda en 0. 
			if (wIndex < 0) {
				sIndex++;
				wIndex++;
			}
		}
	}

	// Retornamos todas las match en texto.
	return match;
}

int KMP::matches(const string &s) {
	// Contamos la cantidad de matches. 
	return busqueda(s).size();
}

// Retornamos la memoria usada hasta ahora. 
unsigned int KMP::memoria() {
	return mem;
}
