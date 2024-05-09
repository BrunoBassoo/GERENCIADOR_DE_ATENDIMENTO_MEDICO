#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "structs.h"
#include "imprimir.h"

// Variáveis criadas para poder limitar o tamanho máximo de pacientes que podem ser criados.

int maxPacientes = 10;

// Varíáveis que guardam a quantidade de pacientes já existentes. o i antes do nome significa "index"

int iPacientes = 0;

// Array de structs criado para armazenas todos os pacientes. Isso facilita muito para trabalhar com os dados que temos e iremos trabalhar, pois estando em listas, podemos percorrê-las para encontrar o que precisamos, modificar dentro das listas e depois reescrever por cima dos arquivos, sem a necessidade de trabalhar diretamente com os arquivos.


Lista *cria_Lista() {
  Lista *lista = malloc(sizeof(Lista));
  lista->inicio = NULL;
  lista->qtd = 0;
  
  return lista;
}

CelLista *cria_CelLista(Registro *paciente){
  CelLista *celula = malloc(sizeof(CelLista));
  celula->paciente = *paciente;
  celula->proximo = NULL;

  return celula;
}

// ===============================================================================
// FUNÇÕES PRINCIPAIS PARA O FUNCIONAMENTO DO CÓDIGO
// ===============================================================================


// Essa função é muito importante para a funcionalidade do nosso programa, pois muitas vezes, o programa acaba ficando com resíduos na memória, que podem acarretar em problemas para captar alguma informação de tipo "char", já que esses resíduos podem acabar se tornando a informação que o usuário deve fornecer. A função é responsável por remover todo tipo de resíduo da memória e bloquear a entrada dos mesmos no código, fazendo com que a única entrada possível seja a que o usuário entregar.

void limpaBuffer() {
  char a;
  do {
    a = getchar();
  } while (a != '\n' && a != EOF);
}

// ===============================================================================
// MANIPULAÇÃO DE LISTA
// ===============================================================================


void inserir_na_lista(Lista *pacientes, Registro *paciente) {
  CelLista *novo = cria_CelLista(paciente);

  // CASO 1: INICIO 
  if (pacientes->qtd == 0) {
      pacientes->inicio = novo;
      pacientes->qtd++;
  } 
  else {
    CelLista *atual = pacientes->inicio;
    CelLista *anterior = NULL;

    while (atual != NULL) {
      anterior = atual;
      atual = atual->proximo;
    }
    // CASO 2: COMECO 
    if (anterior == NULL && atual != NULL) {
      novo->proximo = atual;
      pacientes->inicio = novo;
      pacientes->qtd++;
    }
    // CASO 3: FIM 
    if (anterior != NULL && atual == NULL) {
      anterior->proximo = novo;
      pacientes->qtd++;
    }
    // CASO 4: MEIO 
    if (anterior != NULL && atual != NULL) {
      anterior->proximo = novo;
      novo->proximo = atual;
      pacientes->qtd++;
    }
  }
}



void remover_da_lista(Lista *lista, Registro *paciente) {
  if (lista->qtd == 0) {
    printf("Erro!\n");
    return;
  }

  if (lista->qtd == 1) {
    lista->inicio = NULL;
    free(lista->inicio);
    lista->qtd--;
  } 
  else {
    CelLista *atual = lista->inicio;
    CelLista *anterior = NULL;

    while (atual != NULL && atual->paciente.nome != paciente->nome) { 
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
    lista->qtd--;
    free(atual);
  }
}

// MOSTRAR TODA A LISTA //
void mostrar(Lista *pacientes) {
  CelLista *atual = pacientes->inicio;
  int idx = 1;
  
  while (atual != NULL) {
    printf("\n==================[PACIENTE %d]===================", idx);

    printf("\n -> Nome: ");
    for(int i = 0; i < atual->paciente.nome[i] != '\0'; i++){
      printf("%c", atual->paciente.nome[i]);
    }
    
    printf(" -> Idade: %d", atual->paciente.idade);
    printf("\n -> RG: %ld", atual->paciente.rg);

    Data atual_data = atual->paciente.entrada;
    printf("\n -> Data de entrada: %d/%d/%d", atual_data.dia, atual_data.mes, atual_data.ano);
    
    printf("\n=================================================\n");
    atual = atual->proximo;
    idx++;
  }
  printf("\n");
}

// ===============================================================================
// MANIPULAÇÃO DE PACIENTE
// ===============================================================================

// Aqui temos um passo importante para o sistema, pois, se já existe algum paciente cadastrado com esse RG, então o novo paciente não poderá ser cadastrado.

int ExistePaciente(long int rg, Lista *pacientes) {
  int idx = 0;
  CelLista *atual = pacientes->inicio;

  while(atual != NULL) {
    if(atual->paciente.rg == rg){
      return idx;
    }
    else{
      idx++;
      atual = atual->proximo;
    }
  }
  
  return -1;
}

// Caso a opção desejada seja a de cadastrar, nós criamos um paciente através de struct e malloc e pedimos as informações necessárias para criação do mesmo.

Registro *pegar_dados(Lista *pacientes){
  limpaBuffer();

  Registro *paciente = malloc(sizeof(Registro));
  printf("\n------------ DADOS ------------\n\n");
  printf("Digite seu nome: ");
  fgets(paciente->nome, 50, stdin);

  printf("Digite sua idade: ");
  scanf("%d", &paciente->idade);
  
  printf("Digite seu rg: ");
  scanf("%ld", &paciente->rg);
  
  long int id = paciente->rg;

  printf("Digite a data de hoje!\n");
  printf("Dia: ");
  scanf("%d", &paciente->entrada.dia);
  
  printf("Mes: ");
  scanf("%d", &paciente->entrada.mes);
  
  printf("Ano: ");
  scanf("%d", &paciente->entrada.ano);


  id = ExistePaciente(id, pacientes);

  if(id != -1){
    printf("\nERRO: Paciente ja cadastrado!\n\n");
  }
  else{
    cria_CelLista(paciente);
    inserir_na_lista(pacientes, paciente);
    
    printf("\nPaciente cadastrado!\n\n");
  }

  return paciente;
}






void CadastrarOpcoes(Lista *pacientes) {   
  imprimirMenuCadastrar();
  printf("--> ");

  int opcao;
  
  limpaBuffer();
  scanf("%d", &opcao);

  if(opcao == 1){
    Registro *paciente = pegar_dados(pacientes);
  }
  else if(opcao == 2){
    
  }
  else if(opcao == 3){
    mostrar(pacientes);
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