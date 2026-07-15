#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){

    const char *ip_alvo = "127.0.0.1"; 
    int porta_inicio = 22;
    int porta_final = 443;
    int conexoes = 0;

    printf("Iniciando escaneamento no ip: %s da porta %d até a porta %d\n\n", ip_alvo, porta_inicio, porta_final);

    for (int porta = porta_inicio; porta <= porta_final; porta++)
    {
        int socket_rede = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_rede < 0)
        {
            printf("Falha ao criar Socket\n");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in alvo;
        memset(&alvo, 0, sizeof(alvo));
        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(porta);

        if (inet_pton(AF_INET, ip_alvo, &alvo.sin_addr) <= 0)
        {
            printf("Ip inválido.\n");
            exit(EXIT_FAILURE);
        }
        
        int conexao_ip = connect(socket_rede, (struct sockaddr *)&alvo, sizeof(alvo));

        if (conexao_ip == 0)
        {
            printf("[*] Porta %d: aberta\n", porta);
            conexoes +=1;
        }
        
        close(socket_rede);
    }
    
    printf("\n[-] Quantidade de portas abertas: %d\n", conexoes);
    return 0;
}
/*comando para abrir uma porta:     sudo nc -lk 127.0.0.1 {n da porta}          ex: sudo nc -lk 127.0.0.1 80

*/