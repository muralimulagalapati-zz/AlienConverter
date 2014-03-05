#include "RomanConverter.h"
    
RomanConverter::RomanConverter()
{   
    initAllTables();
}   

RomanConverter::~RomanConverter()
{
}   
    
void RomanConverter::initAllTables()
{   
    // Initializing mCoversion Map.
    mConversion['M'] = 1000;
    mConversion['D'] = 500;
    mConversion['C'] = 100;
    mConversion['L'] = 50;
    mConversion['X'] = 10;
    mConversion['V'] = 5;
    mConversion['I'] = 1;
    
    // Initializing mPriority Map.
    mPriority['I'] = 0;
    mPriority['V'] = 1;
    mPriority['X'] = 2;
    mPriority['L'] = 3;
    mPriority['C'] = 4;
    mPriority['D'] = 5;
    mPriority['M'] = 6;
    
    // Initializing mRomanTable Vector.
    mRomanTable.push_back(make_pair("M", 1000));
    mRomanTable.push_back(make_pair("CM", 900));
    mRomanTable.push_back(make_pair("D", 500));
    mRomanTable.push_back(make_pair("CD", 400));
    mRomanTable.push_back(make_pair("C", 100));
    mRomanTable.push_back(make_pair("XC", 90));
    mRomanTable.push_back(make_pair("L", 50));
    mRomanTable.push_back(make_pair("XL", 40));
    mRomanTable.push_back(make_pair("X", 10));
    mRomanTable.push_back(make_pair("IX", 9));
    mRomanTable.push_back(make_pair("V", 5));
    mRomanTable.push_back(make_pair("IV", 4));
    mRomanTable.push_back(make_pair("I", 1));
}

string RomanConverter::numberToRoman(int number)
{   
    string roman = "";
    vector< pair<string, int> >::iterator it;
    number = (number < 0) ? (-1*number) : number;

    for(it = mRomanTable.begin(); it != mRomanTable.end(); it++)
    {
        while(number - it->second >= 0) 
        {
            number = number - it->second;
            roman += it->first;
        }
    }   
    return roman;
}           
        
int RomanConverter::romanToNumber(string roman)
{   
    int number = 0;
    int i= 0;
    
    // Validating Roman number
    for(int i=0; i<roman.length(); i++)
    {
        if(mConversion.find(roman[i]) == mConversion.end())
        {
            cout << "Pl enter a valid Roman number" << endl;
            return -1;
        }
    }   
            
    while(roman[i] != '\0')
    {   
        if( mPriority[roman[i]] < mPriority[roman[i+1]] )
        {
            int tmp = mConversion[roman[i+1]] - mConversion[roman[i]];
            number += tmp;
            i += 2;
        }   
        else
        {   
            number += mConversion[roman[i]];
            i++;
        }
    }   
    return number; 
}  
