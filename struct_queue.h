#pragma once


typedef struct tQueue {
	void** data;
	int head;
	int tail;
	int size;
	int current_capacity;
} Queue;