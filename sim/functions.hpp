#ifndef DEF_SIM_FUNCTIONS
#define DEF_SIM_FUNCTIONS

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>

#include "../utils/utils.hpp"
#include "../DNA.hpp"
#include "../dna_strands/EarStrand.hpp"
#include "../dna_strands/EyeStrand.hpp"
#include "../dna_strands/LimbStrand.hpp"
#include "../dna_strands/MouthStrand.hpp"
#include "../dna_strands/NostrilStrand.hpp"
#include "../dna_strands/SkinStrand.hpp"
#include "../dna_strands/Strand.hpp"
#include "../Creature.hpp"

#include "XMLData.hpp"
#include "functions.hpp"

#define DEATH_CHANCE 500
#define ENV_FACTOR 5

enum MutationTypes {add = 0, del, sub};

DNA createRandomDNA();
DNA mating(DNA strand1, DNA strand2);
DNA matingMut(DNA dnaStrand1, DNA dnaStrand2);
std::vector<Strand*> AddMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType);
std::vector<Strand*> DelMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType);
std::vector<Strand*> SubMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType);
std::map<int, Creature> mateAndKill(std::map<int, Creature> creatures, int* counter);
void registerGen(int gen, std::map<int, Creature> creatures, std::vector<std::string>* saveLines);
void saveCsv(std::vector<std::string> saveLines);

#endif
