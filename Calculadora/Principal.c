#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Lista.h"
#include "Calculadora.h"


int main()
{
	
	setlocale(LC_ALL, "");
	
	Lista * base = criar();
	Lista * expoente = criar();
	Lista * resultado = criar();
	
	Lista * parcela1 = criar();
	Lista * parcela2 = criar();
	int dig;
	
	titulo();
	
	menu(base, expoente, resultado, parcela1, parcela2,dig);

	
	
	destruir(base);
	destruir(expoente);
	destruir(resultado);
	
	destruir(parcela1);
	destruir(parcela2);
	
	system("pause");
}

void menu(Lista * base, Lista * expoente, Lista * resultado, Lista * parcela1, Lista * parcela2, int dig)
{

	char escolha, calculadora, potencia;
	
	
	
	printf("\n\n\t\t\tCalculadora");
	printf("\n\n\t\t01. Calculadoras");
	printf("\n\t\t02. Créditos");
	printf("\n\t\t03. Sair");
	printf("\n\n\t\tEscolha a opção: ");
	scanf("%s", &escolha);

	switch(escolha)
	{

		case '1':
			limpar_tela();
			printf("\n\n\t\tCalculadora");
			printf("\n\n\t\t01. Soma");
			printf("\n\t\t02. Multiplicação");
			printf("\n\t\t03. Potenciação");
			printf("\n\n\t\tEscolha a calculadora: ");
			scanf("%s", &calculadora);
			
			switch(calculadora)
			{
				
				case '1':
                     
					limpar_tela();
					limpar_listas(parcela1, parcela2, resultado);
					resultado = calculadora_soma(parcela1, parcela2);
					getch();
					limpar_tela();
					return menu(base, expoente, resultado, parcela1, parcela2,dig);
					break;
				case '2':
					limpar_tela();
					limpar_listas(parcela1, parcela2, resultado);
					resultado = calculadora_multiplica_dig(parcela1,dig);
					getch();
					limpar_tela();
					return menu(base, expoente, resultado, parcela1, parcela2,dig);
					break;
				case '3':
					limpar_tela();		
					printf("\n\n\t\t01. Insira Base");
					printf("\n\t\t02. Inserir Expoente");
					printf("\n\t\t03. Resultado");
					printf("\n\n\t\tEscolha a Opção: ");
					scanf("%s", &potencia);
					
					switch(potencia)
					{
						
						case '1':
						
							break;
						
						case '2':
						
							break;
							
						case '3':
						
							break;
							
						case '4':
						
							break;
							
						default:
							
							return menu(base, expoente, resultado, parcela1, parcela2,dig);
							break;	
					}
					
					break;
				case '4':
					limpar_tela();
					return menu(base, expoente, resultado, parcela1, parcela2,dig);
					break;
						
			}
			break;
		case '2':
			limpar_tela();
			creditos();
			getch();
			limpar_tela();
			return menu(base, expoente, resultado, parcela1, parcela2,dig);
			break;
		case '3':

			exit(0);
			break;

		default:
			
			limpar_tela();
			return menu(base, expoente, resultado, parcela1, parcela2,dig);
			break;

	}



}

void creditos()
{

	printf("Projeto Desenvolvido em C, \n Por Thyago Oliveira e Artur Lima");
}

void limpar_tela()
{
	system("cls");
}

void limpar_listas(Lista * parcela1, Lista * parcela2, Lista * resultado)
{
     
     limpar(parcela1);
     limpar(parcela2);
     limpar(resultado);
}

void inserir_listas(Lista * parcela1, Lista * parcela2)
{
	
	int valorParcela1 = 0, valorParcela2 = 0;
	int aux1 = 0, aux2 = 0;
	int i, n;
	
	printf("\n\n\t Digite a primeira Parcela: ");
	scanf("%d", &valorParcela1);
	printf("\n\t Digite a segunda Parcela: ");
	scanf("%d", &valorParcela2);
	printf("\n");
	
	if(valorParcela1 <= 9)
	{
		inserir_pos(parcela1, 0, valorParcela1);		
	} else {
		
		 	for(i = 0; valorParcela1 > 0; i++)
			{
				inserir_primeiro(parcela1, valorParcela1 %10);
    			valorParcela1 = valorParcela1/10;
			}
	}
	
	aux1 = 0;
	aux2 = 0;
	
	if(valorParcela2 <= 9)
	{
		inserir_pos(parcela2, 0, valorParcela2);		
	} else {
		
			for(i = 0; valorParcela2 > 0; i++)
			{
				inserir_primeiro(parcela2, valorParcela2 %10);
    			valorParcela2 = valorParcela2/10;
			}
			
	}	
}

Lista * calculadora_soma(Lista * parcela1, Lista * parcela2)
{
		
	inserir_listas(parcela1, parcela2);
	
	Lista * resultado = criar();
	
	int cima, soma, i;
	
	cima = 0;
	soma = 0;
	int tam1, tam2;
	tam1 = tamanho(parcela1);
	tam2 = tamanho(parcela2);
	
	
	imprimir(parcela1);
	imprimir(parcela2);
	system("pause");
	
	if(tamanho(parcela1) > tamanho(parcela2))
	{
 
            for(i = 0; i < tam1 - tam2 ; i++)
			{
                  inserir_primeiro(parcela2, 0);
                        
            } 
            
    } else{
    	for(i = 0; i < tam2 - tam1 ; i++)
		{
            inserir_primeiro(parcela1,0);     
        }
	}
    
    imprimir(parcela1);
    imprimir(parcela2);
    system("pause");
    
    for(i = tamanho(parcela1) ; i > 0 ; i--)
	{
    	
          soma = ler_pos(parcela1, i-1) + ler_pos(parcela2, i-1) + cima;
          inserir_primeiro(resultado, soma % 10);
          cima = soma / 10;
    }
    
    if(cima > 0)
	{
            printf("Entrou");
             printf("\n Cima = %d", cima ); 
                 
             inserir_primeiro(resultado,cima);
             printf("\n Resultado = "); imprimir(resultado);      
    }
    
    
    printf("\t Primeira Parcela: ");
	imprimir(parcela1);
	printf("\t Segunda Parcela: ");
	imprimir(parcela2);
	printf("\t Resultado: \t");
	imprimir(resultado);
	
	return resultado;
}

Lista * calculadora_multiplica_dig(Lista * parcela1, int dig)
{
	
	int valorParcela1, valor, i, tam, cima, baixo, resultadoM,j;
	Lista * resultado = criar();
	
	cima =0;
	baixo = 0;
	valor = 0;
	
	printf("\n\tparcela1:");
	scanf("%d", &valorParcela1);
	
	printf("\n\tdig:");
	scanf("%d", &dig);
	
	for(i = 0; valorParcela1 > 0; i++)
	{
		inserir_primeiro(parcela1, valorParcela1 %10);
    	valorParcela1 = valorParcela1/10;
	}
	tam = tamanho(parcela1);
	imprimir(parcela1);
	system("pause");
	
	for(i = tam; i > 0 ; i--)
	{
		printf("Entrou");
		printf("\nI = %d", i);
		
		valor = ler_pos(parcela1,i-1) * dig;
		
		printf("\nValor = %d", valor);
		
		system("pause");
		
		if(valor>=10)
		{
			printf("\nEntrou");
				
			cima = valor/10;
			baixo = valor % 10;
			
			resultadoM = valor + cima;
			
			printf("\nCima = %d", cima);
			printf("\nBaixo = %d", baixo);
			printf("\nResultadoM = %d", resultadoM);
			
			system("pause");
			
			inserir_primeiro(resultado,baixo);
			imprimir(resultado);
			system("pause");
			
		}else{
			
			inserir_primeiro(resultado,valor);
		}
			
		if(cima > 0)
		{
			
			inserir_primeiro(resultado, cima);
		}
			imprimir(resultado);
	}
	
	imprimir(parcela1);
	printf("%d", dig);
	imprimir(resultado);
	
	return resultado;
	
}

void calculadora_multiplica(Lista * parcela1, Lista * parcela2, Lista * resultado)
{
	
	inserir_listas(parcela1, parcela2);
	
	int i, n, cima = 0, baixo = 0, valor = 0, x = 0;
	
	if(tamanho(parcela1) >= tamanho(parcela2))
	{
		n = tamanho(parcela1);
	}else{
		n = tamanho(parcela2);
	}
	
		
	for(i = 0; i < n; i++)
	{
			
		printf("\nI = %d",i );
			
		valor = ler_pos(parcela1,i) * ler_pos(parcela2,i);
				
		printf("\nValor = %d",valor);
			
		if(valor >= 10)
		{
				
			cima = valor/10;
			baixo = valor % 10;
				
			printf("\nCima =  %d", cima);
			printf("\nBaixo = %d ", baixo);
			
			
			inserir_pos(resultado,i,baixo);
			x = cima;		
		}else{
			inserir_pos(resultado, i, ler_pos(parcela1, i) * ler_pos(parcela2, i));
		}
			
		if(x > 0)
		{
			inserir_pos(resultado, i, cima + baixo);
		}else{
			inserir_pos(resultado,i,baixo);
		}
			
		x = cima;
	}
	

	
    
    printf("\t Primeira Parcela: ");
	imprimir(parcela1);
	printf("\t Segunda Parcela: ");
	imprimir(parcela2);
	printf("\t Resultado: \t");
	imprimir(resultado);
		
}

void calculadora_potencia(Lista * base, Lista * expoente, Lista * resultado)
{
		
		int valorBase, valorExpoente;
		
		
		printf("\n\n Digite a Base: ");
		scanf("%d", &valorBase);
		printf("\n Digite o Expoente: ");
		scanf("%d" , &valorExpoente);	
		printf("\n");
		
		if(valorBase <= 9 || valorExpoente <= 9)
		{
			
			inserir_pos(base, 0, valorBase);
			inserir_pos(expoente, 0, valorExpoente);	
		} else {
			
		}
		
		
		imprimir(base);
		imprimir(expoente);
}	

