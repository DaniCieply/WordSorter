#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void alphabetic_sort(std::string input_file_path, std::string output_file_path) {
    std::fstream infile(input_file_path, std::ios::in); // File to sort words from
    std::fstream outfile; // File to output sorted words
    std::vector<std::string> words;
    std::string word;

    if(infile.is_open()) {
        outfile.open(output_file_path, std::ios::out); // Open file to output to

        while(infile) { // Reads each word from the file into a vector
            infile >> word;
            words.push_back(word);
        }

        std::sort(words.begin(), words.end()); // Sorts the words in the vector alphabetically

        for(std::string word : words) { // Outputs one word on each line from the vector into the output file
            outfile << word << "\n";
        }

        std::cout << "Success! Your sorted words are in " << output_file_path << std::endl;
        std::cin; 

    } else { // If file doesn't open, do this
        std::cerr << "ERROR! File to sort does not exist!" << std::endl;
        std::cin;
    }
    infile.close();
}

int main() {
    std::string infile = "infile.txt";
    std::string outfile = "outfile.txt";

    // Gathers path of file to to sort words from
    std::cout << "Hello! Which file would you like to sort alphabetically? Insert the path: ";
    std::cin >> infile;

    // Gathers path of file to output sorted words to
    std::cout << "Which file would you like to output the sorted words to? Insert the path: ";
    std::cin >> outfile;

    alphabetic_sort(infile, outfile);

    return 0;
}
