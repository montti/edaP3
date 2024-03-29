#include <bits/stdc++.h>
#include "FMIndex.h"

using namespace std;

string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
		cout << "ERROR" << endl;
		return (string)"";
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

int main(int argc, char const *argv[]){
    if(argc != 2) return 1;
    string texto = readFileIntoString(argv[1]);
    FMIndex A = FMIndex(texto,1);
    string _s;
    cin >> _s;
    while (_s != "0"){
        cout << A.count(_s) << endl;
        cin >> _s;
    }
    
    cout << A.count("is") << endl;
    return 0;
}
