#include <bits/stdc++.h>
#include "FMIndex.h"

FMIndex::FMIndex(const std::string &s): _t(s){
    _t.push_back('$');
}
FMIndex::~FMIndex() {}
unsigned FMIndex::count(const std::string &pat){
}