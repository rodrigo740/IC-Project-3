#include<iostream>
#include<fstream>
#include<map>
#include<iterator>
#include<math.h>
#include<set>

using namespace std;

class Fcm {                                         //This program should provide the entropy of the text, as estimated by the model.
    int k;                                          //number of characters read at one time
    float alfa;                                     //smoothing parameter
    string f;                                       //file of the raw text
    map<wstring,int> table;                         
    map<wstring,int> seq;                           //sequence of k size chars, next char, number of times that next char appears
    map<wstring,float> local_ent_map;

    set<wchar_t> alfabeto;

    public: 
        Fcm(int ka, float alpha, string file){
            k=ka;
            alfa=alpha;
            f=file;
        }

    float prob(wstring wstr){                                             //probability of an event knowing a certain context
        float nc = table[wstr];                                           //n of c knowing wstr
        float n = seq[wstr.substr(0,k)]; 

        return (float)(nc+alfa)/(n+alfa*alfabeto.size());
    }

    float doFCM(){
        locale::global(locale(""));
        wifstream wifs(f);                                                 //accept the raw text
        if (!wifs.is_open()){
            cerr << "Could not open input file: '" << f << "'" << endl;
            return -1;
        }

        wchar_t ch;
        wstring chars, tmp;
        int condition=0;
        wcout << endl;
        while(wifs.get(ch)){
            alfabeto.insert(ch);
            chars += ch;
            if(condition<k){
                condition++;
            }else{
                table[chars]++;
                seq[chars.substr(0, k)]++;
                chars.erase(0,1); 
                
                condition=k;
            }
        }
        
        float global_entropy = 0;
        float sum_seq,local = 0;
        float count_all_seq = 0;
        float p;
        for (auto it = seq.begin();it != seq.end(); it++){
            count_all_seq += it->second;
        }


        for (auto it = table.begin();it != table.end(); it++){
            p = prob(it->first);
            local_ent_map[it->first.substr(0, k)] -= (float) (p*log2(p));
        }

        wstring ws;
        for (auto it = seq.begin();it != seq.end(); it++){
            ws = it->first; 
            sum_seq = it->second;
            local = local_ent_map[ws];
            global_entropy += local * (sum_seq/count_all_seq);
        }

        return global_entropy;
    }

    float auxFcm(string finput){ //calculate the number of bits according to existing table
        locale::global(locale(""));
        wifstream wifs2(finput);                                                 //accept the raw text
        if (!wifs2.is_open()){
            cerr << "Could not open input file: '" << finput << "'" << endl;
            return -1;
        }
        
        wchar_t ch;
        wstring chars, tmp;
        int condition=0;
        float p;
        float total=0;
        float count =0;
        float num_bits;
        wcout << endl;
        while(wifs2.get(ch)){
            alfabeto.insert(ch);
            chars += ch;
            if(condition<k){
                condition++;
            }else{
                if(table[chars] != NULL){
                    p = prob(chars);
                    num_bits = -log2(p);
                }
                else{
                    float n = seq[chars.substr(0,k)]; 
                    num_bits = -log2((alfa)/(n+alfa*alfabeto.size()));
                }
                total += num_bits;
                chars.erase(0,1); 
                condition=k;
                count++;
            }
        }
        return total/count;
    }

};