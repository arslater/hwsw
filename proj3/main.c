////////////////////////////
// proj3 by Anita Slater
// @formatter:off

#include"enigma.h"
#include<stdio.h>
#include<stdlib.h>



int main(int argc, char ** argv)
{
   Rotor rotor;
   Rotor *rotor_ptr =(Rotor *) malloc(sizeof(Rotor));
    int i;

   rotor_ptr = setRotor(rotor_ptr);

//   printf("Setting rotor1 to index 7\n");

    //int vals[] = {'7','3','0','1','9','5','2','6','4','2'};

    //void setRotorIndex(Rotor *, int, int); // TOFIX: make this a return a boolean, if it is a vlaid index true

   for( i = 1; i <argc; i++)
   {
       printf("setting rotor %d to index: %d\n", i,atoi(argv[i]) );
       setRotorIndex(rotor_ptr,i, atoi(argv[i]));
   }
   getRotorVal(rotor_ptr ->rotor1);
  // printf("New index of rotor1: %d\n", rotor_ptr -> rotor1);
  // printf("The value that rotor1 represents %d\n", getRotorVal(rotor_ptr, rotor_ptr -> rotor1));
   printRotors(rotor_ptr, true);
   starCrypt(rotor_ptr, "hello world");
   return 0;

}