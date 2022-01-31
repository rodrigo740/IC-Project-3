#include<iostream>
#include<fstream>
#include<map>
#include<set>

using namespace std;

class Filter {
    /**
    *\class Filter
    * This class filters the input file text, removing all numbers and transforming all letters to lowercase.
    */
    string input_fileName;
    string output_fileName;
    set<wchar_t> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    
    public: 
        Filter(string file_in, string file_out){
            input_fileName = file_in;
            output_fileName = file_out;
        }

    void filterFile(){

        locale::global(locale(""));                 // activate user-preferred locale
        wifstream wif = wifstream(input_fileName);
        wofstream wof = wofstream(output_fileName);
        wchar_t c;

        while(wif.get(c)){
            if((numbers.find(c) == numbers.end())){
                wof << (wchar_t) towlower(c);
            }
        }
        wif.close();
        wof.close();
    }

};