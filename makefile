cc = g++
flags = -std=c++17
flags += -Wall
flags += -g


link = $(cc) $(flags) -o
compile = $(cc) $(flags) -c

cross-word: main.cc
	$(link) $@ $^


clean:
	$(RM) cross-word
