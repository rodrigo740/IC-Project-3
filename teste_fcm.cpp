#include "include/Fcm.h"

int main(int argc, char **argv){
    /** \file teste_fcm.cpp 
     * Function to test the \ref Fcm class
     * 
     */
    if(argc != 5){  
        cerr << "Usage: ./teste_fcm.o <input_text> <k> <alfa>\nExample: ./teste_fcm.o lang_models/portuguese.txt texts/test.txt 3 0.1" << endl;
        return -1;
    }

    cout << "Processing file: " << argv[1]  << endl;


    Fcm fcm4 = Fcm(stoi(argv[3]),stod(argv[4]),argv[1]);

    cout << "\nEntropy: " << fcm4.doFCM() << endl;
    float x = fcm4.auxFcm(argv[2]);
    cout << "x= " << x << endl;
    return 0;
}