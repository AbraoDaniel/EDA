#define ERRO_FILA_VAZIA - 1
#define ERRO_FILA_CHEIA - 2

typedef struct fila {
    int *dados;     // vetor para armazenar os dados da fila
    int capacidade, fim, n, inicio; 
} Fila;

void inicializa_fila( Fila *p, int c );
int fila_vazia( Fila f );
int fila_cheia( Fila f );
int inserir( Fila *p, int info );
int remover( Fila *p, int *info );
void mostra_fila( Fila f );
void desaloca_fila( Fila *p );

