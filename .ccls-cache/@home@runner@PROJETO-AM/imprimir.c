#include <stdio.h>
#include <unistd.h>


// Nesse arquivo, estão armazenadas todas as funções de impressão no console que foram utilizadas. Nenhuma das funções recebe parâmetros ou realizam modificações no sistema, sendo utlizadas apenas para impressão do menu. Foi optado por criar um arquivo apenas para essas funções apenas para não poluir as demais funções e arquivos, já que o número de opções disponíveis são grandes.

void imprimirMenuInicial(){
  sleep(1);
  printf("---------------------------------------------------\n");
  printf("--------- Bem Vindo ao Atendimento Rápido ---------\n");
  printf("---------------------------------------------------\n\n");

  sleep(1);
  printf("Qual opção você deseja realizar?\n\n");
  printf("[1]. Cadastrar\n");
  sleep(1);
  printf("[2]. Atendimento\n");
  sleep(1);
  printf("[3]. Pesquisa\n");
  sleep(1);
  printf("[4]. Carregar / Salvar\n");
  sleep(1);
  printf("[5]. Sobre\n");
  sleep(1);
  printf("[6]. Sair\n\n");
  sleep(1);
}

void imprimirMenuCadastrar(){

  sleep(1);
  printf("\n--------------> PAGINA DE CADASTRO <---------------\n\n"); 
  sleep(1);
  
  printf("Qual operação deseja fazer?\n\n");

  printf("1. Cadastrar novo paciente\n");
  sleep(1);
  printf("2. Consultar paciente cadastrado\n");
  sleep(1);
  printf("3. Mostrar lista completa\n");
  sleep(1);
  printf("4. Atualizar dados de paciente\n");
  sleep(1);
  printf("5. Voltar\n\n");
  sleep(1);
}

void imprimirMenuAtendimento(){

  sleep(1);
  printf("\n------------> PAGINA DE ATENDIMENTO <-------------\n\n"); 
  sleep(1);

  printf("Qual operação deseja fazer?\n\n");

  printf("1. Enfileirar paciente\n");
  sleep(1);
  printf("2. Desenfileirar paciente\n");
  sleep(1);
  printf("3. Mostrar fila.\n");
  sleep(1);
  printf("4. Voltar.\n");
  sleep(1);
}

void imprimirMenuPesquisa(){

  sleep(1);
  printf("\n-------------> PAGINA DE PESQUISA <--------------\n\n"); 
  sleep(1);

  printf("Qual operação deseja fazer?\n\n");

  printf("1. Mostrar registros ordenados por dia de registro\n");
  sleep(1);
  printf("2. Mostrar registros ordenados por mês de registro\n");
  sleep(1);
  printf("3. Mostrar registros ordenados por ano de registro\n");
  sleep(1);
  printf("4. Mostrar registros ordenados por idade de registro\n");
  sleep(1);
  printf("5. Voltar\n\n");
  sleep(1);
}

void imprimirMenuCarregar_Salvar(){

  sleep(1);
  printf("\n--------> PAGINA DE CARREGAR E SALVAR <---------\n\n"); 
  sleep(1);

  printf("Qual operação deseja fazer?\n\n");

  printf("1. Ler um arquivo com os dados dos pacientes e carregar a lista\n");
  sleep(1);
  printf("2. Salvar um arquivo com os dados dos pacientes\n");
  sleep(1);
  printf("3. Voltar\n\n");
  sleep(1);
}

void imprimirMenuSobre(){
  
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

  sleep(2);

  printf("------------------ 2 ------------------\n");
  printf("Nome: Gabriela Molina Ciocci\n");
  printf("Ciclo: 4° semestre\n");
  printf("Curso: Ciência da Computação - FEI\n");
  printf("Disciplina: CC4652 - Estrutura de Dados\n");
  printf("Data: 20/05/2024\n");
  printf("---------------------------------------\n\n\n");

  sleep(2);
}
