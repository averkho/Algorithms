#include <iostream>
#include <string>

void naive_search(std::string text, std::string pattern){

    size_t n=text.size();
    size_t m=pattern.size();

    bool match=false;

    for (int i=0; i<n; ++i){

        int j=0;

        while (j<(n-m+1)){

            if (text[i+j]!=pattern[j]){
               
                break;
            }
            ++j;
        }

        if (j==m){

            std::cout << " The pattern match at shift " << i << std::endl;
            match=true;

        }
    }

    if (match==false){
        std::cout << "No match for " << pattern << " is found in " << text << std::endl;
    }

}

int main(){

    std::string text;
    std::string pattern;

    std::cout << "Enter the string " << std::endl;
    std::cin >> text;

    std::cout << std::endl <<  "Enter the pattern to be searched " << std::endl;
    std::cin >> pattern;

    std::cout << std::endl;

    naive_search(text, pattern);

    return 0;
}