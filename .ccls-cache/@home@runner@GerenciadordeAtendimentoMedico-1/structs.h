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
  Registro paciente;
  struct CelFila *proximo;
  struct CelFila *anterior;
} CelFila;

typedef struct Fila{
  struct CelFila *head;
  struct CelFila *tail;
  int qtd;
} Fila;

// --- Pesquisa ---

typedef struct CelArvore{
  Registro paciente;
  struct CelArvore *filhoesq;
  struct CelArvore *filhodir;
  struct CelArvore *pai;
} CelArvore;

typedef struct Arvore{
  CelArvore *raiz;
  int qtd;
} Arvore;