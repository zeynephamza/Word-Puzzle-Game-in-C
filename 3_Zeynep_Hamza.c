/*--------------------------------------------------------------------------*/
/* HW03_151044011_Zeynep_Hamza												*/
/*                                                                          */
/* ---------																*/
/* Created on 14/10/2017 by Zeynep Hamza									*/
/*																			*/
/* Description																*/
/* -----------																*/
/*    This program reads the given file and finds location of the 5 strings */
/*    and prints them to the terminal.      								*/
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/* Includes																	*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

/*--------------------------------------------------------------------------*/
/* Defines																	*/
/*--------------------------------------------------------------------------*/
#define MAX_ROW_COUNT 50
#define MAX_LENGTH 100

/*--------------------------------------------------------------------------*/
/* Prototypes																*/
/*--------------------------------------------------------------------------*/
void initialize(char fileArray[MAX_ROW_COUNT][MAX_LENGTH]);
void display(char fileArray[MAX_ROW_COUNT][MAX_LENGTH]);
void readFile (char *filename, char fileArray[MAX_ROW_COUNT][MAX_LENGTH]);
void findHorizontal(char fileArray[MAX_ROW_COUNT][MAX_LENGTH], 
		char *string, int string_length);
void findVertical(char fileArray[MAX_ROW_COUNT][MAX_LENGTH], 
		char *string,int string_length);
		
int main() {

/* Initializes */
    char fileArray[MAX_ROW_COUNT][MAX_LENGTH];
    char *filename = "input.txt";
    char *string1="Xanthos";
    char *string2="Patara";
    char *string3="Myra";
    char *string4="Arycanda";
    char *string5="Phaselis";
    
    int string_length1 = strlen(string1);
    int string_length2 = strlen(string2);
    int string_length3 = strlen(string3);
    int string_length4 = strlen(string4);
    int string_length5 = strlen(string5);

/* Initializing an array for take from file to array */ 
    initialize(fileArray);
    
/* Reads the file to the array */  
    readFile(filename,fileArray);
    //display(fileArray);
    
/* Calling horizontal and vertical functions for every string parameter 
		and their lengths*/
    findHorizontal(fileArray,string1,string_length1);
    findHorizontal(fileArray,string2,string_length2);
    findHorizontal(fileArray,string3,string_length3);
    findHorizontal(fileArray,string4,string_length4);
    findHorizontal(fileArray,string5,string_length5);
    findVertical(fileArray,string1,string_length1);
    findVertical(fileArray,string2,string_length2);
    findVertical(fileArray,string3,string_length3);
    findVertical(fileArray,string4,string_length4);
    findVertical(fileArray,string5,string_length5);
    
    return 0;
    
}

void readFile (char *filename, char fileArray[MAX_ROW_COUNT][MAX_LENGTH]){	

    int i,j;
    char c;
    
    FILE *fp;
     /*  open the file for reading */
    fp=fopen(filename,"r");
    if (fp == NULL){
        printf("Cannot open file \n");
    }
    c = fgetc(fp); /*takes a character from file*/
	while(c!=EOF){ /* while end of the line */
		for(i=0;i<MAX_ROW_COUNT;i++){
			if(c=='\n') /* or end of the line*/
				c = fgetc(fp);
			for(j=0;j<MAX_LENGTH && c!='\n';j++){
				fileArray[i][j]=c; /*assignes the taken character to the array*/
				c = fgetc(fp); /* and takes the next character */
			}
		    
		}
	}
	/* closing the file pointer*/
    fclose(fp);	
}

/* giving first value to array*/
void initialize(char fileArray[MAX_ROW_COUNT][MAX_LENGTH]){

	int i,j;

	for (i=0;i<MAX_ROW_COUNT;i++)
	{
        for(j=0;j<MAX_LENGTH;j++){
            fileArray[i][j]='.';
        }
	}
	
	return;
}

/* For dispalying the filled array for coder */
void display(char fileArray[MAX_ROW_COUNT][MAX_LENGTH]){
	int i,j;
       
	for (i=0;i<MAX_ROW_COUNT;i++)
	{
            for(j=0;j<MAX_LENGTH;j++){
                printf("%c",fileArray[i][j]);
            }
            printf("\n");
	}
        printf("\n");
	return;
}

/* Finds the given word if it horizontal */
void findHorizontal(char fileArray[MAX_ROW_COUNT][MAX_LENGTH], 
		char *string, int string_length){
	
    int i,j,k,flag=0;
    int row=0;
    int column=0;
    
    for (i=0;i<MAX_ROW_COUNT && flag==0;i++)
    {
        for(j=0;j<MAX_LENGTH && flag==0;j++){
        	
        	/* if the word's first character find*/
            if(fileArray[i][j]==string[0]){ 
            	column=j;
            	row=i;
            	flag=1; 
   
                for(k=1;k<string_length;k++){
                	/*returns for column so it is horizontal*/
                    if(fileArray[i][j+k]!=string[k]){ 
                        flag=0; /* if the next word not equal the word's*/     			
            		}
        		
            	}
            	if (flag==1) /* All word's character equal the word in file */ 
					printf("%s (%d,%d) Horizontal\n",string,row+1,column+1);
            }
        }
    }
    
    
        
    return;
}
/* Finds the given word if it vertical */
void findVertical(char fileArray[MAX_ROW_COUNT][MAX_LENGTH], 
		char *string,int string_length){
	
    int i,j,k,flag=0;
    int row=0;
    int column=0;
    
    for (i=0;i<MAX_ROW_COUNT && flag==0;i++)
    {
        for(j=0;j<MAX_LENGTH && flag==0;j++){
        
        	/* if the word's first character find*/
            if(fileArray[i][j]==string[0]){
            	column=j;
            	row=i;
            	flag=1;
   
                for(k=1;k<string_length;k++){
                	/*returns for column so it is horizontal*/
                    if(fileArray[i+k][j]!=string[k]){
                        flag=0;   /* if the next word not equal the word's*/  			
            		}
        		
            	}
            	if (flag==1)/* All word's character equal the word in file */ 
					printf("%s (%d,%d) Vertical\n",string,row+1,column+1);
            }
        }
    }
    return;
}

