#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "CircularQueue.h"

void _queue_rot(CircularQueue *q);	//	Prototype.

void queue_init(CircularQueue **q, unsigned int capacity) { 
	*q = (CircularQueue *) malloc(sizeof(CircularQueue)); 
	sem_init(&((*q)->empty), 0, capacity); 
	sem_init(&((*q)->full), 0, 0); 
	pthread_mutex_init(&((*q)->mutex), NULL); 
	(*q)->v = (QueueElem *) malloc(capacity * sizeof(QueueElem)); 
	(*q)->capacity = capacity;
	(*q)->first = 0; 
	(*q)->last = 0;
} 

void queue_put(CircularQueue *q, QueueElem value) {
	sem_wait(&(q->empty));	//	Proceeds if a value can be placed, blocks if not.
	
	(q->v)[q->last] = value;
	
	q->last++;
	
	sem_post(&(q->full));
}

void _queue_rot(CircularQueue *q) {
	unsigned int i, j;
	
	for (i = 0, j = 1; i < q->last; i++, j++)
		(q->v)[i] = (q->v)[j];
	
	(q->v)[j] = 0;
}

QueueElem queue_get(CircularQueue *q) { 
	sem_wait(&(q->full));
	
	QueueElem val = (q->v)[q->first];
	
	_queue_rot(q);
	
	q->last--;
	
	sem_post(&(q->empty));
	
	return val;
} 

void queue_destroy(CircularQueue *q) {
	free(q->v);	//	Free the underlaying array
	free(q);		//	Free the queue itself
}