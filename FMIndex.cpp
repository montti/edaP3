#include <bits/stdc++.h>
#include "FMIndex.h"

FMIndex::FMIndex(const std::string &s, int offset) : _t(s), _offset(offset)
{
    size_t _t_size = _t.size() + 1;
    std::vector<int> _arr(_t_size);
    _t.push_back('$');
    _sv = std::string_view(_t);
    iota(_arr.begin(), _arr.end(), 0);
    // ordenar los indices dependiendo de los sufijos de esa posición
    sort(_arr.begin(), _arr.end(),
         // alternativa 1
         [this](unsigned l, unsigned r) -> bool
         {
             return this->_sv.substr(l) < this->_sv.substr(r);
         });
    // Crear vector F y L
    char actual_char = '$';
    int actual_cont = 0;
    for (size_t i = 0; i < _t_size; i++)
    {
        if (_t[_arr[i]] == actual_char)
            actual_cont++;
        else
        {
            F.push_back(std::make_pair(actual_char, actual_cont));
            actual_char = _t[_arr[i]];
            actual_cont = 1;
        }
        if (_arr[i] == 0)
            L.push_back('$');
        else
            L.push_back(_t[_arr[i] - 1]);
    }
    F.push_back(std::make_pair(actual_char, actual_cont));
    // INGRESAR EL ULTIMO CARACTER

    // Crear map C
    std::map<char, int> aux;
    int _sum = 0;
    for (size_t i = 0; i < F.size(); i++)
    {
        aux[F.at(i).first] = 0;
        OCC[F.at(i).first] = std::vector<int>();
        C[F.at(i).first] = _sum;
        _sum += F.at(i).second;
    }
    // Crear map OCC
    for (size_t i = 0; i < L.size(); i++)
    {
        aux[L[i]] = aux[L[i]] + 1;
        if (i % _offset == 0)
        {
            for (std::pair<char, int> item2 : aux)
            {
                OCC[item2.first].push_back(item2.second);
            }
        }
    }

    for (std::pair<char, std::vector<int>> item1 : OCC)
    {
        std::cout << item1.first << ":";
        for (int item2 : item1.second)
        {
            std::cout << item2 << " ";
        }
        std::cout << std::endl;
    }
}
FMIndex::~FMIndex() {}
unsigned FMIndex::count(const std::string &pat)
{

    int i = pat.size() - 1;
    char c = pat[i];
    if (C.find(c) == C.end())
        return 0;
    int sp = C[c] + 1;
    auto it = C.find(c);
    it++;
    int ep;
    if (it != C.end())
        ep = it->second;
    else
        ep = _t.size() - 1;
    while (sp <= ep && i >= 2)
    {
        c = pat[i - 1];
        std::cout << c << " ";
        if (C.find(c) == C.end())
            return 0;
        sp = C[c] + OCC[c][sp - 1] + 1;
        ep = C[c] + OCC[c][ep];
        i--;
    }
    if (ep < sp)
        return 0;
    else
        return ep - sp + 1;
}