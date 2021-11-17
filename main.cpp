/*
 * TODOs
 * Rabin-Karp Alg implementation
 * Partly match implementation (class-styled)
 * Matching % sort function
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define FILEPATH "/home/notahacker/Documents/string_search/text.txt"

class Search{
private:
    std::string text; // text, where we'll search image
    std::string image; // image to find
public:
    Search(){ text = image = ""; };
    Search(std::string text_, std::string image_) { text = text_; image = image_; }
    ~Search(){};

    //Getters
    std::string getText(){ return text; }
    std::string getImage(){ return image; }
    //Setters
    void setText(std::string text_){ text = text_; }
    void setImage(std::string image_){ image = image_; }

    // Set text from file
    void setFromFile(std::ifstream file)
    {
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
};

int main() {
    Search search();
    search.setFromFile();

    return 0;
}
