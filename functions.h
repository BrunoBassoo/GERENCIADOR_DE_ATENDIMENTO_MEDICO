#include "structs.h"

Registro *pegar_dados(Lista *pacientes);

Lista *cria_Lista();

CelLista *cria_CelLista(Registro paciente);

void inserir_na_lista(Lista *pacientes, Registro paciente);

void remover_da_lista(Lista *pacientes, Registro *paciente);

void mostrar(Lista *pacientes);

void consultarPaciente(long int rg, Lista *pacientes);

void removerPaciente(Lista *pacientes);

void CadastrarOpcoes(Lista *pacientes);

void AtendimentoOpcoes(Lista *pacientes);

void PesquisaOpcoes(Lista *pacientes);

void CarregarSalvar(Lista *pacientes);

void Sobre();

void limpaBuffer();