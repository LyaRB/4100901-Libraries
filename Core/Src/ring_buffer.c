/*
 * ring_buffer.c
 *
 *  Created on: Aug 23, 2024
 *      Author: Paulina Ruíz
 */
#include "ring_buffer.h"

//para crear la memoria en buffer
#define capacity (11)
uint8_t ring_buffer[capacity];
uint8_t head_ptr;
uint8_t tail_ptr;
uint8_t is_full;
uint8_t numberID[] = {'1','0','0','2','6','0','9','4','9','3'};


void ring_buffer_write(uint8_t data){
		ring_buffer[head_ptr] = data;
		head_ptr = head_ptr + 1; //los espacios van a ir moviendose

		if(head_ptr >= capacity){ //indica el final del recorrido de la cabeza
			head_ptr = 0;
		}

		if(is_full != 0){ //si se pierden datos viejos, para que la cola avance
			tail_ptr = tail_ptr + 1;
		}

		if(tail_ptr >= capacity){ //si la cola llega al final de la memoria
			tail_ptr = 0; //se reinicia la bandera
		}

		if(head_ptr == tail_ptr){ //si la cabeza alcanza la cola
			is_full = 1;
		}
}

uint8_t ring_buffer_read(uint8_t *byte){

	if((is_full != 0) || (head_ptr != tail_ptr)){
			  *byte = ring_buffer[tail_ptr]; //Esto representa la lectura de un byte de datos del buffer.
			  tail_ptr = tail_ptr + 1;
			  if(tail_ptr >= capacity){
				  tail_ptr = 0;

			  }
			  is_full = 0;
			  //uint8_t size = head_ptr - tail_ptr; //head - tail para que se vaya movirndo igual que el buffer
			return 1; //buffer con datos
		  }
	return 0;
}

uint8_t ring_buffer_size(void){
	uint8_t size = 0;
	if(head_ptr > tail_ptr){
		size = head_ptr - tail_ptr;
	}
	else if(head_ptr < tail_ptr){
			size = (capacity - tail_ptr) + (head_ptr);
	}else{
		if(is_full == 1){
			size = capacity -1;
		}else{
			size = 0;
		}
	}

	return size;
}

uint8_t ring_buffer_reset(void) {
    if (is_full) {  // Verifica si el buffer está lleno
        head_ptr = 0;  // Reinicia el puntero de escritura
        tail_ptr = 0;  // Reinicia el puntero de lectura
        is_full = 0;
        return 1;// Resetea la bandera de buffer lleno
    }
    return 0;
}

uint8_t ring_buffer_is_full(void){
	if(is_full){
		return 1;
	}else{
		return 0;
	}
}

uint8_t ring_buffer_empty(void){
	if((head_ptr == 0)&&(tail_ptr == 0)&&(is_full == 0)){
		return 1;
	}else{
	return 0;
	}
}

uint8_t right_ID(uint8_t *data){

	 if (memcmp(data, numberID, sizeof(numberID)) != 0) {
	        return 0;
	    } else {
	       return 1;
	    }


}

