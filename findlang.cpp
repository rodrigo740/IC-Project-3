#include "include/Lang.h"
#include "include/Filter.h"
#include <experimental/filesystem>
#include <chrono>

using namespace std;
using namespace chrono;
using namespace experimental::filesystem;


int main(int argc, char *argv[]){
    /** \file findlang.cpp
    * Function to predict the language of a file.
    */
    if(argc != 5){
        cerr << "Usage: ./findlang.o <input_text> <k> <alfa> <mode>, mode= -f/-nf\nExample: ./findlang.o texts/test.txt 3 0.1 -f" << endl;
        return -1;
    }

    string mode = argv[4];

    if (mode != "-f" && mode != "-nf")
    {
        cout << "Invalid mode!\nValid modes = -f, -nf\nExiting...." << endl;
        return -1;
    }
    
    cout << "Starting" << endl;
    auto start = high_resolution_clock::now();

    int k = stoi(argv[2]);
    double alfa = stod(argv[3]);

    const path path{"lang_models/"};
    float diff = 0;
    float min = 9999;
    float average = 0;
    int modelsCount = 0;
    string language, model, sfm, filter_file = argv[1];

    if (mode == "-f")
    {
        filter_file = ((string) argv[1]).substr(0, ((string) argv[1]).find(".")) + ("_filtered.txt");

        cout << "Writing filtered input file to: " << filter_file << endl;
        Filter f = Filter(argv[1], filter_file);
        f.filterFile();
    }
    
    for(auto dir_entry: directory_iterator{path}){
        model = dir_entry.path().string();
        if (mode == "-f")
        {
            sfm = model.substr(model.find("/")+1, model.length()-model.find("/"));
            sfm = "texts/filtered/" + sfm.substr(0, sfm.find(".")) + "_filtered.txt";
            Filter fm = Filter(model, sfm);
            fm.filterFile();
        }else{
            sfm = model;
        }
        
        Lang l = Lang(sfm, filter_file, k, alfa);
        
        diff = l.doLang();

        cout << "Model File: " << sfm << "\nnum of bits/symbol: " << diff << endl;
        average += diff;
        modelsCount += 1;

        if (min > diff){
            min = diff;
            language = model;
        }
    }

    average -= min;
    modelsCount -= 1;
    average /= modelsCount;

    language = language.substr(language.find("/")+1, language.length() - language.find("/"));
    language = language.substr(0, language.find("."));

    cout << "\nText " << argv[1] <<" is likely written in " << language << "\nnum of bit: " << min << endl;
    cout << "\nAverage of bits/symbol needed to write file in the wrong models: " << average << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Processing Time: " << duration.count() << " s" << endl;
    
   return 0;
}
