// Copyright 2021 Sai Durga Rithvik Oruganti
#include "./cross-word.h"


int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);

    string puzzleFileName="puzzle.txt";
    string wordsFileName="words.txt";
    vector<vector<char>> puzzle;
    vector<string> words;

   /* std::cout << "Enter the Puzzle File Name: ";
    std::cin >> puzzleFileName;
    std::cout << "Enter the Words File Name: ";
    std::cin >> wordsFileName;*/

    //cout << "\033[1;41mbold red text\033[0m\n";

    readPuzzle(puzzle, puzzleFileName);
    readWords(words, wordsFileName);
    //printPuzzle(puzzle);
    //printWords(words);


    for (auto word : words) {
        vector<int> start;
        vector<int> end;
        bool found;
        found = findWord(puzzle, word, start, end);
        printLocation(word, start, end, found);
        end.clear();
        start.clear();
    }    

    for (unsigned int i = 0; i < POINTS.size(); i++){
        for (unsigned int j = 0; j < POINTS[i].size(); j++)
        {
            printf("\033[1;%dm %c \033[0m", POINTS[i][j], puzzle[i][j]);
        }
        printf("\n");
    }
    /*for (unsigned int i = 0; i < POINTS.size(); i++){
        for (unsigned int j = 0; j < POINTS[i].size(); j++)
        {
            printf("%d\t", POINTS[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}
