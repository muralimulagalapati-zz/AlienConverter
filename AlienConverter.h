#ifndef __ALIEN_CONVERTER_H__
#define __ALIEN_CONVERTER_H__
    
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class AlienConverter
{
    map<string, string> mAlienTable;
    map<string, double> mCurrencyTable;
    
    int calc(string roman, string currency);
        
public:
    AlienConverter();
    ~AlienConverter();
    int alienConverter(vector<string> input);
};

#endif //__ALIEN_CONVERTER_H__
