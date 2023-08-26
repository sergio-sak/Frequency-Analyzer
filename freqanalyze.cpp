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
    if(input_mode == "file"){
        std::unordered_map<std::string, long> text;
        std::string word;
        while(scanf("%s", &word) != EOF){
            scanf("%s", &word);
            text[word]++;
        }
    }
    std::vector<std::pair<std::string, long>> sorted(text.begin(), text.end());
    std::sort(sorted.begin(), sorted.end(), comp);
}