#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "imprimir.h"
#include "functions.h"

// Projeto: Gerenciador de Atendimento Médico em C
// Feito por: Bruno Arthur Basso Silva 
//            Gabriela Molina Ciocci
// RA:        22.123.067-5
//            22.222.032-9
// Disciplina: CC4652 - Estrutura de Dados
// Professor: Luciano Rossi
// Ciclo: 4° Semestre. 
// Curso: Ciência da Computação
// Universidade: Centro Universitário FEI

int main(void) {
  int opcao = -1;
  Lista *pacientes = cria_Lista();
  imprimirMenuInicial();
  
  while (opcao != 6){
    imprimirMenuOpcoes();
    scanf("%d", &opcao);

    switch(opcao){ // faz um escolha dentro da opcao colocada
    case 1:
      CadastrarOpcoes(pacientes);
      break;
      
    case 2:
      AtendimentoOpcoes(pacientes);
      break;
      
    case 3:
      PesquisaOpcoes(pacientes);
      break;
      
    case 4:
      CarregarSalvar(pacientes);
      break;
      
    case 5:
      Sobre();
      break;
      
    case 6:
      printf("\nObrigado(a), volte sempre!");
      break;
      
    default:
      printf("\nOpcao invalida!\n\n");
    }
  }

  return 0;
}