#include <stdio.h>

// máximo divisor comum (algEuclides)
int algEuclides(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int saoCoprimos(int a, int b) {
    return algEuclides(a, b) == 1;
}

// ver se o numero é primo
int primo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// inverso modular de G em Z_n usando o Algoritmo Estendido de Euclides
int inversoModular(int G, int n) {

    int t = 0, novo_t = 1;
    int r = n, novo_r = G;
    while (novo_r != 0) {
        int q = r / novo_r;
        int temp = novo_t;
        novo_t = t - q * novo_t;
        t = temp;

        temp = novo_r;
        novo_r = r - q * novo_r;
        r = temp;
    }
    if (r > 1) return -1; // não tem inverso
    if (t < 0) t += n;
    return t;
}

// exponenciação modular eficiente
int exponenciacaoModular(int base, int exp, int mod) {
    int resultado = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            resultado = (resultado * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return resultado;
}

// Função para calcular a função totiente de Euler φ(n)
int phi(int n) {
    int resultado = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            resultado -= resultado / i;
        }
    }
    if (n > 1)
        resultado -= resultado / n;
    return resultado;
}

int main() {
    
    int H, G, n, x, n1;
    printf("Digite os valores de H, G, n somente: \n");
    scanf("%d %d %d", &H, &G, &n);
    printf("\n");

    printf("Agora digite o expoente x que vai exponenciar A, e o novo modulo n1:\n");
    scanf("%d %d", &x, &n1);

    printf("\n");

    printf("Etapa 1:Sao coprimos? \n");
    if (algEuclides(G, n) != 1) {
        printf("G = %d e n = %d NAO! Divisao nao possivel.\n", G, n);
        return 1;
    }

    else{
        printf("SIM! G = %d e n = %d  sao coprimos, operacao viavel, exite o inverso de %d em z%d, pois o mdc entre eles resulta em 1, verificado pelo algoritmo de euclides \n", G, n, G, n);
        printf("\n");
    }



    printf("\nEtapa 2: Inverso modular de %d em Z%d \n",G, n);

    int Ginv = inversoModular(G, n);


    printf("Usando os restos encontrados no algoritmo de euclides ao encontar o mdc no teorema de bezoult, o inverso de %d em z%d e: %d\n", G, n, Ginv);
    printf("\n");


    printf("\nEtapa 3: Divisao modular \n");
    printf("\n");
    printf("A divisao mudular e caracterizada por usar a multiplicacao modular de H(%d) pelo inverso de G(%d), ou seja, o numero que faca o mod de G por n(%d) resulte em 1;\n", H,G,n );
    printf("\n");
    printf("O inverso de G ja foi calculado na etapa 2, (resultou em %d);\n", Ginv);
    printf("\n");

    int a = (H * Ginv) % n;
    printf("o resultado da multiplicao muldular de %d por %d no universo %d resultou em: %d; \n", H,Ginv, n, a);
    printf("\n");
    printf("ou seja, a = %d.\n", a);
    printf("\n");





    printf("\nEtapa 4: a = %d e n1 = %d sao coprimos?? \n", a, n1);

    printf("\n");


    if (!saoCoprimos(a, n1)) {
        printf("NAO! a e n1 nao sao coprimos. Euller ou fermat não funcionariam.\n");
        return 1;
    } 
    
    else {
        printf("SIM! a(%d) e n1(%d) sao coprimos (tambem pelo alg de euclides).\n", a, n1);
        printf("\n");
    }



    printf("\nEtapa 5: n1(%d) e primo? \n", n1);
    int x1;
    if (primo
    (n1)) {
        x1 = n1 - 1;
        printf("SIM! n1 e primo. Usando Pequeno Teorema de Fermat x1 = %d - 1 (x1 será decomposto em funcao do expoente)  = %d\n", n1,x1);
        printf("\n");
    } 
    
    else {
        x1 = phi(n1);
        printf("NAO! n1 nao e primo. Usando Teorema de Euler: phi(n1) = %d\n", x1);
        printf("\n");
    }

    printf("\nEtapa 6: Decompor expoente no formato a = b * q + r \n");
    int q = x / x1;
    int r = x % x1;
    printf("x = %d = %d * %d + %d\n", x, x1, q, r);
    printf("\n");

    printf("\nEtapa 7: Calcular valores intermediarios \n");
    int x2 = exponenciacaoModular(a, x1, n1);
    int x2q = exponenciacaoModular(x2, q, n1);
    int ar = exponenciacaoModular(a, r, n1);

    printf("a^%d mod %d = %d\n",x1,n1 , x2);
    printf("\n");
    printf("%d^%d mod n1 = %d\n", x2, q, x2q);
    printf("\n");
    printf("%d^r mod %d = %d\n",a, n1,  ar);
    printf("\n");


    printf("\nEtapa 8(final): Resultado final da congruencia \n");
    int resultado = (x2q * ar) % n1;
    printf(" (%d)^%d mod %d = %d\n",  a, x, n1, resultado);
    printf("\n");

    return 0;
}

//