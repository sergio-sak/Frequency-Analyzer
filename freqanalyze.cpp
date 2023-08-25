#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>

int main(){
    std::string input_mode; //File or terminal
    do {
        std::cout<<"Input through terminal or files(terminal/file): ";
        std::cin>>input_mode;
    }
    while (input_mode != "file" && input_mode != "terminal");
    if(input_mode == "file"){

    }
    else {
    }
}