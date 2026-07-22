Um scanner de portas TCP  desenvolvido em C para ambientes Linux. 
O scanner realiza varreduras sequenciais em um intervalo de portas de um endereço IP alvo.


Para compilar o programa basta rodar:

`gcc main.c -o main`

E para executar:

`./main {ip alvo}`

---

**Obs:** * É necessária que o compilador da linguagem C esteja baixado:

Debian/Ubuntu:

`sudo apt install gcc`


Fedora:

`sudo dnf install gcc`


Arch:

`sudo pacman -S gcc`

