parser :
	g++ mainParserTest.cpp parts/XMLData.cpp utils/utils.cpp -o parser.out -std=c++11 -lxerces-c

utilsTest :
	g++ mainUtilsTest.cpp utils/utils.cpp -o utilsTest.out -std=c++11

mainEarStrandTest :
	g++ mainEarStrandTest.cpp utils/utils.cpp dna_strands/EarStrand.cpp -o mainEarStrandTest.out -std=c++11

mainCreatureTest :
	g++ mainCreatureTest.cpp utils/utils.cpp parts/XMLData.cpp dna_strands/Strand.cpp dna_strands/EarStrand.cpp DNA.cpp Creature.cpp -o mainCreatureTest.out -std=c++11 -lxerces-c

clean :
	rm mainStrandTest.out parser.out utilsTest.out mainCreatureTest.out
