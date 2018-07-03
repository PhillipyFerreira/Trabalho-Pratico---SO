#include <stdio.h>
#include <stdlib.h>
#include "disco.h"

int main (void){

	int blocks = 10;
	fileSystem *fs = NULL;
	FILE *fsFile = fopen("files.txt","r");

	initFS(&fs, fsFile);

	printFS(fs);

	processFSSystemCalls(NULL, &fs, fsFile);

	printf("\nMapa de ocupação do disco:\n\n");
	printFS(fs);
	
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

	//printFS(*fs);

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

int printFS(fileSystem* fs){
	for(int i = 0; i < fs->blocks; i++)
		printf("%c ", fs->disc[i]);	
	printf("\n");	
	return 0;
}

int processFSSystemCalls(tipoProcesso* processes, fileSystem **fs, FILE* fsFile){
	int allowed, scId = 0;
	fsSC *sc = malloc(sizeof(fsSC));
	while(fscanf(fsFile,"%d, %d, %c, %d\n", &sc->pid, &sc->op, &sc->name, &sc->blocks) != EOF){
		scId++;
		switch(sc->op){
			case CREATE_OP:
				createFile(fs, sc->name, sc->blocks);
				break;
			case DELETE_OP:
				allowed = deleteAllowed(processes, sc->name);
				if(allowed == ERROR){
					printf("OPERAÇÃO VERIFICAR A PERMISSÃO");
					return -1;
				}
				if(allowed == 1){
					deleteFile(fs, sc->name);
				}else{
					printf("Operação %d => Falha\nO processo '%d' não tem permissão pra apagar o arquivo %c.\n", scId, sc->pid, sc->name);
				}
				break;
			default:
				printf("OPERAÇÃO INVÁLIDA");		
		}
		//printf("%d, %d, %c, %d\n", sc->pid, sc->op, sc->name, sc->blocks);
	}
}

int createFile(fileSystem **fs, char file, int size){

}

int deleteAllowed(tipoProcesso* processes, char file){
	return 1;
}

int deleteFile(fileSystem **fs, char file){
	bool find;
	for(int i = 0; i < (*fs)->blocks; i++){
		if((*fs)->disc[i] == file){
			find = true;
			(*fs)->disc[i] = '0';
			continue;
		}
		if(find)
			break;
	}	
}
