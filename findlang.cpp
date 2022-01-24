#include "fcm.h"
#include "lang.h"
#include <set>


int main(int argc, char *argv[]){
    if(argc>2 || argc==0){
        cerr << "Usage: ./findlang.cpp <input_text>\nExample: ./findlang texts/test.txt" << endl;
        return -1;
    }
    cout << "Processing file: " << argv[1] << endl;
    string input_fn = argv[1];
    set<string> modelos = {"modelo1","modelo2"};

    //Variables
    int tmp=0;                        //valor minimo
    string min;                     //modelo minimo
    set<string>::iterator itr;      //iterator

    for(itr = modelos.begin(); itr!=modelos.end(); itr++){
        int aux=lang(*itr,input_fn);
        if(tmp==0) {
            tmp=aux;
            min=*itr;
        }
        if(aux<tmp) {
            tmp=aux;
            min=*itr;
        }
    }
    cout << "Text "<<input_fn<<" is likely written in "<< min <<endl;
}
