#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
#include "imprimir.h"

// ===============================================================================
// CRIAÇÃO DE LISTAS DE PACIENTES E REGISTRO DE PACIENTES
// ===============================================================================

// Funções responsáveis para criação da lista de pacientes e do registro de cada paciente no programa.


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



void inserirLista(Lista *pacientes, Registro *paciente) {
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

void mostrar(Lista *pacientes) {
  if (pacientes->qtd == 0) {
    printf("\nERRO: Nenhum paciente cadastrado.\n\n");
    return;
  }
  
  else{
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

void exibirPacienteInfos(long int rg, Lista *pacientes){
  long int id = ExistePaciente(rg, pacientes);
  int idx = 1;

  if(id != -1){
    CelLista *atual = pacientes->inicio;
    while(idx <= id) {
      atual = atual->proximo;
      idx++;
    }

    printf("\n====================[PACIENTE]====================");

    printf("\n -> Nome: ");
    for(int i = 0; i < atual->paciente.nome[i] != '\0'; i++){
      printf("%c", atual->paciente.nome[i]);
    }

    printf(" -> Idade: %d", atual->paciente.idade);
    printf("\n -> RG: %ld", atual->paciente.rg);

    Data atual_data = atual->paciente.entrada;
    printf("\n -> Data de entrada: %d/%d/%d", atual_data.dia, atual_data.mes, atual_data.ano);

    printf("\n=================================================\n\n");
  }
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
  
  printf("Digite seu RG: ");
  scanf("%ld", &paciente->rg);
  
  long int id = paciente->rg;

  struct tm *data_hora_atual;
  time_t data;
  time(&data);
  struct tm *data_atual = localtime(&data);
  
  paciente->entrada.dia = data_atual->tm_mday;
  paciente->entrada.mes = data_atual->tm_mon+1;
  paciente->entrada.ano = data_atual->tm_year+1900;

  id = ExistePaciente(id, pacientes);

  if(id != -1){
    printf("\nERRO: Paciente ja cadastrado!\n\n");
  }
  else{
    cria_CelLista(paciente);
    inserirLista(pacientes, paciente);
    
    printf("\nPaciente cadastrado!\n\n");
  }

  return paciente;
}

void consultarPaciente(Lista *pacientes){
  if (pacientes->qtd == 0) {
    printf("\nERRO: Nenhum paciente cadastrado.\n\n");
    return;
  }

  else{
    long int rg;
    printf("\nDigite o RG do paciente que você deseja consultar: ");
    scanf("%ld", &rg);
    
    long int id = ExistePaciente(rg, pacientes);
    int idx = 1;
  
    if(id != -1){
      CelLista *atual = pacientes->inicio;
      while(idx <= id) {
        atual = atual->proximo;
        idx++;
      }
      
      exibirPacienteInfos(rg, pacientes);
      
    }
    else{
      printf("\nERRO: Paciente não existe!\n\n");
    }
  }
}

void atualizarPaciente(Lista *pacientes){
  long int rg;
  printf("\nDigite o RG do paciente que você deseja atualizar: ");
  scanf("%ld", &rg);

  long int id = ExistePaciente(rg, pacientes);
  int idx = 1;

  if(id != -1){
    CelLista *atual = pacientes->inicio;
    while(idx <= id) {
      atual = atual->proximo;
      idx++;
    }

    exibirPacienteInfos(rg, pacientes);
    
    int opcao;
    
    imprimirMenuAtualizarDado();
    printf("--> ");
    scanf("%d", &opcao);

    if(opcao == 1){
      limpaBuffer();
      printf("\nDigite o nome atualizado: ");
      fgets(atual->paciente.nome, 50, stdin);
      printf("\nNome atualizada com sucesso!\n\n");
    }

    else if(opcao == 2){
      printf("\nDigite a idade atualizada: ");
      scanf("%d", &atual->paciente.idade);
      printf("\nIdade atualizada com sucesso!\n\n");
    }

    else if(opcao == 3){
      long int existenteRG;
      
      printf("\nDigite o RG atualizado: ");
      scanf("%ld", &existenteRG);
      
      int flag = ExistePaciente(existenteRG, pacientes);

      if(flag == -1){
        atual->paciente.rg = existenteRG;
        printf("\nRG atualizado com sucesso!\n\n");
      }
      else{
        printf("\nRG já existente! Tente novamente.\n\n");
      }
    }

    else if(opcao == 4){
      printf("\n");
      return;
    }
  }

  else{
    printf("\nERRO: Paciente não existe!\n\n");
  }    
}

void removerPaciente(Lista *pacientes) {
  if (pacientes->qtd == 0) {
    printf("\nERRO: Nenhum paciente cadastrado.\n\n");
    return;
  }
    
  else{
    long int rg;
    printf("\nDigite o RG do paciente que você deseja remover: ");
    scanf("%ld", &rg);

    long int id = ExistePaciente(rg, pacientes);

    if(id != -1){
      if (pacientes->qtd == 1) {
        pacientes->inicio = NULL;
        free(pacientes->inicio);
        pacientes->qtd--;
      } 

      else {
        CelLista *atual = pacientes->inicio;
        CelLista *anterior = NULL;

        while (atual != NULL && atual->paciente.rg != rg) { 
          anterior = atual;
          atual = atual->proximo;
        }

        // CASO 2: COMECO 
        if (anterior == NULL && atual != NULL) {
          pacientes->inicio = atual->proximo;
        }
        // CASO 3: FIM 
        if (anterior != NULL && atual == NULL) {
          anterior->proximo = NULL;
        }
        // CASO 4: MEIO 
        if (anterior != NULL && atual != NULL) {
          anterior->proximo = atual->proximo;
        }
        pacientes->qtd--;
        free(atual);
      }
      
      printf("\nPaciente removido com sucesso!\n\n");
    }
      
    else{
      printf("\nERRO: Paciente não existe!\n\n");
    }
  }
}



// ===============================================================================
// MANIPULAÇÃO DOS ARQUIVOS
// ===============================================================================


void SalvarPacientes(Lista *pacientes){
  
  FILE *file = fopen("pacientes.bin", "wb");

  CelLista *atual = pacientes->inicio;
  CelLista *anterior = NULL;

  while (atual != NULL) {
    fwrite(atual->paciente.nome, sizeof(char), 50, file);
    fwrite(&atual->paciente.idade, sizeof(int), 1, file);
    fwrite(&atual->paciente.rg, sizeof(long int), 1, file);
    fwrite(&atual->paciente.entrada, sizeof(Data), 1, file);
    
    anterior = atual;
    atual = atual->proximo;
  }

  printf("\nArquivo com pacientes salvo com sucesso!\n\n");
  
  fclose(file);
}

void CarregarPacientes(Lista *pacientes){

   FILE *file = fopen("pacientes.bin", "rb");

  CelLista *atual = pacientes->inicio;
  CelLista *anterior = NULL;

    if(file != 0){
      while(!feof(file)){
        fread(atual->paciente.nome, sizeof(char), 50, file);
        fread(&atual->paciente.idade, sizeof(int), 1, file);
        fread(&atual->paciente.rg, sizeof(long int), 1, file);
        fread(&atual->paciente.entrada, sizeof(Data), 1, file);

        anterior = atual;
        atual = atual->proximo;
      }

    printf("\nArquivo com pacientes carregado com sucesso!\n\n");

    fclose(file);
  }

  else{
    printf("\nERRO: não foi possível carregar o arquivo.\n");
    printf("\n       '-> arquivo não encontrado.\n\n");
  }
}




// ===============================================================================
// SELEÇÃO DE OPÇÕES PARA CADA MENÚ
// ===============================================================================



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
    consultarPaciente(pacientes);
  }
  else if(opcao == 3){
    mostrar(pacientes);
  }
  else if(opcao == 4){
    atualizarPaciente(pacientes);
  }
  else if(opcao == 5){
    removerPaciente(pacientes);
  }
  else if(opcao == 6){
    printf("\n");
    return;
  }
  else{
    printf("Opção Inválida!");
    return;
  }

}

void AtendimentoOpcoes(Lista *pacientes) { 
  imprimirMenuAtendimento();
  printf("--> ");

  int opcao;

  limpaBuffer();
  scanf("%d", &opcao);

  if(opcao == 1){

  }
  else if(opcao == 2){

  }
  else if(opcao == 3){

  }
  else if(opcao == 4){
    printf("\n");
    return;
  }
  else{
    printf("Opção Inválida!");
    return;
  }
  
}

void PesquisaOpcoes(Lista *pacientes) {
  imprimirMenuPesquisa();
  printf("--> ");

  int opcao;

  limpaBuffer();
  scanf("%d", &opcao);

  if(opcao == 1){

  }
  else if(opcao == 2){

  }
  else if(opcao == 3){

  }
  else if(opcao == 4){

  }
  else if(opcao == 5){
    printf("\n");
    return;
  }
  else{
    printf("Opção Inválida!");
    return;
  }
  
}

void CarregarSalvar(Lista *pacientes) { 
  imprimirMenuCarregar_Salvar();
  printf("--> ");

  int opcao;

  limpaBuffer();
  scanf("%d", &opcao);

  if(opcao == 1){
    CarregarPacientes(pacientes);
  }
  else if(opcao == 2){
    SalvarPacientes(pacientes);
  }
  else if(opcao == 3){
    printf("\n");
    return;
  }
  else{
    printf("Opção Inválida!");
    return;
  }
  
}

void Sobre() {
  imprimirMenuSobre();
}