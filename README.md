# Decodificador Mips Pocket
**Descrição:** o nível mais baixo de programação de um hardware computadorizado é comumente apresentado como nível assembly (montagem). Nesse nível, só existem comandos básicos, bem simples, que indicam ao hardware (processador ou microcontrolador) uma tarefa bem específica. O sistema implementa exemplos de instruções de um processador simples e bem específico denominado Pocket MIPS Monocycle (PMM). 

## Execução e Teste
### Criar executável
Para criar o executável do projeto basta executar o arquivo **Makefile**
dentro da pasta do projeto:
```bash
$ make
```
Isso irá gerar uma basta **bin** que contém o executável da aplicação. Para iniciar basta rodar o executável:
```bash
$./bin/decoder-mips-pocket
```
**Dica:** a pasta __tests__ contém arquivos que possuem entradas válidas para automatizar  os testes.
```bash
# exemplo de execução com testes pré implementados
$ ./bin/decoder-mips-pocket < ./tests/all-tests.in
```
---
### Código dos registradores
- r0
- r1
- r2
- r3
___

### Tipo - R
Operações aceitas:
- ADD
- SUB
- MTA
- MTB
- MFA
- MFB
- HALT

A sintaxe para executar instruções do **tipo r** é informar o nome da instrução seguida do código do registrador:
#### Exemplo
```bash
# exemplo de entrada 
$ ADD r1
```
```bash
# saída para instrução ADD r1
$ 000 01 000
```
___

## Tipo - I
Operações aceitas:
- ADDI
### Exemplos
A sintaxe para executar instruções do **tipo i** é informar o nome da instrução seguida de um número inteiro de 0 a 31:
```bash
# exemplo de entrada 
$ ADDI 6
```
```bash
# saída 
$ 001 00110
```
___

## Tipo - J
Operações aceitas:
- BEQ
### Exemplos
A sintaxe para executar instruções do **tipo i** é informar o nome da instrução e em seguida o codigo de dois registradores:
```bash
# exemplo de entrada 
$ BEQ r0, r1
```
```bash
# saída 
$ 011 00 01 0
```
**obs**: a virgula entre o código dos registradores é facultativa.  

```bash
# exemplo de entrada sem virgula entre registradores
$ BEQ r1 r2
```

```bash
# saída 
$ 011 01 10 0
```
___