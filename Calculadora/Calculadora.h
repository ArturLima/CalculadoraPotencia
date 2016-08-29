//typedef struct lista Lista;


void menu(Lista * base, Lista * expoente, Lista * resultado, Lista * parcela1, Lista * parcela2, int dig);
void creditos();
void limpar_tela();

Lista * calculadora_soma(Lista * parcela1, Lista * parcela2);
Lista * calculadora_multiplica_dig(Lista * parcela1, int dig);
void calculadora_multiplica(Lista * parcela1, Lista * parcela2, Lista * resultado);
void calculadora_potencia(Lista * base, Lista * expoente, Lista * resultado);

void limpar_listas(Lista * parcela1, Lista * parcela2, Lista * resultado);
void inserir_listas(Lista * parcela1, Lista * parcela2);
