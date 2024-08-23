/*
 * ring_buffer.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Paulina Ruíz
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_

#include <stdint.h>
#include <string.h>
void ring_buffer_write(uint8_t data);
uint8_t ring_buffer_read(uint8_t *byte);

uint8_t ring_buffer_reset();
uint8_t ring_buffer_empty(void);
uint8_t ring_buffer_size(void);
uint8_t ring_buffer_is_full(void);
uint8_t right_ID(uint8_t *data);

#endif /* INC_RING_BUFFER_H_ */
