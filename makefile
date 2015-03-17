all: viterbi-test

CFLAGS = -std=c++11

viterbi.o: grid.h viterbi.h viterbi.cpp
	$(CXX) viterbi.cpp -c $(CFLAGS)

main.o: grid.h viterbi.h main.cpp
	$(CXX) main.cpp -c $(CFLAGS)

viterbi-test: viterbi.o main.o
	$(CXX) viterbi.o main.o -o $@

clean:
	rm -f *~ *.o viterbi-test

run: viterbi-test
	./viterbi-test
