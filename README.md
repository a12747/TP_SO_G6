# Trabalho Prático

## Introdução
Este trabalho prático tem como objetivo a aplicação prática dos conceitos de gestão de processos e de ficheiros.

## Parte 1 -Implementação um conjunto de comandos para manipulação de ficheiros
Implemente os seguintes comandos através de funções de chamada ao sistema
(system calls) (ver https://linux.die.net/man/). Estes comandos devem ser
implementados em C (para Linux) e serão invocados através de um interpretador de
comandos. Qualquer mensagem de erro deverá ser apresentada no descritor stderr,
não utilize programação shell, funções LibC (fopen, fread, etc…) ou comandos
pré-existentes para executar a funcionalidade pretendida.

a) mostra ficheiro – Este comando deve apresentar no ecrã todo o conteúdo
do ficheiro indicado como parâmetro. Caso o ficheiro não exista, o comando
deve avisar o utilizador que o ficheiro não existe;

b) copia ficheiro – Este comando deve criar um novo ficheiro, cujo nome é
“ficheiro.copia”, cujo conteúdo é uma cópia de (todo) o conteúdo do
ficheiro passado como parâmetro no comando, com o nome ficheiro. Caso o
ficheiro não exista, deve ser apresentado um aviso ao utilizador;

c) acrescenta origem destino – Este comando deve acrescentar (todo) o
conteúdo da “origem” no final do “destino”. Caso algum dos ficheiros não
exista, deve ser apresentado um aviso ao utilizador;

d) conta ficheiro – Este comando deve contar o número de linhas existentes
num ficheiro. Se o ficheiro não existir, deverá ser indicado ao utilizador uma
mensagem de erro;

e) apaga ficheiro – Este comando deve apagar o ficheiro com o nome indicado.
No caso de o ficheiro indicado não existir, e apenas, deve ser apresentado
um aviso ao utilizador;

f) informa ficheiro – Este comando apresenta apenas a informação do sistema
de ficheiros em relação ao ficheiro indicado, tipo de ficheiro (normal,
diretoria, link, etc.), i-node, utilizador dono em formato textual e datas de
criação, leitura e modificação em formato textual;

g) lista [directoria] – Este comando deve apresentar uma lista de todas as
pastas e ficheiros existentes na directoria indicada ou na diretoria atual se
não especificada. Adicionalmente, deve distinguir ficheiros simples de
diretorias através de uma indicação textual.

## Parte 2 - Implementação de um interpretador de linha de comandos
No sentido de substituir o interpretador de comandos habitual, Bash shell, por um
novo interpretador personalizado, deve ser implementada uma aplicação, de nome
interpretador, cuja função será a leitura de uma sequência de caracteres da consola, e
em seguida executar essa sequência como um comando e respetivos argumentos no
sistema. O programa deve mostrar o símbolo “%” como indicação de que está pronto
para ler um novo comando do utilizador.
O programa deve executar o comando através de primitivas de execução genérica de
processos tendo como referência a funcionalidade da função system(3), mas sem fazer
uso da mesma. Cada comando escrito deve dar origem a um novo processo.
Adicionalmente, pode considerar que a execução do interpretador deve ser suspensa
até o comando indicado estar concluído. O interpretador deve indicar sempre se o
comando concluiu com ou sem sucesso, através do seu código de erro/terminação. O
programa deve permitir executar vários comandos sequencialmente, isto é, um a
seguir ao outro, atéo utilizador indicar o comando especial “termina” que termina esta
aplicação.

$ ./interpretador
% lista /home/user/Desktop
...
Terminou comando lista com código 0
% apaga /home/user/Desktop/file
...
Terminou comando apaga com código 1
% termina
$

## Parte 3 - Gestão de Sistemas de Ficheiros e Análise ao Sistemas de Ficheiros
a) Num servidor virtual, adicione um disco novo com o tamanho de 10GB (espaço
alocado dinamicamente) e crie uma partição.
b) No disco virtual criado na alínea a), deve criar um volume, que ocupe o espaço
todo, e dentro desse volume, deve adicionar dois volumes lógicos, cada um
com o tamanho de 5GB.
c) Nos volumes lógicos criados no passo b), crie um sistema de ficheiros ext4 em
um deles e ext3 no outro.
d) Monte cada um dos sistemas de ficheiros criados em c) nas directorias
/mnt/ext4 e /mnt/ext3 , respectivamente, ficando persistente a reboots.
e) Dentro da diretoria /mnt/ext4, crie um ficheiro com o nome composto pelo
grupo dos números de alunos que constituem o trabalho, e a extensão .txt
(exemplo: 22222-22233-23333-24003.txt). Esse ficheiro deverá ter, apenas,
permissões de escrita e leitura para o dono (que será o utilizador que está a
usar o sistema sem ser root), o grupo não deve ter qualquer permissão neste
ficheiro, e todos os outros devem ter permissão de leitura.

Com base no ficheiro fs.img (disponível no moodle), responda às seguintes questões:
a) Identificar o bloco de início dos ficheiros regulares presentes do sistema de
ficheiros
b) Indique o conteúdo do ficheiro com o nome ipca.txt

Em todos os passos deve descrever os passos necessários, completando a sua resposta
com os screenshots necessários.




