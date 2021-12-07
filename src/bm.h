#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define ALPH 256

class BM_Search
{
private:
    std::string text;
    std::string pattern;

    void setFromFile() {
        std::ifstream file;
        file.open(FILEPATH, std::ios::in);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                text += line + "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file.\n";
        }
    }

    int search()
    {
        int substringLen = 0; int stringLen = 0; int result = -1;
        while(text[stringLen] != NULL) stringLen++;
        while(pattern[substringLen] != NULL) substringLen++;

        if(stringLen == 0){ std::cout << "\nIncorrect string."; }
        else if(substringLen == 0){ std::cout << "\nIncorrect substring";}
        else
        {
            int i, position;
            int BMT[256];
            for(i = 0; i < 256; i++) BMT[i] = substringLen;
            for(i = substringLen - 1; i >= 0; i--)
                if(BMT[pattern[i]] == substringLen)
                    BMT[pattern[i]] = substringLen - i - 1;
            position = substringLen - 1;
            while(position < stringLen)
                if(pattern[substringLen - 1] != text[position])
                    position += BMT[text[position]];
                else
                    for(i = substringLen - 2; i >= 0; i--)
                    {
                        if(pattern[i] != text[position - substringLen + i + 1])
                        {
                            position += BMT[text[position - substringLen + i + 1]] - 1;
                            break;
                        }
                        else
                        {
                            if(i == 0) return position - substringLen + 1;
                        }
                    }
        }
        return result;
    }

public:
    void setPattern(std::string pattern_) { pattern = pattern_; }
    void setText(std::string text_) { text = text_; }

    std::string getText(){ return text; }
    std::string getPattern() { return pattern; }

    void start(std::string pattern_)
    {
        int res;
        setFromFile();
        setPattern(pattern_);
        std::cout << "Searching : " << pattern_ << "...\n";
        res = search();
        std::cout << "\nDone " << res;
    }
};