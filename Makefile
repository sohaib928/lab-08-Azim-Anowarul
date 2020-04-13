main: main.o imagehelpers.o imagefuncs.o
	g++ -o main main.o imagehelpers.o imagefuncs.o

main.o: main.cpp imagehelpers.h imagefuncs.h

imagehelpers.o: imagehelpers.cpp imagehelpers.h

imagefuncs.o: imagefuncs.cpp imagefuncs.h


clean:
	rm -f main *.o
