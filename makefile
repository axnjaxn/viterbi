all: viterbi-test

CFLAGS = `byteimage-config --cflags` -std=c++11

viterbi.o: viterbi.h viterbi.cpp
	$(CXX) viterbi.cpp -c $(CFLAGS)

main.o: viterbi.h main.cpp
	$(CXX) main.cpp -c $(CFLAGS)

viterbi-test: viterbi.o main.o
	$(CXX) viterbi.o main.o -o $@ `byteimage-config --libs`

clean:
	rm -f *~ *.o viterbi-test

run: viterbi-test
	./viterbi-test
