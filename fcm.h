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
            coiso();
        }

    void coiso(){
        locale::global(locale(""));
        wifstream ifs(f); //accept the raw text
        if (!ifs.is_open()){
            cerr << "Could not open input file: '" << f << "'" << endl;
            
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
        
        double h = 0;
        double count_all_seq = 0;

        //-----

        for (auto it = table.begin();it != table.end(); it++){
            string str(it->first.first.begin(), it->first.first.end());
            count_all_seq = seq[it->first.first];
            //wcout << "n vezes q a sequencia aparece(tas contente?): " << count_all_seq << endl;
            //wcout << "numero cenas: "  << it->second << endl;
            double p = static_cast<double>(it->second) / count_all_seq;

            h = h-p*log2(p);
        }
        
        //prints 
        wcout << "Entropy: " << h << endl;

        
        for(wchar_t asd: alfabeto){
            wcout << asd << " ";
        }

        wcout << "\n Alfabeto size: " << alfabeto.size() << endl;
        wcout << "Max entropy: " << log2(alfabeto.size()) << endl;
        wcout << "\n#############################################" << endl;





        
        wcout << "table " << endl;
        for (auto it = table.begin();it != table.end(); it++){
            wstring str(it->first.first.begin(), it->first.first.end());
            wcout << "Seq size: " << str.length() << endl;
            wcout << "\"\"" << endl;
            wcout <<" "<< str << " " << it->first.second << " \"\" " << it->second << endl;
            

        }/*
        wcout << "seq" << endl;
        for (auto it = seq.begin();it != seq.end(); it++){
            wstring str(it->first.begin(), it->first.end());
            wcout <<" "<< str << " " << it->second << endl;
        }*/

      


    }

};