#include "functions.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
  int opcao;

  do {
    //sleep(1);
    printf("---------------------------------------------------\n");
    printf("--------- Bem Vindo ao Atendimento Rápido ---------\n");
    printf("---------------------------------------------------\n\n");
    
    // sleep(1);
    printf("Qual opção você deseja realizar?\n\n");
    // sleep(1);
    printf("[1]. Cadastrar\n");
    // sleep(1);
    printf("[2]. Atendimento\n");
    // sleep(1);
    printf("[3]. Pesquisa\n");
    // sleep(1);
    printf("[4]. Carregar / Salvar\n");
    // sleep(1);
    printf("[5]. Sobre\n");
    // sleep(1);
    printf("[6]. Sair\n\n");
    // sleep(1);

    
    printf("-->");
    scanf("%d", &opcao);

    switch (opcao) { // faz um escolha dentro da opcao colocada
    case 1:
      cadastrar();
      break;
    case 2:
      atendimento();
      break;
    case 3:
      pesquisa();
      break;
    case 4:
      carregar_salvar();
      break;
    case 5:
      sobre();
      break;

    case 6:
      printf("Saindo...\n");
      sleep(1);
      printf("Ate logo...\n");
      sleep(1);
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  } while (opcao != 6);

  return 0;
}