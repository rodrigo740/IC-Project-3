#include"Fcm.h"

using namespace std;

class Lang{
    /**
    *\class Lang
    * This class calculates the minimum amount of bits necessary to compress a file, file_text, using the \ref Fcm table of a model text, file_lang 
    */

    string file_lang; //ficheiro que representa linguagem
    string file_text; //ficheiro para analisar
    int k;
    double alpha;

    public:
        /**
         * \memberof(Lang)
         * Constructor that receives the name of the model file, the text file, the order and the smoothing parameter to be used on the \ref Fcm .
        */
        Lang(string model, string text, int order, double a){
            file_lang=model;
            file_text=text;
            k=order;
            alpha=a;
        }

    float doLang(){
        /**
         * \memberof(Fcm)
         * Function that calls the \ref Fcm class and will return the minimum number of bits necessary to compress.
        */
        Fcm fcm_lang = Fcm(k,alpha,file_lang);
        float num_bits = fcm_lang.doFCM();
        num_bits = fcm_lang.auxFcm(file_text);

        return num_bits;
    }
};