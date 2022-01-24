#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>
#include"fcm.h"
using namespace std;

class lang { 
    int k,alpha;
    string file_lang; //ficheiro que representa linguagem
    string file_text; //ficheiro para analisar

    public: 
        lang(string lang, string text, int ka, int a){
            file_lang=lang;
            file_text=text;
            alpha=a;
            k=ka;
        }

    int main(){
        
        fcm fcm_lang = fcm(k,alpha,file_lang);
        fcm fcm_text = fcm(k,alpha,file_text);
        int h_lang = fcm_lang.main();
        int h_text = fcm_text.main();
        return h_text;
    }
};