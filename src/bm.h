#ifndef STRING_SEARCH_BM_H
#define STRING_SEARCH_BM_H

#define ALPH 256
#define FILEPATH "../dataset.txt"

class BM
{
private:
    std::string text;
    std::string pattern;
    int badChar[ALPH];

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
            throw std::runtime_error("Unable to open file");
        }
    }

    std::list<int> search()
    {
        int m = pattern.size();
        int n = text.size();

        int* mPtr = &m;
        int* nPtr = &n;

        if(*mPtr < 1) throw std::runtime_error("Incorrect pattern.");
        if(*nPtr < 1) throw std::runtime_error("Incorrect text");

        std::list<int> returnList;

        /* Bad char heuristic */
        for(size_t i = 0; i < ALPH; i++) badChar[i] = -1; // Init
        for(size_t i = 0; i < *mPtr; i++) badChar[(int)pattern[i]] = i;
        /* BCH end */

        int s = 0; /* s - shift of pattern */
        while(s <= (nPtr - mPtr))
        {
            int j = *mPtr - 1;
            /* Keep reducing j while chars of pattern and txt match at this shift */
            while(j >= 0 && pattern[j] == text[s + j]) j--;

            /* If pattern present at this shift, j = -1 after above loop */
            if(j < 0)
            {
                returnList.push_back(s);
                /* Shift pattern that the next char in text aligns with last occurrence of it in pattern
                 * Condition s + mPtr < nPtr necessary for case when pattern occurs at the end of text */
                s += (s + *mPtr < *nPtr) ? *mPtr - badChar[text[s + *mPtr]] : 1;
            }
            else
            {
                /* Shift pattern so bad char in text aligns with last occurrence of it in pattern
                 * max function needed to get positive shift*/

                s += std::max(1, j - badChar[text[s + j]]);
            }
        }
        return returnList;
    }

public:
    void setPattern(std::string pattern_) { pattern = pattern_; }
    void setText(std::string text_) { text = text_; }

    std::string getText(){ return text; }
    std::string getPattern() { return pattern; }

    void start(std::string pattern_)
    {
        setFromFile();
        setPattern(pattern_);
        std::cout << "Searching : " << pattern_ << "...\n";
        std::list<int> res = search();
        auto it = res.begin();
        while(it != res.end())
        {
            std::cout << *it << " ";
            *it++;
        }
    }
};

#endif