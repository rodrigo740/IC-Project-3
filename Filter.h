#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>
#include<set>

using namespace std;



class Filter {

    string input_fileName;
    string output_fileName;
    vector<wchar_t> chars;
    set<wchar_t> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    

    public: 
        Filter(string file_in, string file_out){
            input_fileName = file_in;
            output_fileName = file_out;
        }

    void filterFile(){

        locale::global(locale(""));                 // activate user-preferred locale
        wifstream wif = wifstream(input_fileName);
        wofstream wof = wofstream("hello.txt");
        wchar_t c;

        while(wif.get(c)){
            
            if((numbers.find(c) == numbers.end())){
                wof << (wchar_t) towlower(c);
            }
            /*
            if((c != L'\n') && (numbers.find(c) == numbers.end())){
            }*/
        }
        
        wif.close();
        wof.close();

        ifstream ifs = ifstream("hello.txt");
        ofstream ofs = ofstream(output_fileName);
        char ch;
        FILE* input_file = fopen("hello.txt", "r");
        unsigned char character = 0;
        while (!feof(input_file)){
            character = getc(input_file);

            if(character != '\n'){
                cout << character << "-";
                ofs << character;
            }else{
                ofs << ' ';
            }
        }
        fclose(input_file);
        ifs.close();
        ofs.close();
    }

};