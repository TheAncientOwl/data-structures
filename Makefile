CXXFLAGS+=-g -Wall -std=c++17

init: clean color timer

clean:
	@rm -rf out
	@rm -f executable.elf64
	@mkdir out

dummy: init
	g++ -Wall -std=c++17 -c ./Dummy/Dummy.cpp -o ./out/Dummy.o
	g++ -Wall -std=c++17 -c ./Dummy/test.cpp -o ./out/test.o
	@make executable

executable:
	@g++ -o executable.elf64 ./out/*.o
	@./executable.elf64

color:
	@g++ -Wall -std=c++17 -c ./ccolor/ccolor.cpp -o ./out/ccolor.o

timer:
	@g++ -Wall -std=c++17 -c ./Timer/Timer.cpp -o ./out/Timer.o

