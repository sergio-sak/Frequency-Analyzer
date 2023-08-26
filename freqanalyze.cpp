#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <cctype>

bool comp(std::pair<std::string, long> p1, std::pair<std::string, long> p2){
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
    std::string word;   
    std::ifstream infile;
    infile.open("file.in");
    if(input_mode == "file"){
        while(infile>>word){
            if(std::ispunct(word.back())){
                word.pop_back();
                freq[word]++;
                continue;        
            }
            freq[word]++;        
        }
    }
    std::vector<std::pair<std::string, long>> sorted(freq.begin(), freq.end());
    std::sort(sorted.begin(), sorted.end(), comp);
    for(const auto& element:sorted){
        std::cout<<"Word: \""<<element.first<<"\". Amount of times found: "<<element.second<<std::endl;
    }
}