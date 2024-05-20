#include <stdio.h>
#include <unistd.h>

// Nesse arquivo, estão armazenadas todas as funções de impressão no console que
// foram utilizadas. Nenhuma das funções recebe parâmetros ou realizam
// modificações no sistema, sendo utlizadas apenas para impressão do menu. Foi
// optado por criar um arquivo apenas para essas funções apenas para não poluir
// as demais funções e arquivos, já que o número de opções disponíveis são
// grandes.

void imprimirMenuInicial() {
  printf("|===================================================|\n");
  printf("|         Bem Vindo ao Atendimento Rápido           |\n");
  printf("|===================================================|\n\n");
}

void imprimirMenuOpcoes() {
  printf("Qual opção você deseja realizar?\n\n");
  printf("[1] - Cadastrar\n");
  printf("[2] - Atendimento\n");
  printf("[3] - Pesquisa\n");
  printf("[4] - Carregar / Salvar\n");
  printf("[5] - Sobre\n");
  printf("[6] - Sair\n\n");
  printf("--> ");
}

void imprimirMenuCadastrar() {
  printf("\n--------------> PAGINA DE CADASTRO <---------------\n\n");
  printf("Qual operação deseja fazer?\n\n");
  printf("[1] - Cadastrar novo paciente\n");
  printf("[2] - Consultar paciente cadastrado\n");
  printf("[3] - Mostrar lista completa\n");
  printf("[4] - Atualizar dados de paciente\n");
  printf("[5] - Remover paciente\n");
  printf("[6] - Voltar\n\n");
}

void imprimirMenuAtendimento() {
  printf("\n------------> PAGINA DE ATENDIMENTO <-------------\n\n");
  printf("Qual operação deseja fazer?\n\n");
  printf("[1] - Enfileirar paciente\n");
  printf("[2] - Desenfileirar paciente\n");
  printf("[3] - Mostrar fila.\n");
  printf("[4] - Voltar.\n\n");
}

void imprimirMenuPesquisa() {
  printf("\n-------------> PAGINA DE PESQUISA <--------------\n\n");
  printf("Qual operação deseja fazer?\n\n");
  printf("[1] - Mostrar registros ordenados por ano de registro\n");
  printf("[2] - Mostrar registros ordenados por mês de registro\n");
  printf("[3] - Mostrar registros ordenados por dia de registro\n");
  printf("[4] - Mostrar registros ordenados por idade de registro\n");
  printf("[5] - Voltar\n\n");
}

void imprimirMenuCarregar_Salvar() {
  printf("\n--------> PAGINA DE CARREGAR E SALVAR <---------\n\n");
  printf("Qual operação deseja fazer?\n\n");
  printf("[1] - Ler um arquivo com os dados dos pacientes e carregar a lista\n");
  printf("[2] - Salvar um arquivo com os dados dos pacientes\n");
  printf("[3] - Voltar\n\n");
}

void imprimirMenuSobre() {
  printf("\n-----------> DADOS DOS DESENVOLVEDORES <-----------\n\n");
  printf("|=======================[1]=======================|\n");
  printf("| Nome: Bruno Arthur Basso Silva                  |\n");
  printf("| Ciclo: 4° semestre                              |\n");
  printf("| Curso: Ciência da Computação - FEI              |\n");
  printf("| Disciplina: CC4652 - Estrutura de Dados         |\n");
  printf("| Data: 20/05/2024                                |\n");
  printf("|=================================================|\n\n");
  printf("|=======================[2]=======================|\n");
  printf("| Nome: Gabriela Molina Ciocci                    |\n");
  printf("| Ciclo: 4° semestre                              |\n");
  printf("| Curso: Ciência da Computação - FEI              |\n");
  printf("| Disciplina: CC4652 - Estrutura de Dados         |\n");
  printf("| Data: 20/05/2024                                |\n");
  printf("|=================================================|\n\n");
}

void imprimirMenuAtualizarDado(){
  printf("Qual informação você deseja atualizar?\n\n");
  printf("[1] - Nome\n");
  printf("[2] - Idade\n");
  printf("[3] - RG\n");
  printf("[4] - Voltar\n\n");
  printf("Obs: a data de entrada não pode ser alterada!\n\n");
}