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

## Etapas do Programa

1. **Verificação de Coprimalidade**: Utiliza o Algoritmo de Euclides para verificar se os números G e n são coprimos.
2. **Inverso Modular**: Calcula o inverso de G no conjunto Z_n utilizando o Algoritmo Estendido de Euclides.
3. **Divisão Modular**: Realiza a operação de divisão modular de H por G no módulo n.
4. **Verificação de Coprimalidade de a e n1**: Verifica se a e n1 são coprimos usando o Algoritmo de Euclides.
5. **Verificação de Primalidade de n1**: Verifica se n1 é primo para aplicar o Pequeno Teorema de Fermat, ou se deve usar o Teorema de Euler.
6. **Decomposição do Exponente**: Decompõe o expoente x no formato \( x = q \cdot x1 + r \).
7. **Cálculo de Valores Intermediários**: Calcula os valores intermediários necessários para a exponenciação modular.
8. **Cálculo do Resultado Final**: Combina os valores intermediários e calcula o resultado final da congruência.

## Dependencias

- gcc ou outro compilador C.

- Não há bibliotecas externas necessárias para rodar o código.