#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16

void calculate_subnet_mask(char *ip_address);
void print_class_and_cidr(char *ip_address, int num_bits_host);

int main() {
    char ip_address[MAX_IP_LENGTH];
    
    printf("Digite o endereco IP: ");
    scanf("%s", ip_address);

    calculate_subnet_mask(ip_address);

    return 0;
}

void calculate_subnet_mask(char *ip_address) {
    int first_octet;
    sscanf(ip_address, "%d", &first_octet);
    int num_bits_host = 0;
    int num_addresses = 0;
    char network_address[16];
    char broadcast_address[16];

    if (first_octet >= 1 && first_octet <= 126) {
        printf("Classe de IP: A\n");
        printf("Mascara de Sub-rede: 255.0.0.0\n");
        num_bits_host = 24;
        num_addresses = 1 << (32 - num_bits_host);
    } else if (first_octet >= 128 && first_octet <= 191) {
        printf("Classe de IP: B\n");
        printf("Mascara de Sub-rede: 255.255.0.0\n");
        num_bits_host = 16;
        num_addresses = 1 << (32 - num_bits_host);
    } else if (first_octet >= 192 && first_octet <= 223) {
        printf("Classe de IP: C\n");
        printf("Mascara de Sub-rede: 255.255.255.0\n");
        num_bits_host = 8;
        num_addresses = 1 << (32 - num_bits_host);
    } else {
        printf("Classe de IP: D ou E\n");
        printf("Mascara de Sub-rede nao aplicável\n");
        return;
    }

    int num_available = num_addresses - 2; // Remove o endereço de rede e o de broadcast

    printf("Numero de enderecos IP: %d\n", num_addresses);
    printf("Numero de IPs utilizaveis: %d\n", num_available);

    // Calcular o endereço da rede
    sprintf(network_address, "%s", ip_address);
    char *last_octet = strrchr(network_address, '.');
    *last_octet = '\0';

    // Calcular o endereço de broadcast
    sprintf(broadcast_address, "%s", ip_address);
    char *last_octet_broadcast = strrchr(broadcast_address, '.');
    sprintf(last_octet_broadcast, ".255");

    printf("Faixa de enderecos validos para uso em maquinas: %s - %s\n", network_address, broadcast_address);

    print_class_and_cidr(ip_address, num_bits_host);
}

void print_class_and_cidr(char *ip_address, int num_bits_host) {
    printf("CIDR: /%d\n", 32 - num_bits_host);
}
