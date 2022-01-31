#include <fstream>
#include <iostream>
#include <locale>
#include "include/Filter.h"


using namespace std;
    /** \file testFilter.cpp
     * Function to test the \ref Filter class
     * 
     */
/* This program  will filter any text
*/

int main(int argc, char **argv){

    if(argc != 3){
        cerr << "Usage: ./testFilter.o <input_text> <output_text>\nExample: ./testFilter.o texts/test.txt texts/filtered.txt" << endl;
        return -1;
    }

    cout << "Processing file: " << argv[1]  << "\nto output file: " << argv[2] << endl;

    Filter f(argv[1], argv[2]);

    f.filterFile();
    
    
    return 0;
}