#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamic_queue.h"



void queue_create(Queue* pqueue) {
	pqueue->size = 10;
	pqueue->data = malloc(sizeof(void*) * pqueue->size);
	if (pqueue->data == NULL) {
		printf("Не удалось выделить память");
		exit(1);
	}
	pqueue->head = 0;
	pqueue->tail = 0;
	pqueue->current_capacity = 0;
}

void queue_destroy(Queue* pqueue){
	free(pqueue->data);
	pqueue->size = 0;
	pqueue->head = 0;
	pqueue->tail = 0;
	pqueue->current_capacity = 0;
	pqueue->data = NULL;
}

void queue_enqueue(Queue* pqueue, Pointer value) {

	if (pqueue->current_capacity == pqueue->size) {
		void** new_data = malloc(sizeof(void*) * pqueue->size * 2);
		if (new_data == NULL) {
			printf("Не удалось выделить память");
			exit(1);
		}

		if (pqueue->tail < pqueue->head) {
			memcpy(new_data, pqueue->data + pqueue->head, (pqueue->size - pqueue->head) * sizeof(void*));
			memcpy(new_data + (pqueue->size - pqueue->head), pqueue->data, pqueue->tail * sizeof(void*));
			pqueue->tail = pqueue->size;
		}
		else {
			memcpy(new_data, pqueue->data, pqueue->size * sizeof(void*));
		}
		free(pqueue->data);
		pqueue->size *= 2;
		pqueue->data = new_data;
	}

	pqueue->data[pqueue->tail] = value;
	pqueue->tail++;
	pqueue->current_capacity++;

	if (pqueue->current_capacity != pqueue->size && pqueue->tail == pqueue->size) {
		pqueue->tail = 0;
	}
}

size_t queue_size(Queue* pqueue) {
	return pqueue->current_capacity;
}

Pointer queue_dequeue(Queue* pqueue) {

	if (pqueue->current_capacity == 0) {
		return NULL;
	}

	void* value = pqueue->data[pqueue->head];

	pqueue->head++;
	pqueue->current_capacity--;

	if (pqueue->current_capacity != pqueue->size && pqueue->head == pqueue->size) {
		pqueue->head = 0;
	}

	return value;
}

Pointer queue_peek(Queue* pqueue) {
	return pqueue->current_capacity == 0 ? NULL : pqueue->data[pqueue->head];
}




