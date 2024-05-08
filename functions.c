#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "structs.h"


void limpaBuffer() {
  char a;
  do {
    a = getchar();
  } while (a != '\n' && a != EOF);
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Cadastrar novo paciente em uma lista dinâmica encadeada, mantendo a
// ordem de registro (inserção no início);

// --------------------------- CADASTRAR ----------------------------- //

Registro *pegar_dados(){
  limpaBuffer();

  Registro *paciente = malloc(sizeof(Registro));
  printf("\n------------ DADOS ------------\n\n");
  printf("Digite seu nome: ");
  fgets(paciente->nome, 50, stdin);

  printf("Digite sua idade: ");
  scanf("%d", &paciente->idade);

  limpaBuffer();
  
  printf("Digite seu rg:");
  fgets(paciente->rg, 9, stdin);

  printf("Digite a data de hoje!\n");
  printf("Dia: ");
  scanf("%d", &paciente->entrada.dia);
  
  printf("\nMes: ");
  scanf("%d", &paciente->entrada.mes);
  
  printf("\nAno: ");
  scanf("%d", &paciente->entrada.ano);

  return paciente;
}

Lista *cria_Lista() {
  Lista *lista = malloc(sizeof(Lista));

  lista->inicio = (ELista *)NULL;
  lista->qntd = 0;

  return lista;
}

ELista *cria_EL(Registro registro){
  ELista *celula = malloc(sizeof(ELista));

  celula->dados = registro;
  celula->proximo = NULL;

  return celula;
}

void inserir_na_lista(Lista *lista, Registro registro) {
  ELista *novo = cria_EL(registro);
  
  // CASO 1: INICIO 
  if (lista->qntd == 0) {
    lista->inicio = (ELista *) novo;
    lista->qntd++;
  } else {
    ELista *atual = lista->inicio;
    ELista *anterior = NULL;

    while (atual != NULL && atual->dados.nome < registro.nome) {
      anterior = atual;
      atual = atual->proximo;
    }
    // CASO 2: COMECO 
    if (anterior == NULL && atual != NULL) {
      novo->proximo = atual;
      lista->inicio = novo;
      lista->qntd++;
    }
    // CASO 3: FIM 
    if (anterior != NULL && atual == NULL) {
      anterior->proximo = novo;
      lista->qntd++;
    }
    // CASO 4: MEIO 
    if (anterior != NULL && atual != NULL) {
      anterior->proximo = novo;
      novo->proximo = atual;
      lista->qntd++;
    }
  }
}

void remover_da_lista(Lista *lista, Registro registro) {
  if (lista->qntd == 0) {
    printf("Erro!\n");
    return;
  }

  if (lista->qntd == 1) {
    lista->inicio = NULL;
    free(lista->inicio);
    lista->qntd--;
  } else {
    ELista *atual = lista->inicio;
    ELista *anterior = NULL;

    while (atual != NULL && atual->dados.nome != registro.nome) { 
      anterior = atual;
      atual = atual->proximo;
    }

    // CASO 2: COMECO 
    if (anterior == NULL && atual != NULL) {
      lista->inicio = atual->proximo;
    }
    // CASO 3: FIM 
    if (anterior != NULL && atual == NULL) {
      anterior->proximo = NULL;
    }
    // CASO 4: MEIO 
    if (anterior != NULL && atual != NULL) {
      anterior->proximo = atual->proximo;
    }
    lista->qntd--;
    free(atual);
  }
}

// MOSTRAR TODA A LISTA //
void mostrar(Lista *lista) {
  ELista *atual = lista->inicio;
  while (atual != NULL) {
    printf("%d ", atual->dados.nome[50]);
    atual = atual->proximo;
  }
  printf("\n");
}


void cadastrar() { 
  limpaBuffer();
  Lista *lista_criada = cria_Lista();
  int opcao;
  imprimirMenuCadastrar();
  printf("-->");
  scanf("%d", &opcao);

  if(opcao == 1){
    Registro *paciente = pegar_dados();
    cria_EL(*paciente);

    inserir_na_lista(lista_criada, *paciente);
    // // inserindo //
    // for (int i = 0; i < 2; i++) {
    //   inserir_na_lista(lista_criada, valores[i]);
    //   mostrar(lista_criada);
    // }
    printf("\nPaciente foi inserido na lista, obrigado!\n");
  }
  else if(opcao == 2){
    
  }
  else if(opcao == 3){
    
  }
  else if(opcao == 4){

  }
  else if(opcao == 5){

  }
  else if(opcao == 6){

  }
  else{
    printf("Opção Inválida!");
    return;
  }

}

// ------------------------------------------------------------------- //

void atendimento() { 

  imprimirMenuAtendimento();
  
}

void pesquisa() {

  imprimirMenuPesquisa();
  
}

void carregar_salvar() { 
  
  imprimirMenuCarregar_Salvar();
  
}

void sobre() {
  imprimirMenuSobre();
}