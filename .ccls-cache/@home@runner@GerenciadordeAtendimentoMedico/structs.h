#include <stdio.h>
#include <string.h>
#define len 10

// CONTEXTO 
typedef struct Data{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct Registro{
  char nome[50];
  int idade;
  long int rg;
  Data entrada;
} Registro;

// --- CADASTRO ---

// celula
typedef struct CelLista{
  Registro paciente;
  struct CelLista *proximo;
} CelLista;

// lde
typedef struct Lista{
  CelLista *inicio;
  int qtd;
} Lista;

// --- Atendimento ---

typedef struct EFila{
  Registro dados;
  struct EFila *proximo;
} EFila;

typedef struct Fila{
  struct EFila *Head;
  EFila Tail;
  int qtd;
} Fila;

// --- Pesquisa ---

typedef struct EABB{
  Registro dados;
  struct EABB *filhoesq;
  struct EABB *filhodir;
} EABB;

typedef struct ABB{
  EABB raiz;
  int qtd;
} ABB;