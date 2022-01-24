#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>
#include<set>

using namespace std;

class fcm { //This program should provide the entropy of the text, as estimated by the model.
    int k; //number of characters read at one time
    int a; //smoothing parameter
    string f; //file of the raw text
    map<pair<vector<wchar_t>,wchar_t>,int> table; //sequence of k size chars, next char, number of times that next char appears
    map<vector<wchar_t>,int> seq;
    set<wchar_t> alfabeto;

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
        wchar_t c;
        wchar_t ch;
        vector<wchar_t> chars;
        int condition=0;
        while(ifs.get(ch)){
            
            alfabeto.insert(ch);

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
        
        double local_entropy = 0;
        double global_entropy = 0;
        double sum_one_seq = 0;
        double sum_seq = 0;
        double count_all_seq = 0;
        for (auto it = seq.begin();it != seq.end(); it++){
            count_all_seq += seq[it->first];
        }
        //-----

        for (auto it = table.begin();it != table.end(); it++){
            string str(it->first.first.begin(), it->first.first.end());
            sum_one_seq = seq[it->first.first];
            sum_seq += seq[it->first.first];
            double p = static_cast<double>(it->second)/sum_one_seq;
            local_entropy -= p*log2(p);
        }
        
        //prints 
        global_entropy += local_entropy * ((double)sum_seq/(double)count_all_seq);
        wcout << "Entropy: " << global_entropy << endl;

        
        for(wchar_t asd: alfabeto){
            wcout << asd << " ";
        }

        wcout << "\n Alfabeto size: " << alfabeto.size() << endl;
        wcout << "Max entropy: " << log2(alfabeto.size()) << endl;
        wcout << "\n#############################################" << endl;


        /*wcout << "table " << endl;
        for (auto it = table.begin();it != table.end(); it++){
            string str(it->first.first.begin(), it->first.first.end());
            wcout <<" "<< str.c_str() << " " << it->first.second << " " << it->second << endl;
        }
        wcout << "seq" << endl;
        for (auto it = seq.begin();it != seq.end(); it++){
            string str(it->first.begin(), it->first.end());
            wcout <<" "<< str.c_str() << " " << it->second << endl;
        }*/

        return 0;


    }

};