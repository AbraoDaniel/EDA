#define MAX_VERTICES 100

// Definição da estrutura de conjunto
typedef struct {
    int representante;
} Conjunto;

// Definição da estrutura União-Busca
typedef struct {
    Conjunto conjuntos[MAX_VERTICES];
} UniaoBusca;


void inicializar(UniaoBusca *u, int n);
void criaConjunto(UniaoBusca *u, int x);
int buscaConjunto(UniaoBusca *u, int x);
void uniao(UniaoBusca *u, int x, int y);
void mostrarConjuntos(UniaoBusca *u, int n);