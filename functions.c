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


void cadastrar() { 
  limpaBuffer();
  Lista *lista = cria_Lista();
  int opcao;
  //sleep(1);
  printf("\n--------------> PAGINA DE CADASTRO <---------------\n\n"); 

  // sleep(1);
  printf("Qual operação deseja fazer?\n\n");
  // sleep(1);
  printf("1. Cadastrar novo paciente\n");
  // sleep(1);
  printf("2. Consultar paciente cadastrado\n");
  // sleep(1);
  printf("3. Mostrar lista completa\n");
  // sleep(1);
  printf("4. Atualizar dados de paciente\n");
  // sleep(1);
  printf("5. Voltar\n\n");
  // sleep(1);
  printf("-->");
  scanf("%d", &opcao);

  if(opcao == 1){
    Registro *paciente = pegar_dados();
    cria_EL(*paciente);

    inserir_na_lista(lista, *paciente);
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

void atendimento() { printf("Atendimento feito!\n"); }

void pesquisa() { printf("Pesquisa feito!\n"); }

void carregar_salvar() { printf("Carregar e Salvar feito!\n"); }

void sobre() {
  sleep(1);
  printf("\n------------ DADOS DOS DESENVOLVEDORES ------------\n\n");
  sleep(1);
  printf("------------------ 1 ------------------\n");
  printf("Nome: Bruno Arthur Basso Silva\n");
  printf("Ciclo: 4° semestre\n");
  printf("Curso: Ciência da Computação - FEI\n");
  printf("Disciplina: CC4652 - Estrutura de Dados\n");
  printf("Data: 20/05/2024\n");
  printf("---------------------------------------\n\n");

  sleep(3);

  printf("------------------ 2 ------------------\n");
  printf("Nome: Gabriela Molina Ciocci\n");
  printf("Ciclo: 4° semestre\n");
  printf("Curso: Ciência da Computação - FEI\n");
  printf("Disciplina: CC4652 - Estrutura de Dados\n");
  printf("Data: 20/05/2024\n");
  printf("---------------------------------------\n\n\n");

  sleep(3);
}