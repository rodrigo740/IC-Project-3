#include "fcm.h"

int main(int argc, char **argv){

    if(argc != 2){
        cerr << "Usage: ./teste_fcm.o <input_text>\nExample: ./testFilter.o texts/test.txt" << endl;
        return -1;
    }

    cout << "Processing file: " << argv[1]  << endl;


    fcm fcm4 = fcm(8,0.3,argv[1]);
    return 0;
}