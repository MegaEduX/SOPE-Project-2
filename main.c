#include <stdio.h>
#include <stdlib.h>

#include "CircularQueue.h"

CircularQueue* create_all_numbers_queue(int max) {
	CircularQueue *queue;
	
	queue_init(&queue, max + 2);
	
	int i;
	
	for (i = 2; i <= max; i++)
		queue_put(queue, i);
	
	queue_put(queue, 0);
	
	return queue;
}

int main() {
	CircularQueue *queue = create_all_numbers_queue(10);
	
	unsigned int val1 = (unsigned int) queue_get(queue);
	unsigned int val2 = (unsigned int) queue_get(queue);
	unsigned int val3 = (unsigned int) queue_get(queue);
	unsigned int val4 = (unsigned int) queue_get(queue);
	unsigned int val5 = (unsigned int) queue_get(queue);
	
	printf("Value 1: %d\nValue 2: %d\nValue 3: %d\nValue 4: %d\nValue 5: %d\n", val1, val2, val3, val4, val5);
	
	queue_destroy(queue);
	
	return EXIT_SUCCESS;
}