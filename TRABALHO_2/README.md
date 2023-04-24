# Trabalho 1: Avaliação de uma expressão aritmética

O objetivo deste trabalho é implementar um programa em C que lê uma string
que contenha uma expressão aritmética na notação infixa, converta para a notação
posfixa e avalie o seu resultado, ou seja, calcule o valor esperado para a expressão. Os
algoritmos para a conversão entre as notações bem como para a avaliação da expressão
utilizam uma pilha.

Numa expressão em notação infixa, operadores são separados pelos respectivos
operandos, e a mudança na ordem de precedência de operadores pode ser feita mediante
o uso de parênteses. Considere os exemplos a seguir:

![image](https://user-images.githubusercontent.com/50593898/231619109-83290100-fc66-4cbd-a379-035b15302eba.png)

Os poloneses desenvolveram métodos de notação que não necessitam de uso de
parênteses para definir uma outra ordem de avaliação das operações nas expressões: a
notação prefixa e a notação posfixa.

Numa expressão em notação prefixa, o operadores antecedem os seus
operandos, conforme mostrado a seguir:

![image](https://user-images.githubusercontent.com/50593898/231619166-e0f5f3fe-81ff-425d-a0f1-810467763396.png)

Já numa expressão em notação posfixa, os operadores sucedem seus respectivos
operandos, conforme segue:

![image](https://user-images.githubusercontent.com/50593898/231619203-77a11635-61dc-46f2-a8ad-dd2f6c26eac4.png)


A notação posfixa permite uma implementação mais simples para o cálculo das
operações da expressão. Portanto, o trabalho compreente a implementação de dois
algoritmos, cada um utilizando uma pilha como estrutura auxiliar:

#### 1) Conversão da string de entrada da notação infixa para a notação posfixa;

#### 2) Avaliação da expressão na notação posfixa, mostrando na tela o resultado calculado.


Observação: para simplificar o processamento, os algoritmos propostos a seguir
consideram que os valores e operações estão no domínio dos inteiros, os números
possuem somente um dígito, e não é permitido espaços em branco. Todavia, é possível
adaptar estes algoritmos para eliminar tais restrições.

## 1) Conversão entre Infixo e Posfixo
Variáveis utilizadas:
<p/> - Entrada: string E (notação infixa);
<p/> - Saída: string S (notação posfixa);
<p/> - Uma pilha é usada para empilhar os operadores e o '('. Os operandos são
copiados diretamente de E para S;
<p/> - Caracteres c e x;
<p/> - Booleano (inteiro em C padrão) para guardar condição de erro na entrada.


## Pseudocódigo:

![image](https://user-images.githubusercontent.com/50593898/231619380-596671c6-e529-4683-8713-2937ede0932d.png)
![image](https://user-images.githubusercontent.com/50593898/231619403-04e5858f-97b6-4e9d-b306-200e74c24fd0.png)


Observação: na linha 27, a função precendecia() é invocada. Ela serve para retornar
o nível de precedência entre operadores, de modo que o laço de repetição desempilhe os
operadores de maior precedência e os coloque na string de saída antes do operador lido
na entrada. A função recebe um char como parâmetro e retorna um int, conforme o
seguinte padrão:

<p/> - Retorna 0, se o caractere for '(' // Ver nota de rodapé -> 1
<p/> - Retorna 1, se o caractere for '+' ou '-';
<p/> - Retorna 2, se o caractere for '*' ou '/';

## 2) Avaliação de expressões em notação posfixa

Variáveis utilizadas:
<p/> - Entrada: string representando uma expressão em notação posfixa;
<p/> - Saída: valor inteiro, resultante da avaliação da expressão;
<p/> - Uma pilha é usada para empilhar os operandos (inteiros);
<p/> - Variáveis inteiras auxiliares.

## Pseudocódigo:

![image](https://user-images.githubusercontent.com/50593898/231620655-24301af9-81da-4add-b8bb-ea87254fc3ee.png)

Ao final do algoritmo, a pilha guardará o resultado total da avaliação da
expressão.

### Observações sobre a implementação
<p/> É possivel (e até recomendável) construir funções auxiliares para algumas etapas
dos processamentos. Por exemplo, no 2º algoritmo, uma função útil seria para a
verificação se um caractere é dígito; outra poderia ser usada para a realização do cálculo
com base no tipo de operador e os valores dos operandos.


<p/> A conversão de char para int em linguagem C é bem simples, bastando subtrair
48 do valor (código ASCII) do caractere.


<p/> A pilha de inteiros pode ser usada em ambos os algoritmos, visto que um char
pode ser armazenado na pilha de inteiros (conforme mostrado em aula).


#### Critérios de avaliação
<p/> - Execução correta e alinhamento com o que foi solicitado neste enunciado;
<p/> - Uso apropriado das funções dos tipos abstratos de dados (biblioteca de pilha).
Respeite o encapsulamento!
