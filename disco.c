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

int main (void){

	int blocks = 10;
	fileSystem *fs = NULL;
	FILE *fsFile = fopen("files.txt","r");

	initFS(&fs, fsFile);

	printFS(fs);

	processFSOps(&fs, fsFile);
	
	return 0;
}

int createFS(fileSystem **fs, int blocks){
	//printf("CRIANDO FS\n");
	*fs = (fileSystem *) malloc(sizeof(fileSystem));
	(*fs)->blocks = blocks;
	(*fs)->disc = malloc(blocks * sizeof ((*fs)->disc));
	//printf("CRIADO FS\n");
	return 0;
}

int formatFS(fileSystem **fs){
	//printf("FORMATANDO FS\n");
	for(int i = 0; i < (*fs)->blocks; i++)
		(*fs)->disc[i] = '0';
	//printf("FORMATADO FS\n");	
	return 0;	
}

int initFS(fileSystem **fs, FILE* fsFile){
	int blocks = 0;

	if(fscanf(fsFile,"%d\n", &blocks) == EOF){
		printf("ERRO AO LER O NÚMERO TOTAL DE BLOCOS\n");
		return ERROR;
	}

	//printf("BLOCOS: %d\n", blocks);
    
	createFS(fs, blocks);
	//printf("BLOCOS: %d\n", (*fs)->blocks);
	formatFS(fs);

	printFS(*fs);

	loadFS(fs, fsFile);
}

int loadFS(fileSystem **fs, FILE* fsFile){

	int numFiles = 0;

	if(fscanf(fsFile,"%d\n", &numFiles) == EOF){
		printf("ERRO AO LER O NÚMERO TOTAL DE ARQUIVOS\n");
		return ERROR;
	}

	//printf("ARQUIVOS: %d\n", files);
	file *files = malloc(numFiles * sizeof(file) );

	//printf("CARREGANDO...\n");
	for(int i = 0; i < numFiles; i++){
		file *f = &files[i];
		if(fscanf(fsFile,"%c, %d, %d\n", &f->name, &f->seek, &f->blocks) == EOF){
			printf("ERRO AO LER O ARQUIVO %d\n", i+1);
			return ERROR;
		}
		for(int j = 0; j < f->blocks; j++)
			(*fs)->disc[f->seek + j] = f->name;
		
		//printf("%c, %d, %d\n", f->name, f->seek, f->blocks);
	}
	//printf("CARREGADO...\n");

	/*printf("VERIFICANDO...\n");
	for(int i = 0; i < numFiles; i++){
		file *f = &files[i];
		printf("%c, %d, %d\n", f->name, f->seek, f->blocks);
	}
	printf("VERIFICADO...\n");*/

}

int writeFile(fileSystem **fs, char file, int size){

}

int deleteFile(fileSystem **fs, char file){

}

int printFS(fileSystem* fs){
	for(int i = 0; i < fs->blocks; i++)
		printf("%c ", fs->disc[i]);	
	printf("\n");	
	return 0;
}

int processFSOps(fileSystem **fs, FILE* fsFile){

}
