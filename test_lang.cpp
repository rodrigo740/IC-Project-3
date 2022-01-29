#include "include/Lang.h"

int main(int argc, char *argv[]) { 

    if(argc != 5) {
        cout << "Usage: ./test_lang.o <modelLanguage> <text> <k> <alpha>" << endl;
        return -1;
    }

    lang l = lang(argv[1], argv[2], stoi(argv[3]), stod(argv[4]));
    cout << "Amount of information: "<< l.doLang()<< endl;
    return 0;
}