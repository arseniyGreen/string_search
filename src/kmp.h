#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>

#define FILEPATH "/home/notahacker/Documents/string_search/dataset.txt"

#ifndef STRING_SEARCH_KMP_H
#define STRING_SEARCH_KMP_H

class KMP{
private:
    std::string S; // pattern
    std::string T; // text

    std::vector<int> prefix()
    {
        int n = (int) S.length();
        std::vector<int> pi(n);
        for(size_t i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while(j > 0 && S[i] != S[j]) j = pi[j - 1];
            if(S[i] == S[j]) ++j;
            pi[i] = j;
        }
        return pi;
    }

    int kmp()
    {
        int sl = T.length(); int ssl = S.length(); // sl - string len, ssl - substring len
        int res = -1;
        if(sl == 0) throw std::runtime_error("Invalid string\n");
        else if(ssl == 0) throw std::runtime_error("Invalid substring\n");
        else
        {
            int i, j = 0, k = -1;
            int* d = new int[1000];
            d[0] = -1;
            while(j < ssl - 1){
                while(k >= 0 && S[j] != S[k])
                    k = d[k];
                j++;
                k++;
                if(S[j] == S[k])
                    d[j] = d[k];
                else
                    d[j] = k;
            }
            i = j = 0;
            while(j < ssl && i < sl){
                while(j >= 0 && T[i] != S[j])
                    j = d[j];
                i++;
                j++;
            }
            delete[] d;
            (j == ssl) ? res = i - ssl : res = -1;
        }
        return res;
    }

    void setFromFile()
    {
        std::ifstream file;
        file.open(FILEPATH, std::ios::in);
        if(file.is_open()){
            std::string line;
            while(std::getline(file, line)){
                T += line + "\n";
            }
            file.close();
        }
        else{
            std::cerr << "Unable to open file.\n";
        }
    }

public:
    KMP(){ S = T = ""; }
    KMP(std::string S_, std::string T_){ S = S_; T = T_; }
    ~KMP(){}

    void search(std::string pattern_)
    {
        S = pattern_;
        setFromFile();
        std::cout << "\nSearching : " << S << "...\n";
        std::cout << kmp();
    }
};

#endif //STRING_SEARCH_KMP_H
