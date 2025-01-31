#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define PERIODO_MS 3000

uint8_t control = 0; // Inicia no vermelho
uint8_t contador = 3;
void init_pinos();

// Callback do timer para atualizar o semáforo
bool atualizar_semaforo(struct repeating_timer *t) {
    control = (control + 1) % 3; // Alterna entre 0, 1 e 2

    switch(control){
        case 0: // Vermelho
            gpio_put(LED_RED, 1);
            gpio_put(LED_BLUE, 0);
            gpio_put(LED_GREEN, 0);
            break;
        case 1: // Amarelo (Vermelho + Verde)
            gpio_put(LED_RED, 1);
            gpio_put(LED_BLUE, 0);
            gpio_put(LED_GREEN, 1);
            break;
        case 2: // Verde
            gpio_put(LED_RED, 0);
            gpio_put(LED_BLUE, 0);
            gpio_put(LED_GREEN, 1);
            break;
    }
    return true; 
}

int main() {
    init_pinos();
    stdio_init_all();

    // Garante que o semáforo inicie no vermelho
    gpio_put(LED_RED, 1);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);

    struct repeating_timer timer;
    add_repeating_timer_ms(PERIODO_MS, atualizar_semaforo, NULL, &timer);

    while (true) {
      printf("Semáforo alternando em %d  segundos\n", contador);
      contador --;
      if (contador == 0){contador = 3;}
      sleep_ms(1000);
    }
}

// Inicializa os pinos do LED RGB
void init_pinos(){
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
 
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
 
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
}
