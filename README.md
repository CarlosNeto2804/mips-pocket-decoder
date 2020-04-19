# Decodificador Mips Pocket
![UFMS](https://s1.static.brasilescola.uol.com.br/be/vestibular/-5b8eb74b1d9fe.jpg)
![SI](https://img.elo7.com.br/product/zoom/17B0528/adesivo-curso-sistemas-de-informacao-sistemas-de-informacao.jpg)

**Descrição:** o nível mais baixo de programação de um hardware computadorizado é comumente apresentado como nível assembly (montagem). Nesse nível, só existem comandos básicos, bem simples, que indicam ao hardware (processador ou microcontrolador) uma tarefa bem específica. A Tabela a seguir apresenta exemplos de instruções de um processador simples e bem específico denominado Pocket MIPS Monocycle (PMM).  Observe que a 1a. coluna indica o nome (mnemônico da instrução), a 2a. coluna indica a sintaxe de utilização da instrução, a 3a. coluna mostra a ação realizada em cada instrução. A 4a. e última coluna apresenta o formato (código binário de máquina) de cada instrução. Em instruções em que há sequências de XXX, isso significa que os respectivos bits são Don't care (não importa valor que possuem). Observe finalmente que cada instrução, independente da sua funcionalidade, possui tamanho de 8 bits.

## Testes
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