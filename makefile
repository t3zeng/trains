all:
	@echo "make all"
	g++ main.cpp track.cpp connection.cpp junction.cpp node.cpp train.cpp input.cpp -o trains.out

clean:
	@echo "make clean"
	rm *.out