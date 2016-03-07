CC=g++
CFLAGS= -std=c++11 -Wall
LDFLAGS= -lxerces-c

functions= bin/sim/functions.o
strands= bin/dna_strands/EarStrand.o bin/dna_strands/EyeStrand.o bin/dna_strands/LimbStrand.o bin/dna_strands/MouthStrand.o bin/dna_strands/NostrilStrand.o bin/dna_strands/SkinStrand.o bin/dna_strands/Strand.o
utils= bin/utils/utils.o
xml= bin/sim/XMLData.o
all= $(strands) $(xml) $(utils) $(functions) bin/DNA.o bin/Creature.o

simulation : bin/mainSimulation.o $(all)
	$(CC) -o simulation.out $^ $(CFLAGS) $(LDFLAGS)

parserTest : bin/mainParserTest.o $(utils) $(xml)
	$(CC) -o parserTest.out $< $(utils) $(xml) $(CFLAGS) $(LDFLAGS)

utilsTest : bin/mainUtilsTest.o $(utils)
	$(CC) -o utilsTest.out $< $(utils) $(CFLAGS)

creationTest : bin/mainCreationTest.o $(all)
	$(CC) -o creationTest.out $^ $(CFLAGS) $(LDFLAGS)

earStrandTest : bin/mainEarStrandTest.o $(strands) $(utils) $(xml)
	$(CC) -o earStrandTest.out $^ $(CFLAGS) $(LDFLAGS)

reproductionTest : bin/mainReproductionTest.o $(functions) $(strands) $(utils) $(xml) bin/DNA.o
	$(CC) -o reproductionTest.out $^ $(CFLAGS) $(LDFLAGS)

creatureTest : bin/mainCreatureTest.o $(strands) $(utils) $(xml) bin/DNA.o bin/Creature.o
	$(CC) -o creatureTest.out $^ $(CFLAGS) $(LDFLAGS)

bin/mainSimulation.o : mainSimulation.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin/%Test.o : %Test.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin/DNA.o : DNA.cpp DNA.hpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin/Creature.o : Creature.cpp Creature.hpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin/utils/utils.o : utils/utils.cpp utils/utils.hpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin/sim/XMLData.o : sim/XMLData.cpp sim/XMLData.hpp
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

bin/sim/functions.o : sim/functions.cpp sim/functions.hpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin/dna_strands/%.o: dna_strands/%.cpp dna_strands/%.hpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm bin/*.o
	rm bin/*/*.o

clean_all : clean
	rm *.out
	rm *.csv
