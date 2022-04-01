// FILE: rand.cpp
// CLASS IMPLEMENTED: statistician (see random.h for documentation)

#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include "random.h"

using namespace std;

namespace coen79_lab2
{
    //parameterized constsructor
    rand_gen :: rand_gen(int init_seed, int init_multiplier, int init_increment, int init_modulus)
    {
      seed = init_seed;
      multiplier = init_multiplier;
      increment = init_increment;
      modulus = init_modulus;
    }

    //set seed variable to the input newSeed value
    void rand_gen :: set_seed(int newSeed)
    {
      seed = newSeed;
    }

    //returns the new seed calculated with the private variables and set seed to this new seed
    int rand_gen :: next()
    {
      seed = (multiplier * seed + increment) % modulus;
      return seed;
    }

    //print out all the private variables' values
    void rand_gen :: print_info()
    {
      cout << "Seed: " << seed << endl;
      cout << "Multiplier: " << multiplier << endl;
      cout << "Incremenet: " << increment << endl;
      cout << "Modulus: " << modulus << endl;
    }
}
