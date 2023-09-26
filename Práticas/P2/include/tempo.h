//---------------------------------------------------------------------
// Arquivo	: time.h
// Conteudo	: implementacao do .h do arquivo tempo.c
// Autor	: Raquel Rosa (raquelgr@ufmg.br)
// Historico : 02/09/2023 - arquivo criado
//---------------------------------------------------

#ifndef TEMPOH
#define TEMPOH

#include <sys/resource.h>
#include <time.h>
#include <inttypes.h>

#define MILISECONDS_OPTION 0
#define MICROSECONDS_OPTION 1
#define NANOSECONDS_OPTION 2

int64_t getUnixTimestamp(int option);

float difUserTime(struct rusage *start, struct rusage *end); 
float difSystemTime(struct rusage *start, struct rusage *end); 

#endif