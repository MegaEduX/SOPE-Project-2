#!/bin/sh

rm sope2

gcc CircularQueue.c main.c -g -pthread -lm -lrt -o sope2 -Wall
