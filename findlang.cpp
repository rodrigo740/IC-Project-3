#include "lang.h"
#include <set>
#include <vector>
#include <experimental/filesystem>
#include <chrono>

using namespace std;
using namespace chrono;
using namespace experimental::filesystem;


int main(int argc, char *argv[]){

    if(argc != 4){
        cerr << "Usage: ./findlang.cpp <input_text> <k> <alfa>\nExample: ./findlang texts/test.txt 3 0.1" << endl;
        return -1;
    }

    cout << "Starting" << endl;
    auto start = high_resolution_clock::now();

    int k = stoi(argv[2]);
    double alfa = stod(argv[3]);

    const path path{"lang/"};
    float diff = 0;
    float min = 9999;
    string language, model;

    for(auto dir_entry: directory_iterator{path}){
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Processing Time: " << duration.count() << " s" << endl;
    
   return 0;
}
