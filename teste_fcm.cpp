#include "Fcm.h"

int main(int argc, char **argv){

    if(argc != 4){
        cerr << "Usage: ./teste_fcm.o <input_text> <k> <alfa>\nExample: ./testFilter.o texts/test.txt 3 0.1" << endl;
        return -1;
    }

    cout << "Processing file: " << argv[1]  << endl;


    Fcm fcm4 = Fcm(stoi(argv[2]),stod(argv[3]),argv[1]);
    cout << "\nEntropy: " << fcm4.doFCM() << endl;
    return 0;
}