parser :
	g++ mainParserTest.cpp parts/XMLData.cpp utils/utils.cpp -o parser.out -std=c++11 -lxerces-c

utilsTest :
	g++ mainUtilsTest.cpp utils/utils.cpp -o utilsTest.out -std=c++11

mainStrandTest :
	g++ mainStrandTest.cpp utils/utils.cpp dna_strands/EarStrand.cpp -o mainStrandTest.out -std=c++11

clean :
	rm mainStrandTest.out parser.out utilsTest.out
