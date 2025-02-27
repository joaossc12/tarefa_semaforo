# README

## Descrição
Este projeto implementa um semáforo utilizando a Raspberry Pi Pico e seus pinos GPIO para controlar um LED RGB. O código alterna automaticamente entre as cores vermelho, amarelo e verde, simulando o funcionamento de um semáforo de trânsito.

## Objetivos
- Demonstrar o uso da Raspberry Pi Pico para controle de LEDs.
- Implementar um semáforo funcional utilizando um LED RGB.
- Explorar o uso de timers para alternância periódica entre estados.

## Tecnologias Utilizadas
- **Microcontrolador:** RP 2040
- **Linguagem de Programação:** C
- **IDE:** Visual Studio Code
- **SDK:** Pico SDK
- **Simulador:** Wokwi
- **Controle de Versão:** Git
- **Plataforma de Hospedagem:** GitHub

### Video demostração

- **Simulação no Wokwi:** [Assista no YouTube](https://youtu.be/qP-lvtdPxqc)

## Como executar o Projeto
### Pré-requisitos
- Raspberry Pi Pico
- LED RGB com resistores apropriados
- Ambiente de desenvolvimento configurado para Raspberry Pi Pico (SDK C/C++)

### Passos para execução
1. Clone este repositório para o seu ambiente de desenvolvimento.
2. Compile o código utilizando o SDK da Raspberry Pi Pico.
3. Carregue o binário gerado na Raspberry Pi Pico.
4. Conecte os pinos do LED RGB conforme as definições no código:
   - **Pino 13** - Vermelho
   - **Pino 12** - Azul
   - **Pino 11** - Verde
5. Após a execução, o LED RGB começará a alternar entre as cores vermelho, amarelo e verde a cada 3 segundos, simulando um semáforo.

