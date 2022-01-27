#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>
#include"fcm.h"
using namespace std;

int main(int argc, char *argv[]) { 

    if(argc < 5) {
        std::cout << "Usage: ./lang.o <modelLanguage> <text> <k> <alpha>" << std::endl;
        return -1;
    }

    string file_lang = argv[1]; //ficheiro que representa linguagem
    string file_text = argv[2]; //ficheiro para analisar
    int k = stoi(argv[2]);
    double alpha = stod(argv[3]);
  
    fcm fcm_lang = fcm(k,alpha,file_lang);
    fcm fcm_text = fcm(k,alpha,file_text);
    float h_lang = fcm_lang.doFCM();
    float h_text = fcm_text.doFCM();



    return 0;
}