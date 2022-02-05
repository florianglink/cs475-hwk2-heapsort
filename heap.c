/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	//TODO - BuildHeap on the list
	
	//TODO - while n > 0:
		//TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		//TODO - A[n-1] now sorted in place!
		//TODO - So decrement n
		//TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
		while(n>0){
			struct Employee *e1;
			struct Employee *e2;
			*e1 = A[n-1];
			*e2 = A[0];
			swap(e1, e2);
			n--;
			for(int i=0; i<(n-1); i++){
				heapify(A, i, n);
			}
		}
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	for(int i=0; i<floor(n/2); i++) {
		heapify(A, i, n);
	}
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	//TODO - get index of left child of element i
	//TODO - get index of right child of element i

	//TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"

	//TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	//TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
	int leftChild;
	int rightChild;
	int smaller;
	struct Employee *ptr1;
	struct Employee *ptr2;
	if(2*i+1 < n) leftChild = 2*i+1;
	if(2*i+2 < n) rightChild = 2*i+2;
	if(leftChild >= n && rightChild >= n) return;
	if(leftChild >= n) leftChild = rightChild;
	if(rightChild >= n) rightChild = leftChild;
	
	if(leftChild < rightChild){
		smaller = leftChild;
	}
	else {
		smaller = rightChild;
	}

	if(A[i].salary > A[smaller].salary){
		A[i] = *ptr1;
		A[smaller] = *ptr2;
		swap(ptr1, ptr2);
		heapify(A, smaller, n);
	}

}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{
	struct Employee *smallest;
	*smallest = A[0];
	for(int i=1; i<n; i++){
		if(A[i].salary < smallest->salary) {
			*smallest = A[i];
		}
	}
	return smallest;
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	struct Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;

}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	for(int i=0; i<n; i++) {
		printf("\nEmployee %u:\n", i+1);
		printf("Name: %s\n", A[i].name);
		printf("Salary: %u\n", A[i].salary);
	}
}
