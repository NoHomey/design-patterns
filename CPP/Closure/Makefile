compile=g++ -std=c++11 -Wall

test: clean Closure.o
	${compile} test.cc Closure.o Inner.o
	./a.out

Closure.o: Inner.o
	${compile} -c Closure.cc

Inner.o:
	${compile} -c Inner.cc

clean:
	rm -f *.o a.out
