#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <algorithm>

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
    std::unordered_map<std::string, long> text_freq;
    std::string word;
    if(input_mode == "file"){
        freopen("file.in", "r", stdin);
        while(scanf("%s", &word) != EOF){
            scanf("%s", &word);
            text_freq[word]++;
        }
    }
    std::vector<std::pair<std::string, long>> sorted(text_freq.begin(), text_freq.end());
    std::sort(sorted.begin(), sorted.end(), comp);
    for(const auto& element:sorted){
        std::cout<<"Word: "<<element.first<<" Amount of times found: "<<element.second<<std::endl;
    }
}