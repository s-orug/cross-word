// Copyright 2022 Sai Durga Rithvik Oruganti
#include "./cross-word.h"


int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);

    string puzzleFileName;
    string wordsFileName;
    vector<vector<char>> puzzle;
    vector<string> words;

    std::cout << "CROSS WORD PUZZLE SOLVER\n" << std::endl;
    std::cout << "Created By\t:\tSai Durga Rithvik Oruganti" <<
        "\n" << "Created Date\t:\t05/19/2022\n" << std::endl;
    std::cout << "Enter the Puzzle File Name: ";
    std::cin >> puzzleFileName;
    std::cout << "Enter the Words File Name: ";
    std::cin >> wordsFileName;

    readPuzzle(puzzle, puzzleFileName);
    readWords(words, wordsFileName);


    for (auto word : words) {
        vector<int> start;
        vector<int> end;
        bool found;
        for (char w : word){
            if (w == ' ') {
                remove(word.begin(), word.end(), ' ');
                word.resize(word.size() - 1);
                break;            
            }
        }

        found = findWord(puzzle, word, start, end);
        printLocation(word, start, end, found);
        end.clear();
        start.clear();
    }    
    std::cout << std::endl;

    for (unsigned int i = 0; i < POINTS.size(); i++){
        for (unsigned int j = 0; j < POINTS[i].size(); j++)
        {
            printf("\033[1;%dm %c \033[0m", POINTS[i][j], puzzle[i][j]);
        }
        printf("\n");
    }

    return 0;
}
