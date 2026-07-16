#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>


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

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec =0;
        setsockopt(socket_rede, SOL_SOCKET,SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

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
    printf("[*] Porta %d:\n", porta);
    conexoes += 1;

    const char *mensagem_usuario = 
    " ____            _   ____                             \n"
        "|  _ \\ ___  _ __| |_/ ___|  ___ __ _ _ __  _ __   ___ _ __\n"
        "| |_) / _ \\| '__| __\\___ \\ / __/ _` | '_ \\| '_ \\ / _ \\ '__|\n"
        "|  __/ (_) | |  | |_ ___) | (_| (_| | | | | | | |  __/ |   \n"
        "|_|   \\___/|_|   \\__|____/ \\___\\__,_|_| |_|_| |_|\\___|_|  \n"
        "\n                       v1.1\n";

    send(socket_rede, mensagem_usuario, strlen(mensagem_usuario), 0);
    printf("    [>] Mensagem enviada!\n\n");

    char buffer_resposta[1024];
    memset(buffer_resposta, 0, sizeof(buffer_resposta));   

   

        }
   
    }
 printf("Quantidade de conexões: %d\n", conexoes);
}
//comando para abrir uma porta:     sudo nc -lk 127.0.0.1 {n da porta}          ex: sudo nc -lk 127.0.0.1 80