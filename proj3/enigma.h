//
// Created by anita on 3/29/18.
//
// @formatter:off

#ifndef PROJ3_ENIGMA_H
#define PROJ3_ENIGMA_H
#include <stdbool.h>
struct rotor
{
    int rotor1; /* Contains the index, in the array, of the roters */
    int rotor2; /*                                                 */
    int rotor3; /*    */

    int rotor_vals[11];
};
int _ROTOR_VALUES[11];
//extern const static char _ROTOR_VALUES[11];
typedef struct rotor Rotor;

void incrRotor(int rotor);  // changes the struct value of the node passed to it
Rotor *setRotor(Rotor *);

void setRotorIndex(Rotor *, int, int);
int getRotorVal(int);
void printRotors(Rotor*, bool);
char* getSecretMessage();
void starCrypt(Rotor * rt_ptr, char * intputString);


#endif //PROJ3_ENIGMA_H
