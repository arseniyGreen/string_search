/*
 * TODOs
 * Rabin-Karp Alg implementation
 * Partly match implementation (class-styled)
 * Matching % sort function
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>

#define FILEPATH "/home/notahacker/Documents/string_search/text.txt"
#define alph 256

class Search{
protected:
    std::string text; // text, where we'll search pattern
    std::string pattern; // pattern to find

    /* Polynomial hash formula : H = c1 * b^(m-1) + c2 * b^(m-2) + c3 * b^(m-3) + ... + Cm * b^0,
     * where c - chars in string, m - string length, b - const */

    /* New substring hash formula : H = (Hp - Cp * b^(m-1)) * b + Cn,
     * where Hp - previous hash, Cp - previous char, Cn - new char, m - substring length, b - const */

    virtual std::list<int> findHash()
    {
        int textHash, patternHash; textHash = patternHash = 0;
        size_t operations = 0; // Number of search loop iterations
        const int Q = 101; // Prime number
        int h = 1; // Multiplier
        std::list<int> positions;
        int stringSize = 0; // Compare size of the pattern to string
        int textLength = text.length();
        int patternLength = pattern.length();

        // Calculate h (== pow(alph, patternLength - 1))
        for(size_t i = 0; i < patternLength - 1; i++){
            h = (h * alph) % Q;
        }

        // Calculate starting hash
        for(size_t i = 0; i < patternLength; i++){
            textHash = ((alph * textHash) + text[i]) % Q;
            patternHash = ((alph * patternHash) + pattern[i]) % Q;
        }

        // Rolling hashing
        for(size_t i = 0; i < textLength - patternLength; i++)
        {
            operations++;
            // Compare hashes of text and pattern
            if(textHash == patternHash)
            {
                // Check chars match
                for(size_t j = 0; j < patternLength; j++)
                {
                    stringSize = j + 1;
                    if(text[i + j] != pattern[j]) break;
                }
                if(stringSize == patternLength) positions.push_back(i);
            }
            // Calculate next hash
            textHash = ((alph * (textHash - (h * text[i]))) + text[i + patternLength]) % Q;
            if(textHash < 0) textHash += Q;
        }
        return positions;
    }

public:
    Search(){ text = pattern = ""; setFromFile(); };
    Search(std::string text_, std::string image_) { text = text_; pattern = image_; setFromFile(); }
    ~Search(){};

    //Getters
    std::string getText(){ return text; }
    std::string getPattern(){ return pattern; }
    void printText(){ std::cout << "\n" << text << "\n"; }
    //Setters
    void setText(std::string text_){ text = text_; }
    void setPattern(std::string image_){ pattern = image_; }

    // Set text from file
    void setFromFile()
    {
        std::ifstream file;
        file.open(FILEPATH, std::ios::in);
        if(file.is_open()){
            std::string line;
            while(std::getline(file, line)){
                text += line + "\n";
            }
            file.close();
        }
        else{
            std::cerr << "Unable to open file.\n";
        }
    }
    virtual void start()
    {
        std::list<int> answer = findHash();
        auto it = answer.begin();
        while(it != answer.end())
        {
            std::cout << *it << " ";
            *it++;
        }
    }
};

class partialSearch : public Search
{
private:
    std::list<std::pair<int, int>> findPartialHash()
    {
        int textHash, patternHash; textHash = patternHash = 0;
        size_t operations = 0; // Number of search loop iterations
        const int Q = 101; // Prime number
        int h = 1; // Multiplier
        std::list<std::pair<int, int>> positions;
        int stringSize = 0; // Compare size of the pattern to string
        int textLength = text.length();
        int patternLength = pattern.length();

        // Calculate h (== pow(alph, patternLength - 1))
        for(size_t i = 0; i < patternLength - 1; i++){
            h = (h * alph) % Q;
        }

        // Calculate starting hash
        for(size_t i = 0; i < patternLength; i++){
            textHash = ((alph * textHash) + text[i]) % Q;
            patternHash = ((alph * patternHash) + pattern[i]) % Q;
        }

        // Rolling hashing
        for(size_t i = 0; i < textLength - patternLength; i++)
        {
            std::pair<int, int> coincidence; // Here we store data for every coincidence
            operations++;
            // Compare hashes of text and pattern
//            if(textHash == patternHash )
//            {
                // Check chars match
                // Here we make partial comparison
                int matches = 0; // Recording number of matched chars, then find % of coincidence
                for(size_t j = 0; j < patternLength; j++)
                {
                    stringSize = j + 1;
                    if(text[i + j] == pattern[j]) matches++;
                }
                int percentage = (matches / stringSize) * 100;
                coincidence.first = i;
                coincidence.second = percentage;
                if(percentage > 70) positions.push_back(coincidence);
            //}
           //Calculate next hash
            textHash = ((alph * (textHash - (h * text[i]))) + text[i + patternLength]) % Q;
            if(textHash < 0) textHash += Q;
        }
        return positions;
    }
public:
    void start() override
    {
        std::list<std::pair<int,int>> answer = findPartialHash();
        auto it = answer.begin();
        while(it != answer.end())
        {
            std::cout << "\nPosition : " << it->first << "\tCoincidence % : "<< it->second << " ";
            *it++;
        }
    }
};

int main() {
    std::cout << "\n\tFull coincidence search:\n";
    Search search;
    search.printText();
    search.setPattern(std::string("early"));
    search.start();
    std::cout << std::endl;
    search.setPattern(std::string("Paris"));
    search.start();
    search.setPattern("Pariz");
    search.start();

    std::cout << "\n\tPartial coincidence search:\n";
    partialSearch search2;
    search2.printText();
    search2.setPattern("Paris");
    search2.start();
    search2.setPattern(std::string("early"));
    search2.start();

    return 0;
}
