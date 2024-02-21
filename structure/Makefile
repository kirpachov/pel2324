
build/myapp: build/myfunction.o tools/myapp.cpp
	g++ -std=c++11 tools/myapp.cpp -I include build/myfunction.o -o build/myapp

build/myfunction.o: src/myfunction.cpp include/myfunction.hpp
	g++ -std=c++11 -c src/myfunction.cpp -o build/myfunction.o -I include/


