all:
	@echo "make all"
	g++ -std=c++14 main.cpp track.cpp connection.cpp junction.cpp node.cpp train.cpp input.cpp djikstra.cpp -o trains.out

clean:
	@echo "make clean"
	rm *.out