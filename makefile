

grid : obj/grid.o 
	g++ -std=c++11 -o bin/grid obj/grid.o 

obj/%.o : %.cpp
	g++ -c -std=c++11 $< -o $@
