#include "structs.h"

Registro *pegar_dados(Lista *pacientes);

Lista *cria_Lista();

CelLista *cria_CelLista(Registro paciente);

CelArvore *cria_CelArvore(Registro *paciente);

Arvore *cria_Arvore();

void mostrarFila(Fila *atendimento);

Fila *cria_Fila();

CelFila *cria_CelFila(Registro *paciente);

void inserirLista(Lista *pacientes, Registro paciente);

void removerLista(Lista *pacientes, Registro *paciente);

void mostrarLista(Lista *pacientes);

void consultarPaciente(long int rg, Lista *pacientes);

void removerPaciente(Lista *pacientes);

void CadastrarOpcoes(Lista *pacientes);

void AtendimentoOpcoes(Lista *pacientes, Fila *atendimento);

void PesquisaOpcoes(Lista *pacientes);

void CarregarSalvar(Lista *pacientes);

void inserirArvore(Arvore *pesquisa, Registro *paciente, int type);

void Sobre();

void limpaBuffer();