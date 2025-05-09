## Como compilar e executar


1. Clone o repositório:
   ```bash
   git clone https://github.com/eduardar0/atividade9-md2.git
2. Compile com:
    ```bash
    gcc main.c -o acesso
    ```

3. Execute com:

    ```
    ./acesso
    ```


## Descrição

Este programa implementa um sistema de validação de acesso com base em conceitos de **Teoria dos Números**, como **congruência**, **primalidade**, **coprimalidade**, **Teorema de Fermat**, e **Teorema de Euler**. Ele segue uma sequência de etapas para validar a operação de divisão modular e realizar exponenciação modular eficiente.



## Funções Implementadas

- **algEuclides(int a, int b)**: Algoritmo de Euclides para calcular o maior divisor comum entre a e b.

- **saoCoprimos(int a, int b)**: Verifica se os números a e b são coprimos (MDC(a, b) = 1).

- **primo(int n)**: Verifica se um número n é primo.

- **inversoModular(int G, int n)**: Calcula o inverso modular de G em Z_n utilizando o Algoritmo Estendido de Euclides.

- **exponenciacaoModular(int base, int exp, int mod)**: Exponenciação modular eficiente, calcula base^exp mod n.

- **phi(int n)**: Calcula a função totiente de Euler para um número n.



## Dependencias

- gcc ou outro compilador C.

- Não há bibliotecas externas necessárias para rodar o código.