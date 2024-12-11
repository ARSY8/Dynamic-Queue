#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamic_queue.h"
#include "struct_queue.h"


void test_queue(void) {
    Queue q;
    queue_create(&q);

    assert(q.data != NULL);
    assert(q.size == 10);
    assert(q.current_capacity == 0);
    assert(q.head == 0);
    assert(q.tail == 0);

    for (int i = 0; i < 15; i++) {
        int* val = malloc(sizeof(int));
        if (val == NULL) {
            printf("ошибка выделения памяти");
            exit(1);
        }
        *val = i;
        queue_enqueue(&q, val);
    }

    assert(q.size == 20);

    int* peek1 = (int*)queue_peek(&q);
    assert(*peek1 == 0);

    for (int i = 0; i < 15; i++) {
        int* deq = (int*)queue_dequeue(&q);
        assert(*deq == i);
        free(deq);
    }

    assert(queue_size(&q) == 0);

    queue_destroy(&q);

    assert(q.data == NULL);
    assert(q.size == 0);
    assert(q.current_capacity == 0);
    assert(q.head == 0);
    assert(q.tail == 0);

    printf("все тесты пройдены");
}