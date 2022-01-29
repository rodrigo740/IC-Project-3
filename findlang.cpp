#include "lang.h"
#include <set>
#include <vector>
#include <experimental/filesystem>

using namespace std;

int main(int argc, char *argv[]){

    if(argc != 4){
        cerr << "Usage: ./findlang.cpp <input_text> <k> <alfa>\nExample: ./findlang texts/test.txt 3 0.1" << endl;
        return -1;
    }

    cout << "Starting" << endl;
    int k = stoi(argv[2]);
    double alfa = stod(argv[3]);

    namespace stdfs = experimental::filesystem;

    const stdfs::path path{"lang/"};
    float diff = 0;
    float min = 9999;
    string language, model;

    for(auto dir_entry: stdfs::directory_iterator{path}){
        model = dir_entry.path().string();

        lang l = lang(model, argv[1], k, alfa);
        
        diff = l.doLang();

        cout << "Model File: " << model << " num of bits: " << diff << endl;

        if (min > diff){
            min = diff;
            language = model;
        }
    }

    cout << "Text " << argv[1] <<" is likely written in " << language <<endl;
    
   return 0;
}
