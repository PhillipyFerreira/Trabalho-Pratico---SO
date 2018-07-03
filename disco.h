#include <stdio.h>
#include <stdlib.h>

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

int createFS(fileSystem**, int);
int formatFS(fileSystem**);
int printFS(fileSystem*);
int loadFS(fileSystem**, FILE*);
int initFS(fileSystem**, FILE*);
int writeFS(fileSystem**, FILE*);

int processFSOps(fileSystem**, FILE*);
int writeFile(fileSystem**, char, int);
int deleteFile(fileSystem**, char);
