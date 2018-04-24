//
// Created by anita on 3/29/18.
// @formatter:off

#include "enigma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Rotor *setRotor(Rotor *rt_ptr)
{
    printf("Resetting all of the rotor values...fam\n");

    //int vals[] = {'7','3','0','1','9','5','2','6','4','2'};
    //rt_ptr->rotor_vals = vals;

    rt_ptr -> rotor1 = 2;
    rt_ptr -> rotor2 = 0;
    rt_ptr -> rotor3 = 0;

    //_ROTOR_VALUES =

    return(rt_ptr);

}
int getRotorVal(int rt_index)
{
    int vals[] = {7,3,0,1,9,5,2,6,4,2};
    //printf("new value.........'%d'\n", vals[rt_ptr->rotor1]);

    return(vals[rt_index]);
}
void setRotorIndex(Rotor *rt_ptr, int rt_num, int rt_index)
{
    if(rt_num<=3 && rt_num>0)
    {
        switch(rt_num)
        {
            case 1:
                //printf("Changing the index of rotor%d to '%d'\n", rt_num, rt_index);
                rt_ptr -> rotor1 = rt_index;
                break;
            case 2:
               // printf("Changing the index of rotor%d to '%d'\n", rt_num, rt_index);
                rt_ptr -> rotor2 = rt_index;
                break;
            case 3:
                printf("Changing the index of rotor%d to '%d'\n", rt_num, rt_index);
                rt_ptr -> rotor3 = rt_index;
                break;
            default:
                printf("What chu' doin'?!\n");
        }
    }
    else
    {
        printf("What ARR ya' gettin' at?! You can't have an invalid index!\n");
    }

}
void printRotors(Rotor* rt_ptr, bool displayRotorVals)
{
    printf("Rotor #1 is set to index#%d\n", rt_ptr -> rotor1);
    printf("Rotor #2 is set to index#%d\n", rt_ptr -> rotor2);
    printf("Rotor #3 is set to index#%d\n", rt_ptr -> rotor3);

    if(displayRotorVals)
    {
        printf("1:%d",getRotorVal(rt_ptr ->rotor1));
        printf(" 2:%d",getRotorVal(rt_ptr ->rotor2));
        printf(" 3:%d\n",getRotorVal(rt_ptr ->rotor3));
    }
}
char* getSecretMessage() //TOFIX: awesome-ify this by having it take a file pointer!
{
    char * inputString = malloc(sizeof(char)*65);
    printf("Rotors have been set, enter in the secret message:\n");
    fgets(inputString,64, stdin);
    printf("Input text supplied is: %s\n", inputString);

    inputString = strncpy(inputString,inputString,sizeof(inputString));

    return (inputString);

}

void starCrypt(Rotor * rt_ptr, char * inputString, char actionType)
{
    // the '*' wildcard is often denoted as a star.
    // because encrypt and decrypt only differ by the prescence of an 'en' on 'de'
    // the following regular expression would match both: *crypt. So this
    // fucntion will be able to handle both 'crypting.

    int key;
    int i = 0;
    char newLetter;

    while(inputString[i] != '\n')
    {
        key = getRotorVal(rt_ptr ->rotor1)+getRotorVal(rt_ptr ->rotor2)+getRotorVal(rt_ptr ->rotor3);
        //printRotors(rt_ptr, true);
        if(actionType == 'd')
        {
            printf("encrypted letter: '%c' | unencrypted to letter: ",inputString[i]);
            //newLetter = inputString[i]+key;
            printf("%c\n", getNewLetter(inputString[i],(-1*key)));
           // printf("--------------------------------------------\n");
        }
        else
        {
            //assumes test for valid input has already been done
            printf("unencrypted letter: '%c' | encrypted to letter: ",inputString[i]);
            //newLetter = inputString[i]+key;
            printf("%c\n", getNewLetter(inputString[i],key));
           // printf("--------------------------------------------\n");
        }
        incrementRotor(rt_ptr);
        i++;
    }
}
char getNewLetter(char currentLetter, int key)
{
    int newLetter;
    int  i;
    char LETTERS[] = {'A','B','C','D','E','F','G','H','I','J','K',
                      'L','M','N','O','P','Q','R','S','T','U','V',
                      'W','X','Y','Z',' '};

    newLetter = (char)((currentLetter == ' ') ? 26 : currentLetter - 65);
    key += newLetter;
    key = (key > 26) ? key-27  :key;    // UGLY logic here, change this
    key = (key < 0)  ?(key+27) :key;  //
    //printf("key:%d *****%d ", key ,newLetter);
    //printf("The ascii-trick value is %d, in the array is '%c' the given value is %d\n",newLetter, LETTERS[newLetter], currentLetter);


    return LETTERS[key];
}
void incrementRotor(Rotor * rt_ptr)
{
    //int newRotorIndex;

    if( rt_ptr ->rotor1 == 9)
    {
        rt_ptr -> rotor1 = 0;

        if( rt_ptr->rotor2 == 9)
        {
            rt_ptr ->rotor2 = 0;
            rt_ptr ->rotor3++;
        }
        else
            (rt_ptr->rotor2)++;
    }
    else
        (rt_ptr->rotor1)++;
    //return(newRotorIndex);
}