#include <stdio.h>
#include <stdlib.h>

#include "CircularQueue.h"

int main() {
	CircularQueue *queue;
	
	queue_init(&queue, 10);
	
	printf("Inserting 1...\n");
	queue_put(queue, 1);
	
	printf("Inserting 2...\n");
	queue_put(queue, 2);
	
	printf("Inserting 5...\n");
	queue_put(queue, 5);
	
	printf("Inserting 4...\n");
	queue_put(queue, 4);
	
	printf("Inserting 3...\n");
	queue_put(queue, 3);
	
	unsigned int val1 = (unsigned int) queue_get(queue);
	unsigned int val2 = (unsigned int) queue_get(queue);
	unsigned int val3 = (unsigned int) queue_get(queue);
	unsigned int val4 = (unsigned int) queue_get(queue);
	unsigned int val5 = (unsigned int) queue_get(queue);
	
	printf("Value 1: %d\nValue 2: %d\nValue 3: %d\nValue 4: %d\nValue 5: %d\n", val1, val2, val3, val4, val5);
	
	queue_destroy(queue);
	
	return EXIT_SUCCESS;
}