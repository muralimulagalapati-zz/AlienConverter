#ifndef __ROMAN_CONVERTER_H__
#define __ROMAN_CONVERTER_H__
    
#include <iostream>
#include <map>
#include <vector>
    
using namespace std;
    
class RomanConverter
{   
    vector< pair<string, int> > mRomanTable;
    map<char, int> mConversion;
    map<char, int> mPriority;

    void initAllTables();
    
public: 
    RomanConverter();
    ~RomanConverter();
    string numberToRoman(int number);
    int romanToNumber(string roman);
};  
    
#endif //__ROMAN_CONVERTER_H__
