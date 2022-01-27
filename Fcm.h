#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>
#include<set>

using namespace std;

class Fcm {                                         //This program should provide the entropy of the text, as estimated by the model.
    int k;                                          //number of characters read at one time
    float alfa;                                     //smoothing parameter
    string f;                                       //file of the raw text
    map<wstring,int> table;                         //sequence of k size chars, next char, number of times that next char appears
    /*
    aaa b 1
    aaa c 2
    */
    map<wstring,int> seq;
    /*
    aaa 3
    */
    set<wchar_t> alfabeto;

    public: 
        Fcm(int ka, float alpha, string file){
            k=ka;
            alfa=alpha;
            f=file;
        }

    float prob(wstring wstr){                                             //probability of an event knowing a certain context
        float nc = (float) table[wstr];                                   //n of c knowing wstr
        float n = (float) seq[wstr.erase(k-1,1)];

        return (float)(nc+alfa)/(n+alfa*alfabeto.size());
    }


    float doFCM(){
        locale::global(locale(""));
        wifstream wifs(f);                               //accept the raw text
        if (!wifs.is_open()){
            cerr << "Could not open input file: '" << f << "'" << endl;
            return -1;
        }

        // | 0 1 2 3 | 4 5 6 7 8 9 
        wchar_t c, ch;
        wstring chars, tmp;
        int condition=0;

        while(wifs.get(ch)){
            
            alfabeto.insert(ch);
            /*abcdefghijk k=3 abc d - bcd e ...*/ 
            if(condition<k){
                chars += ch;
                condition++;
            }else{
                c = wifs.peek();
                tmp = chars + c;
                table[tmp]++;                           //increase the current counting
                seq[chars]++;
                chars.erase(0,1);                       //delete first char
                condition=k-1;
            }
        }
        
        float local_entropy = 0;
        float global_entropy = 0;
        float sum_one_seq = 0;
        float sum_seq = 0;
        float count_all_seq = 0;

        //total number of sequences
        for (auto it = seq.begin();it != seq.end(); it++){
            count_all_seq += (float) seq[it->first];
        }
        //-----
        wcout << "caq: " << count_all_seq << endl;
        for (auto it = table.begin();it != table.end(); it++){

            sum_seq = seq[it->first];
            //float p = static_cast<float>(it->second)/sum_one_seq;
            float p = prob(it->first);
            global_entropy -= (float) (p*log2(p)*((float)sum_seq/(float)count_all_seq));
            //wcout << p << endl;

        }
        //mal codificado, rever isto
        //global_entropy += local_entropy * ((double)count_all_seq/(double)sum_seq);
        

        for(wchar_t asd: alfabeto){
            wcout << asd << " ";
        }

        wcout << "\n Alfabeto size: " << alfabeto.size() << endl;
        wcout << "Max entropy: " << log2(alfabeto.size()) << endl;
        wcout << "\n#############################################" << endl;

        return global_entropy;
    }

};