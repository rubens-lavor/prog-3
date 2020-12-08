# Programação Orientada a Objetos: Operações Bancárias em C++

Este projeto visa demonstrar os principais conceitos de orientação a objeto usando a linguagem C++; são eles: Classe, Encapsulamento, Agregação e Composição, Templates, Sobrecarga de operador, Herança e Polimorfismo. Por meio  de operações bancárias tais como abertura de contas, transferências, demonstrativos bancários (extratos), entre outros. Todo o código está documentado nos arquivos de cabeçalho. 


## Ambiente de Desenvolvimento:

- O código foi desenvolvido e testado na IDE VScode em máquina com o sistema operacinal Ubuntu 20.04 LTS

- Compilador GCC versão 9.3.0 

- Dialeto C++ 17.

- O uso de memória foi verificado usando valgrind

### Flags de compilação usadas:

    -std=c++17 -Wall -Wextra -Werror -Wshadow -Wconversion -Wcast-align

    -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 

    -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs 
     
    -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls 
    
    -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 
    
    -Wswitch-default -Wundef -Wno-unused

## Pré requisitos:
- Compilador GCC instalado versão 8 ou superior

## Verifique a versão do GCC instalado na sua máquina:
Abra o terminal de comando e verifique com o comando abaixo:
    
> gcc -v

---

## Instalando o GCC:

### Instalando o compilador GCC em distribuições Linux:
 Sistemas operacionais construídos a partir do núcleo Linux, como o ubunto, já possui GCC instalado por default, porém algumas você precisa instalar a parte como ferramenta, abaixo os comando para instalar no Fedora, OpenSUSE e Ubuntu: 

#### Fedora

> sudo yum install gcc

#### OpenSUSE

> sudo zypper in gcc

#### Ubuntu

> sudo apt-get update

> sudo apt-get install gcc

### Para Windows - MinGW:

MinGW é um software que inclui um conjunto de arquivos cabeçalho para a API do Windows que permite aos desenvolvedores usar o GCC para criar programas nativos em Windows. Acesse o link abaixo e o download do arquivo mingw-get-setup.exe

https://osdn.net/projects/mingw/releases/

---

## Agora basta compilar e executar o programa

### Abra a pasta do projeto no terminal, compile com o comando:

> $ make all

### Em seguida execute com:


> $ ./main


Todo o projeto foi pensado e programado por
Rubens Heryson de Lima Lavor e Thaiz Antunes Izidoro, para o trabalho final da disciplina de programação 3. 
