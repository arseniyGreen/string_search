#ifndef STRING_SEARCH_KMP_H
#define STRING_SEARCH_KMP_H

#define FILEPATH "C:/string_search/dataset.txt"

class KMP{
private:
    std::string pattern; // pattern
    std::string text; // text

    void lps_func(int M, std::vector<int>& lps_array)
    {
        int len = 0; // length of the biggest suffix
        lps_array[0] = 0; // lps[0] always 0
        /* Calculate lps[i] for i = 1 to M - 1 */
        size_t i = 1;
        while(i < M)
        {
            if(pattern[i] == pattern[len])
            {
                len++;
                lps_array[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                {
                    len = lps_array[len - 1];
                }
                else
                {
                    lps_array[i] = 0;
                    i++;
                }
            }
        }
    }

    std::list<int> kmp()
    {
        int n = text.length();
        int m = pattern.length();

        if(n < 1) throw std::runtime_error("Incorrect text");
        if(m < 1) throw std::runtime_error("Incorrect pattern");

        std::vector<int>Lps(m);
        std::list<int> answer;
        lps_func(m, Lps); //make lps array

        int i = 0, j = 0;
        while(i < n){
            if(pattern[j] == text[i]){
                j++; i++;
            }
            if(j == m)
            {
                j = Lps[j - 1];
                answer.push_back(i - j);
            }
            else if(i < n && pattern[j] != text[i]){
                if(j != 0) j = Lps[j - 1];
                else i++;
            }
        }
        return answer;
    }

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
            throw std::runtime_error("Unable to open file");
        }
    }

public:
    KMP(){ text = pattern = ""; }
    KMP(std::string pattern_, std::string text_){ pattern = pattern_; text = text_; }
    ~KMP(){}

    void setText(std::string text_){ text = text_; }
    void setPattern(std::string pattern_){ pattern = pattern_; }

    std::string getText() { return text; }
    std::string getPattern() { return pattern; }

    void search(std::string pattern_)
    {
        pattern = pattern_;
        setFromFile();
        std::cout << "\nSearching : " << pattern << "...\n";
        std::list<int> ans = kmp();
        auto it = ans.begin();
        while(it != ans.end()){
            std::cout << *it << " ";
            *it++;
        }
    }
};

#endif //STRING_SEARCH_KMP_H
