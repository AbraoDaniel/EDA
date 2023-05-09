struct Produto{
    int codigo;
    char descricao[30];
    float preco;
};

void mostra_produto( struct Produto x );

void gera_dados_produto( struct Produto *p );

int busca_produto( struct Produto v[], int n, int codigo );


