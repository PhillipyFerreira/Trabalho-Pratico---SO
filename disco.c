#include <stdio.h>
#include <stdlib.h>
#include "disco.h"
#include "filaProcessos.h"

int inicializaFileSystem (int* processes, const char* fsFileName){

	fileSystem *fs = NULL;
	FILE *fsFile = fopen(fsFileName,"r");

	initFS(&fs, fsFile);

	//printFS(fs);

	printf("\nSistema de arquivos =>\n");
	processFSSystemCalls(processes, &fs, fsFile);

	printf("\nMapa de ocupação do disco:\n\n");
	printFS(fs);
	printf("\n");

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

	return 0;
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
		writeFile(fs, f->name, f->seek, f->blocks);
	}

    return  0;
}

int printFS(fileSystem* fs){
	for(int i = 0; i < fs->blocks; i++)
		printf("%c ", fs->disc[i]);
	printf("\n");
	return 0;
}

int processFSSystemCalls(int* processes, fileSystem **fs, FILE* fsFile){
	int allowed, scId = 0;
	fsevent e;
	fsSC *sc = malloc(sizeof(fsSC));
	while(fscanf(fsFile,"%d, %d, %c, %d\n", &sc->pid, &sc->op, &sc->name, &sc->blocks) != EOF){
		scId++;
		if(processes[sc->pid] != -1)
			switch(sc->op){
				case CREATE_OP:
					e = createFile(fs, sc->name, sc->blocks);
					switch(e.code){
						case FILE_CREATED:
							printf("Operação %d => Sucesso\nO processo '%d' criou o arquivo %c. (blocos %d a %d)\n", scId, sc->pid, sc->name, e.seek, (e.seek + e.blocks - 1));
							break;
						case OUT_OF_SPACE:
							printf("Operação %d => Falha\nO processo '%d' não criar o arquivo %c (falta de espaço)\n", scId, sc->pid, sc->name);
							break;
						default:
							printf("NÃO ESPERADO");
					}
					break;
				case DELETE_OP:
					allowed = deleteAllowed(fs, processes, sc->pid, sc->name);
					if(allowed == ERROR){
						printf("OPERAÇÃO VERIFICAR A PERMISSÃO");
						return -1;
					}
					if(allowed == 1){
						deleteFile(fs, sc->name);
						printf("Operação %d => Sucesso\nO processo '%d' deletou o arquivo %c.\n", scId, sc->pid, sc->name);
					}else{
						printf("Operação %d => Falha\nO processo '%d' não tem permissão pra apagar o arquivo %c.\n", scId, sc->pid, sc->name);
					}
					break;
				default:
					printf("OPERAÇÃO INVÁLIDA");
			}
		else{
			printf("Operação %d => Falha\nNão existe o processo %d.\n", scId, sc->pid, sc->name);
		}	
		printf("\n");
	}
	return 0;
}

fsevent createFile(fileSystem **fs, char file, int blocks){
	bool find = false;
	int initFree = 0;
	int free = 0;
	fsevent *event = malloc(sizeof(fsevent));

	for(int i = 0; i < (*fs)->blocks; i++){
		if((*fs)->disc[i] == '0'){
			free++;
			if(!find){
				find = true;
				initFree = i;
			}
			if(free == blocks){
				writeFile(fs, file, initFree, blocks);
				event->code = FILE_CREATED;
				event->seek = initFree;
				event->blocks = blocks;
				break;
			}
		}else{
			find = false;
			free = 0;
		}
	}

	if(event->code != FILE_CREATED){
		event->code = OUT_OF_SPACE;
	}

	return *event;
}

int writeFile(fileSystem **fs, char file, int seek, int blocks){
	for(int j = 0; j < blocks; j++)
			(*fs)->disc[seek + j] = file;
	return 0;
}

int deleteAllowed(fileSystem *fs, int* processes, int PID, char file){
	return processes[PID] == FILA_TEMPO_REAL ? 1 : 0;
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
	return 0;
}
