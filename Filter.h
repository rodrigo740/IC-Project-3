#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>

using namespace std;



class Filter {

    string input_fileName;
    string output_fileName;
    vector<wchar_t> chars;

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
            wof << (wchar_t) towlower(c);
        }
        

    }

};