all:
	@echo "make all"
	g++ trains.cpp track.cpp connection.cpp junction.cpp node.cpp -o trains.out

clean:
	@echo "make clean"
	rm *.out