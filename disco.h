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

int processFSSystemCalls(tipoProcesso*, fileSystem**, FILE*);
int deleteAllowed(tipoProcesso*, char);
fsevent createFile(fileSystem**, char, int);
int writeFile(fileSystem**, char, int, int);
int deleteFile(fileSystem**, char);

int inicializaFileSystem (tipoProcesso*, const char*);