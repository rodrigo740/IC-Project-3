#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>

using namespace std;

class fcm { //This program should provide the entropy of the text, as estimated by the model.
    int k; //number of characters read at one time
    int a; //smoothing parameter
    string f; //file of the raw text
    map<pair<vector<char>,char>,int> table; //sequence of k size chars, next char, number of times that next char appears
    map<vector<char>,int> seq;
    public: 
        fcm(int ka, int alpha, string file){
            k=ka;
            a=alpha;
            f=file;
            main();
        }

    int main(){
        locale::global(locale(""));
        wifstream ifs(f); //accept the raw text
        if (!ifs.is_open()){
            cerr << "Could not open input file: '" << f << "'" << endl;
            return 1;
        }

        // | 0 1 2 3 | 4 5 6 7 8 9 
        char c;
        wchar_t ch;
        vector<char> chars;
        int condition=0;
        while(ifs.get(ch)){
            if(condition<k){
                chars.push_back(ch);
                condition++;
            }
            if(condition==k){
                c = ifs.peek();
                table[make_pair(chars,c)]++; //increase the current counting
                seq[chars]++;
                chars.erase(chars.begin()); //delete first entry
                condition=k-1;
            }
        }
        
        double h = 0;
        double count_all_seq = 0;

        //-----

        for (auto it = table.begin();it != table.end(); it++){
            string str(it->first.first.begin(), it->first.first.end());
            count_all_seq = seq[it->first.first];
            double p = static_cast<double>(it->second) / count_all_seq;
            h = h-p*log2(p);
        }
        
        //prints 
        cout << "Entropy: " << h << endl;
        /*cout << "table " << endl;
        for (auto it = table.begin();it != table.end(); it++){
            string str(it->first.first.begin(), it->first.first.end());
            cout <<" "<< str << " " << it->first.second << " " << it->second << endl;
        }*/
        /*cout << "seq" << endl;
        for (auto it = seq.begin();it != seq.end(); it++){
            string str(it->first.begin(), it->first.end());
            cout <<" "<< str << " " << it->second << endl;
        }*/

        return 1;


    }

};