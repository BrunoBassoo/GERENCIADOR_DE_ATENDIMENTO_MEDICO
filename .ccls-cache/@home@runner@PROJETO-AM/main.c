#include "functions.h"
#include <stdio.h>
#include <unistd.h>
#include "imprimir.c"

int main(void) {
  int opcao;

  do {

    imprimirMenuInicial();
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