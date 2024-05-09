#include "structs.h"

// NOMEANDO AS FUNÇÕES
// IMPORTAR OS STRUCTS PARA AS FUNCOES!

// funcao para pegar dados
Registro *pegar_dados();

// funcoes para o cadastrar
Lista *cria_Lista();

CelLista *cria_CelLista(Registro registro);

void inserir_na_lista(Lista *lista, Registro registro);

void remover_da_lista(Lista *lista, Registro registro);

void CadastrarOpcoes();

// funções para o atendimento
void atendimento();


// funções para o pesquisa
void pesquisa();

// funções para o carregar_salvar
void carregar_salvar();


void sobre();

// Limpando para tirar o debugg
void limpaBuffer();