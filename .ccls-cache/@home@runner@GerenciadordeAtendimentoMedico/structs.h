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

typedef struct CelFila{
  Registro dados;
  struct CelFila *proximo;
} CelFila;

typedef struct Fila{
  struct CelFila *Head;
  CelFila Tail;
  int qtd;
} Fila;

// --- Pesquisa ---

typedef struct CelABB{
  Registro dados;
  struct CelABB *filhoesq;
  struct CelABB *filhodir;
} CelABB;

typedef struct ABB{
  CelABB raiz;
  int qtd;
} ABB;