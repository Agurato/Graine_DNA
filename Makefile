window :
	g++ -o window.out window.cpp -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system

mainStrandTest :
	g++ mainStrandTest.cpp utils/utils.cpp dna_strands/EarStrand.cpp -o mainStrandTest -std=c++11

clean :
	rm *.o mainStrandTest window
