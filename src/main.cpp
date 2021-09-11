#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> file_to_vect(std::string input_file_path) {
    std::fstream infile(input_file_path, std::ios::in);
    std::vector<std::string> words;
    std::string word;

    if(infile.is_open()) {
        while(infile) { // Reads each word from the file into a vector
            infile >> word;
            words.push_back(word);
        }
    } else {
        std::cerr << "ERROR! File to sort does not exist!";
    }
    infile.close();
    return words;
}

void vect_to_file(std::string output_file_path, std::vector<std::string> words) { // Prints each item in a string vector to a file
    std::fstream outfile(output_file_path, std::ios::out);

    if(outfile.is_open()) {
        for(std::string word : words) { // Outputs one word on each line from the vector into the output file
            outfile << word << "\n";
        }
    } else {
        std::cerr << "ERROR! File to output to does not exist!";
    }
    outfile.close();
}

int main() {
    std::vector<std::string> words;
    std::string infile_path = "infile.txt";
    std::string outfile_path = "outfile.txt";
    int sort_type_selected;

    // Gathers path of file to to sort words from
    std::cout << "Enter path of file to sort: ";
    std::cin >> infile_path;

    // Gathers path of file to output sorted words to
    std::cout << "Enter path of file to output: ";
    std::cin >> outfile_path;

    // Asks for user to enter which way they want words sorted
    std::cout << "Alphabetically (0) or reverse alphabetically (1): ";
    std::cin >> sort_type_selected; 

    words = file_to_vect(infile_path); 

    switch(sort_type_selected) {
        case 0:
            std::sort(words.begin(), words.end());
            break;
        case 1:
            std::sort(words.begin(), words.end()); // First sorts alphabetically,
            std::reverse(words.begin(), words.end()); // then reverses the sorted vector
            break;
        default:
            std::cerr << "ERROR! Sort type not recognized!";
            return 1;
    }

    vect_to_file(outfile_path, words);
    return 0;
}
