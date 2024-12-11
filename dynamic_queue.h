#pragma once
#include "struct_queue.h"


typedef void* Pointer;

void queue_create(Queue* pqueue);

void queue_destroy(Queue* pqueue);

void queue_enqueue(Queue* pqueue, Pointer value);

size_t queue_size(Queue* pqueue);

Pointer queue_dequeue(Queue* pqueue);

Pointer queue_peek(Queue* pqueue);