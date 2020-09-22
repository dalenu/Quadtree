qttest: qttest.cpp Quadtree.cpp Quadtree.h
	g++ -std=c++11 -o qttest qttest.cpp

test: qttest
	./qttest < t01/test.in > output.txt
	diff output.txt t01/test.out
	./qttest < t02/test.in > output.txt
	diff output.txt t02/test.out
	./qttest < t03/test.in > output.txt
	diff output.txt t03/test.out
	./qttest < t04/test.in > output.txt
	diff output.txt t04/test.out
	./qttest < t05/test.in > output.txt
	diff output.txt t05/test.out
	./qttest < t06/test.in > output.txt
	diff output.txt t06/test.out
	./qttest < t07/test.in > output.txt
	diff output.txt t07/test.out

clean:
	rm qttest
	rm output.txt
