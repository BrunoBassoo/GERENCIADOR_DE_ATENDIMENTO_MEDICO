#include <stdio.h>
#include <string.h>

// CONTEXTO 
typedef struct Data{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct Registro{
  char nome[50];
  int idade;
  char rg[9];
  Data entrada;
} Registro;

// --- CADASTRO ---

// celula
typedef struct ELista{
  Registro dados;
  struct ELista *proximo;
} ELista;

// lde
typedef struct Lista{
  ELista *inicio;
  int qntd;
} Lista;

// --- Atendimento ---

typedef struct EFila{
  Registro dados;
  struct EFila *proximo;
} EFila;

typedef struct Fila{
  struct EFila *Head;
  EFila Tail;
  int qntd;
} Fila;

// --- Pesquisa ---

typedef struct EABB{
  Registro dados;
  struct EABB *filhoesq;
  struct EABB *filhodir;
} EABB;

typedef struct ABB{
  EABB raiz;
  int qntd;
} ABB;