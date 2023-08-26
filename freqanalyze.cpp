#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <cctype>

bool comp(std::pair<std::string, long> p1, std::pair<std::string, long> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int main(){
    std::string input_mode; //File or terminal
    do {
        std::cout<<"Input through terminal or files(terminal/file): ";
        std::cin>>input_mode;
    }               
    while (input_mode != "file" && input_mode != "terminal");

    std::unordered_map<std::string, long> freq;
    std::string word, cur;   
    std::ifstream infile;
    if(input_mode == "file"){
        infile.open("file.in");
        while(infile>>word){
            if(std::ispunct(word.back())){
                word.pop_back();
                freq[word]++;
                continue;        
            }
            freq[word]++;        
        }
    }
    else {
        std::cout<<"Enter Text:\n";
        std::cin.ignore();
        getline(std::cin, word);
        std::vector<std::string> words;
        for(int i = 0; i < word.size(); ++i){
            if(word[i] == ' ' || std::ispunct(word[i])){
                words.push_back(cur);
                cur.clear();
            }
            else{
                cur.push_back(word[i]);
            }
        }
        for(int i = 0; i < words.size(); ++i){
            freq[words[i]]++;        
        }
    }
    std::vector<std::pair<std::string, long>> sorted(freq.begin(), freq.end());
    std::sort(sorted.begin(), sorted.end(), comp);
    for(const auto& element:sorted){
        std::cout<<"Word: \""<<element.first<<"\". Amount of times found: "<<element.second<<std::endl;
    }
}