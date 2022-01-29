#include "include/Lang.h"

int main(int argc, char *argv[]) { 

    if(argc != 5) {
        cout << "Usage: ./test_lang.o <modelLanguage> <text> <k> <alpha> \nExample: ./test_lang.o lang_models/portuguese.txt texts/test.txt 3 0.1" << endl;
        return -1;
    }

    lang l = lang(argv[1], argv[2], stoi(argv[3]), stod(argv[4]));
    cout << "Amount of information: "<< l.doLang()<< endl;
    return 0;
}