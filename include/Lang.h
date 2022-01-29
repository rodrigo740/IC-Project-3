#include"Fcm.h"

using namespace std;

class lang{

    string file_lang; //ficheiro que representa linguagem
    string file_text; //ficheiro para analisar
    int k;
    double alpha;

    public:
        lang(string model, string text, int order, double a){
            file_lang=model;
            file_text=text;
            k=order;
            alpha=a;
        }

    float doLang(){
        Fcm fcm_lang = Fcm(k,alpha,file_lang);
        float entr = fcm_lang.doFCM();
        float x = fcm_lang.auxFcm(file_text);

        return x;
    }
};