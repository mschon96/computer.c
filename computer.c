/*
Name : Mariah Schon
Class : 2240
Program # : 3
Due Date : Oct 23
Honor Pledge: On my honor as a student of the University
of Nebraska at Omaha, I have neither given nor received
unauthorized help on this homework assignment.

NAME: Mariah Schon
NUID: 581
EMAIL: mschon@unomaha.edu
Partners: CSLC
This is a virtual computer that runs external programs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
   Function Name : execute
Parameters : 
Return value(s) : 
Partners : CSLC
Description : This program will execute the written program
*/
int execute(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand, int mem[]){

    *instructionCounter =0;

    while(*operationCode != 99){
        *instructionRegister = mem[*instructionCounter];

        *operationCode = mem[*instructionCounter] /100;
        *operand = mem[*instructionCounter] %100;

        switch(*operationCode){
            case 10:
                printf("Enter value: ");
                scanf("%d",&mem[*operand]);

                break;

            case 11:
                printf("%d\n", mem[*operand]);

                break;

            case 12:
                while(mem[*operand] != 0){
                    printf("%c%c", (mem[*operand]/100), (mem[*operand]%100));
                    (*operand) ++;
                }
                break;

            case 20:
                *accumulator = mem[*operand];
                 break;

            case 21:
                mem[*operand] = *accumulator;

                break;


            case 30:
                *accumulator += mem[*operand];

                break;

            case 31:
                *accumulator -= mem[*operand];

                break;

            case 32:
                *accumulator /= mem[*operand];

                break;

            case 33:

                *accumulator *= mem[*operand];

                break;

            case 34:
                *accumulator %=mem[*operand];

                break;

            case 40:
                *instructionCounter = (*operand)-1;

                break;

            case 41:
                if(*accumulator < 0)
                    *instructionCounter = (*operand)-1;

                break;


            case 42:
 if (*accumulator ==0 )
                    *instructionCounter = (*operand)-1;

                break;

        }
        (*instructionCounter)++;
    }

    return 0;
}
/*
   Function Name : compile
Parameters : Written program
Return value(s) : 
Partners : CSLC
Description : This function will compile the written program
*/

int compile(int *instructionCounter, int *operationCode, int  mem[] , int *operand){
    char string[20] = {0};
    /*check format of program reda in*/

    while(fgets(string, 20, stdin)!= NULL){

        if(sscanf(string, "%d %s %d", instructionCounter, string, operand) == 3)
        {

            if(strcmp(string, "READ") == 0)
                *operationCode = 10;
            else if(strcmp(string, "WRIT")== 0)
                *operationCode = 11;
            else if(strcmp(string, "PRNT")==0)
                *operationCode = 12;
            else if(strcmp(string,"LOAD")==0)
                *operationCode = 20;
            else if(strcmp(string,"STOR")==0)
                *operationCode = 21;
            else if(strcmp(string,"SET")==0)
                *operationCode = 22;
 else if(strcmp( string, "ADD")==0)
                *operationCode = 30;
            else if(strcmp(string, "SUB")==0)
                *operationCode = 31;
            else if (strcmp(string, "DIV")==0)
                *operationCode = 32;
            else if(strcmp(string, "MULT")==0)
                *operationCode = 33;
            else if(strcmp(string, "MOD")==0)
                *operationCode = 34;
            else if(strcmp(string, "BRAN")==0)
                *operationCode = 40;
            else if(strcmp(string, "BRNG")==0)
                *operationCode = 41;
            else if(strcmp(string, "BRZR")==0)
                *operationCode = 42;
            else if(strcmp( string, "HALT")==0)
                *operationCode = 99;


            if(*operationCode == 22)
                mem[*instructionCounter]= *operand;
            else
                mem[*instructionCounter] = (((*operationCode)*100)+ (*operand));

        }
        /*        printf("%d, %s, %d\n", *accumulator, string, *operationCode);*/
        /* mem[*instructionCounter] = (((*operationCode)*100)+ (*operand));*/
        /*Checking "compile version"
          printf("%d\n", mem[*instructionCounter]);*/

    }


    return 0;
}


int main(void) {
    int accumulator= 0,
        instructionCounter= 0,
        instructionRegister= 0,
        operationCode= 0,
        operand= 0;
int mem[100]= {0};
/*
    int *aPtr = &accumulator,
        *countPtr = &instructionCounter,
        *regPtr = &instructionRegister,
        *codePtr = &operationCode,
        *opPtr= &operand;
*/
    if(compile(&instructionCounter, &operationCode, mem, &operand) == 0){
        /*printf("We good!");*/

        stdin = fopen("/dev/tty", "r");

        execute(&accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand, mem);


        printf("REGISTERS:\n");
        printf("accumulator:                  +%04d\n",accumulator);
        printf("instructionCounter:              %02d\n",instructionCounter);
        printf("instructionReigster:          +%04d\n",instructionRegister);
        printf("operationCode:                   %02d\n",operationCode);
        printf("operand:                         %02d\n",operand);
        printf("MEMORY:\n");
        printf("       0     1     2     3     4     5     6     7     8     9\n");

        for(operand = 0; operand < 90; operand++){
            if(operand% 10 == 0)
                printf("\n%d  ",operand);


            printf("+%04d ", mem[operand]);

        }

        printf("\n");

    }
    else
        printf("The program was formatting incorrectly");

    return 0;
}
