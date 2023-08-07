all: compile link run

delete:
	del *.o

compile:
	g++ -c main.cpp src/*.cpp -ISFML/include

link:
	g++ *.o -o main -LSFML/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 

run:
	./main.exe
