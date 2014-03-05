#include "AlienConverter.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        cout << "Valid format is " << argv[0] << ", arg1, arg2, arg3, ..." << endl;                                                                             exit(-1);
    }
    
    vector<string> input(argv, argv+argc);

    AlienConverter *obj = new AlienConverter();
    int output = obj->alienConverter(input);

    if(output != -1)
    {
        cout << "Your value is " << output << " Credits." << endl;
    }
    else
    {
        cout << "You've failed me with your stupid syntax" << endl;
    }

    delete obj;
}
