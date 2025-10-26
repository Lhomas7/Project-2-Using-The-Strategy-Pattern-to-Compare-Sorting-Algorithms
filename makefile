#This makefile will compile, run, and clean the program executables

compile:
	g++ -Wall main.cpp -o sort.exe

run:
	./sort.exe

clean:
	rm sort.exe
