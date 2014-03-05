#include "AlienConverter.h"
#include "RomanConverter.h"

AlienConverter::AlienConverter()
{
    // Initializing mAlienTable map
    mAlienTable["glob"] = "I";
    mAlienTable["prok"] = "V";
    mAlienTable["pish"] = "X";
    mAlienTable["tegj"] = "L";

    //Initializing mCurrencyTable map
    mCurrencyTable["Silver"] = 17;
    mCurrencyTable["Gold"] = 14450;
    mCurrencyTable["Iron"] = 195.5;
}

AlienConverter::~AlienConverter()
{
}

int AlienConverter::calc(string roman, string currency)
{
    RomanConverter *obj = new RomanConverter();
    if(currency == "Gold" || currency == "Silver" || currency == "Iron")
    {
        return obj->romanToNumber(roman) * mCurrencyTable[currency];
    }
    return obj->romanToNumber(roman);
}

int AlienConverter::alienConverter(vector<string> input)
{
    for(int i=1; i<input.size(); i++)
    {
        if( mAlienTable.find(input[i]) == mAlienTable.end() && mCurrencyTable.find(input[i]) == mCurrencyTable.end() )
        {
            cout << "Invalid syntax. Please use proper syntax" << endl;
            return -1;
        }
    }

    if( mCurrencyTable.find(input[input.size()-2]) != mCurrencyTable.end() )
    {
        cout << "Invalid syntax. Please use proper syntax" << endl;
        return -1;
    }

    string roman = "";
    string currency = "";

    try
    {
        int i;
        for(i=1; i<input.size(); i++)
        {
            roman += mAlienTable[input[i]];
        }

        currency = input[i-1];
    }
    catch(std::exception &e)
    {
        cerr << "Caught an exception throwed by map" << endl;
    }

    return calc(roman, currency);
}
