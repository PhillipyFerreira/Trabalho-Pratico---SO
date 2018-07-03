#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

#define ERROR        -1

typedef struct fileSystem{
	int blocks;
	char *disc;
} fileSystem;

typedef struct file{
	char name;
	int seek;
	int blocks;
} file;

typedef struct fsSC{
	int pid;
	int op;
	char name;
	int blocks;
} fsSC;

int createFS(fileSystem**, int);
int formatFS(fileSystem**);
int printFS(fileSystem*);
int loadFS(fileSystem**, FILE*);
int initFS(fileSystem**, FILE*);
int writeFS(fileSystem**, FILE*);

#define CREATE_OP 0
#define DELETE_OP 1

int processFSSystemCalls(tipoProcesso*, fileSystem**, FILE*);
int deleteAllowed(tipoProcesso*, char);
int createFile(fileSystem**, char, int);
int deleteFile(fileSystem**, char);
