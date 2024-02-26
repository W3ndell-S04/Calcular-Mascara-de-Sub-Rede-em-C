# Programa para Calculo de Mascara de Sub_Rede feito em C

Este é um programa em C que calcula a máscara de sub-rede com base em um endereço IP fornecido pelo usuário. Ele também determina o número de endereços IP disponíveis na sub-rede e o formato CIDR (Classless Inter-Domain Routing) correspondente.


# Instrução de uso

1- **Compilação:** 
Compile o programa usando um compilador C compatível (por exemplo, gcc).

    gcc calcMask.c -o calc.exe

2 - **Execução:**
Execute o programa compilado e siga as instruções para fornecer o endereço IP.

    ./calc.exe
    


3 **Entrada de Dados**: Insira o endereço IP conforme solicitado pelo programa.
    
4  **Resultado**: O programa calculará e exibirá a máscara de sub-rede correspondente, o número de endereços IP disponíveis e o formato CIDR.



## Exemplo de Saída  
```shell
Digite o endereco IP: 10.0.0.0
Classe de IP: A
Mascara de Sub-rede: 255.0.0.0
Numero de enderecos IP: 256
Numero de IPs utilizaveis: 254
Faixa de enderecos validos para uso em maquinas: 10.0.0 - 10.0.0.255
CIDR: /8
```
