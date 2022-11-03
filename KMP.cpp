#include <bits/stdc++.h>

using namespace std;

//codigo basado en la implementacion de geekforgeeks https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
class KMP{
private:
	string _t;
	void computeLPSArray(string pat, int M, int* lps){
		int len = 0;
		lps[0] = 0; // lps[0] is always 0
		int i = 1;
		while (i < M) {
			if (pat[i] == pat[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else {
				if (len != 0) {
					len = lps[len - 1];
				}
				else {
					lps[i] = 0;
					i++;
				}
			}
		}
	}
public:
	KMP(const string &s): _t(s){
	}
	unsigned countMatches(string pat){
		int count = 0;
		int M = pat.length();
		int N = _t.length();
		//array donde se almacena las posiciones en las que se repite un patron dentro de el mismo(o algo así)
		int lps[M];
		//calcula el lps array
		computeLPSArray(pat, M, lps);
		//indice para el texto
		int i = 0; // index for txt[]
		//indice para el patron
		int j = 0;
		while ((N - i) >= (M - j)) {
			if (pat[j] == _t[i]) {
				j++;
				i++;
			}
			//cuado se encuentran encuentra el patron en el texto se aumenta el contador y se disminuye j dependiento del lps array
			if (j == M) {
				count++;
				j = lps[j - 1];
			}
			//si no coinciden los caracteres se "avanza" dependiendo de lps array
			else if (i < N && pat[j] != _t[i]) {
				if (j != 0)
					j = lps[j - 1];
				else
					i = i + 1;
			}
		}
		return count;
	}
};