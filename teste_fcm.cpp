#include "Fcm.h"

int main(int argc, char **argv){

    if(argc != 2){
        cerr << "Usage: ./teste_fcm.o <input_text>\nExample: ./testFilter.o texts/test.txt" << endl;
        return -1;
    }

    cout << "Processing file: " << argv[1]  << endl;


    Fcm fcm4 = Fcm(3,0.3,argv[1]);
    cout << "Entropy: " << fcm4.doFCM() << endl;
    return 0;
}