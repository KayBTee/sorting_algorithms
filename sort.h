#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include<stdio.h>
/**
 *struct listint_s - Doubly linked list node
 *
 *@n: Integer stored in the node
 *@prev: Pointer to the previous element of the list
 *@next: Pointer to the next element of the list
 *
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void make_merge(int *array, int *temp, int begin, int middle, int end);
void sort_merge(int array[], int first, int size, int asc);
void merge_asc(int *array, int *temp, int begin, int end);
void merge_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void change_swap(int *array, ssize_t item1, ssize_t item2);
int re_partition(int *array, ssize_t first, ssize_t last, size_t size);
void custom_quick(int *array, ssize_t first, ssize_t last, int size);
listint_t *my_node_swap(listint_t *node, listint_t **list);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void shell_sort(int *array, size_t size);
void int_swaper(int *array, int intOne, int intTwo);
void cocktail_sort_list(listint_t **list);
listint_t *change_node_position(listint_t *node, listint_t **list);
int hoare_part(int *array, int first, int last, int size);
void int_swaper4(int *array, ssize_t item1, ssize_t item2);
void counting_sort(int *array, size_t size);
void *my_calloc(unsigned int members, unsigned int size);
void int_swaper2(int *a, int *b);
void Heapify_max(int *array, size_t size, int index, size_t n);
int max_value(int *arr, int n);
void sort_count(int *array, size_t n, int expo, int *output);
void radix_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void heap_sort(int *array, size_t size);
void int_swaper3(int array[], int item1, int item2, int ord);
void sort_bit(int array[], int first, int items, int size);
void bitonic_sort(int *array, size_t size);
#endif
