#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

#define ERROR        -1

typedef struct file{
	char name;
	int seek;
	int blocks;
} file;

typedef struct fileSystem{
	int blocks;
	char *disc;
	int ownerPID[1000];
} fileSystem;

typedef struct fsSC{
	int pid;
	int op;
	char name;
	int blocks;
} fsSC;

typedef struct fsevent{
    int code;
	int seek;
	int blocks;
} fsevent;

int createFS(fileSystem**, int);
int formatFS(fileSystem**);
int printFS(fileSystem*);
int loadFS(fileSystem**, FILE*);
int initFS(fileSystem**, FILE*);
int writeFS(fileSystem**, FILE*);

#define CREATE_OP 0
#define DELETE_OP 1

#define FILE_CREATED 1
#define OUT_OF_SPACE -10

int processFSSystemCalls(int*, fileSystem**, FILE*);
int deleteAllowed(fileSystem*, int*, int, char);
fsevent createFile(fileSystem**, int, char, int);
int writeFile(fileSystem**, int, char, int, int);
int deleteFile(fileSystem**, char);

int inicializaFileSystem (int*, const char*);