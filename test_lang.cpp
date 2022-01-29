#include "include/Lang.h"

int main(int argc, char *argv[]) { 

    if(argc != 5) {
        cout << "Usage: ./lang.o <modelLanguage> <text> <k> <alpha>" << endl;
        return -1;
    }

    cout << "Processing model language: " << argv[1] << "\nProcessing sample text: " << argv[2] << endl;


    string file_lang = argv[1]; //ficheiro que representa linguagem
    string file_text = argv[2]; //ficheiro para analisar
    int k = stoi(argv[3]);
    double alpha = stod(argv[4]);
    Fcm fcm_lang = Fcm(k,alpha,file_lang);
    Fcm fcm_text = Fcm(k,alpha,file_text);
    float h_lang = fcm_lang.doFCM();
    float h_text = fcm_text.doFCM();

    cout << "entropy lang: " << h_lang << endl;
    cout << "entropy text: " << h_text << endl;
    return 0;
}