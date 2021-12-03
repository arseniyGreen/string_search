#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define ALPH 256

class BM_Search
{
private:
    int N, shift;
    std::string text;
    std::string pattern;
public:
    int start()
    {
        int i = 0, j = N - 1, textLen = text.size(), shiftIndex;
        char lastChar = text[N - 1];
        while(j + i < textLen)
        {
            if(text[i + j] != pattern[j] || j == 0)
            {
                shiftIndex = -1;

                for(size_t k = 0; k < N; k++){
                    if(lastChar == pattern[k])
                    {
                        shiftIndex = k;
                        break;
                    }
                }
                if(shiftIndex == -1) i += N;
                else
                {
                    i += sample
                }
            }
        }
    }
};