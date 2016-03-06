#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>

#include "../utils/utils.hpp"
#include "../DNA.hpp"
#include "../dna_strands/EarStrand.hpp"
#include "../dna_strands/EyeStrand.hpp"
#include "../dna_strands/LimbStrand.hpp"
#include "../dna_strands/MouthStrand.hpp"
#include "../dna_strands/NostrilStrand.hpp"
#include "../dna_strands/Strand.hpp"
#include "../Creature.hpp"

DNA* createRandomDNA();
DNA mating(DNA strand1, DNA strand2);
