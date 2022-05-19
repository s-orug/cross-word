// Copyright 2022 Sai Durga Rithvik Oruganti
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;

vector<vector<int>> POINTS;

string reverse(string word);
void readPuzzle(vector<vector<char>> &puzzle, string filename);
void readWords(vector<string> &words, string filename);
void printPuzzle(const vector<vector<char>> &puzzle);
void printWords(const vector<string> &words);
void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found);
bool vertical(const vector<vector<char>> &puzzle, string word,
              vector<int> &start, vector<int> &end);
bool horizontal(const vector<vector<char>> &puzzle, string word,
              vector<int> &start, vector<int> &end);
bool right(const vector<vector<char>> &puzzle, string word,
              vector<int> &start, vector<int> &end);
bool left(const vector<vector<char>> &puzzle, string word,
              vector<int> &start, vector<int> &end);
bool findWord(const vector<vector<char>> &puzzle, string word,
              vector<int> &start, vector<int> &end);
void add_point(int x, int y, int x1, int y1, string word);

string reverse(string word) {
  if (word.length() == 1) return word;
  return word[word.length()-1] + reverse(word.substr(0, word.length()-1));
}

void printWords(const vector<string> &words) {
    for (auto i : words) {
      cout << i << std::endl;
    }
}

bool findWord(const vector<vector<char>> &puzzle, string word,
              vector<int> &start, vector<int> &end) {
  if (vertical(puzzle, word, start, end) ||
      horizontal(puzzle, word, start, end) ||
      left(puzzle, word, start, end) ||
      right(puzzle, word, start, end)) return true;
  return false;
}

void readWords(vector<string> &words, string filename) {
    std::ifstream fs(filename);
    string word;
    if (fs.is_open()) {
      while (std::getline(fs, word)) {
          words.push_back(word);
      }
    fs.close();
    }
}

void printPuzzle(const vector<vector<char>> &puzzle) {
  string buffer;
  for (vector<char>vec : puzzle) {
    buffer = "";
    for (auto c : vec) {
      std::cout << buffer << c;
      buffer = " ";
    }
    std::cout << " " << std::endl;
  }
}

void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found) {
    if (found == true) {
      //cout << "Word " << word << " found at (" << start[0] << "," <<
       // start[1] << ") -> (" << end[0] << "," << end[1] << ")" << std::endl;
      add_point(start[0], start[1], end[0], end[1], word);

    }
    if (found == false) cout << "Word " << word << " not found" << std::endl;

}

void readPuzzle(vector<vector<char>> &puzzle, string filename) {
    std::ifstream fs(filename);
    string line, word;
    if (fs.is_open()) {
        while (std::getline(fs, word)) {
            std::stringstream ss(word);
            vector<char> vec;
            vector<int> tmp;
            while (getline(ss, line, ' ')) {
                vec.push_back(line[0]);
                tmp.push_back(0);
            }
            puzzle.push_back(vec);
            POINTS.push_back(tmp);
        }
        fs.close();
    }
}

bool vertical(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
                int len = word.length();
                for (int y = 0; y < (int)puzzle.size()-len+1; y++) {
                  for (int x = 0; x < (int)puzzle[0].size(); x++) {
                    string test = "";
                    for (int i = 0; i < len; i++) {
                      test += puzzle[y+i][x];
                    }
                    if (word == test) {
                      start = {y, x};
                      end = {y+len-1, x};
                      return true;
                    }
                    if (reverse(test) == word) {
                      start = {y+len-1, x};
                      end = {y, x};
                      return true;
                    }
                  }
                }
                return false;
              }
bool horizontal(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
                int len = word.length();
                for (int y = 0; y < (int)puzzle.size(); y++) {
                  for (int x = 0; x < (int)puzzle[0].size()-len+1; x++) {
                    string test = "";
                    for (int i = 0; i < len; i++) {
                      test += puzzle[y][x+i];
                    }
                    if (word == test) {
                      start = {y, x};
                      end = {y, x+len-1};
                      return true;
                    }
                    if (reverse(test) == word) {
                      start = {y, x+len-1};
                      end = {y, x};
                      return true;
                    }
                  }
                }
                return false;
              }
bool right(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
                int len = word.length();
                for (int y = 0; y < (int)puzzle.size()-len+1; y++) {
                  for (int x = 0; x < (int)puzzle[0].size()-len+1; x++) {
                    string test = "";
                    for (int i = 0; i < len; i++) {
                      test += puzzle[y+i][x+i];
                    }
                    if (word == test) {
                      start = {y, x};
                      end = {y+len-1, x+len-1};
                      return true;
                    }
                    if (reverse(test) == word) {
                      start = {y+len-1, x+len-1};
                      end = {y, x};
                      return true;
                    }
                  }
                }
                return false;
              }
bool left(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
                int len = word.length();
                for (int y = puzzle.size()-1; y > len - 2; y--) {
                  for (int x = 0; x < (int)puzzle[0].size()-len+1; x++) {
                    string test = "";
                    for (int i = 0; i < len; i++) {
                      test += puzzle[y-i][x+i];
                    }
                    if (word == test) {
                      start = {y, x};
                      end = {y-len+1, x+len-1};
                      return true;
                    }
                    if (reverse(word) == test) {
                      start = {y-len+1, x+len-1};
                      end = {y, x};
                      return true;
                    }
                  }
                }
                return false;
              }

void add_point(int x, int y, int x1, int y1, string word){
    int rand_color = (rand()%6) + 41;
    int length = word.size();
    
    if (y == y1){
        int tmp = x*(x1>x) + x1*(x>x1);
        for (int i = tmp; i < length + tmp; i++){
            POINTS[i][y]= rand_color;
        }
    }
    else if (x == x1){
        int tmp = y*(y1>y) + y1*(y>y1);
        for (int i = 0; i < length; i++){
            POINTS[x][i + tmp]= rand_color;
        }
    }
    else {
        int tmp = x*(x1>x) + x1*(x>x1);
        int tmp2 = y*(y1>y) + y1*(y>y1);
        int slope = -(y1-y)/(x1-x) > 0 ? 1 : -1; // negative because the y axis increments after each row going down.

        for (int i = tmp2; i < length + tmp2; i++){
            for (int j = tmp; j < length + tmp; j++){
                if (i-tmp2 == j-tmp && slope == -1) POINTS[j][i] = rand_color;
                else if (i+j-tmp-tmp2+1 == length && slope == 1) POINTS[j][i] = rand_color;
            }
        }
    }
}