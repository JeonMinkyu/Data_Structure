#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

void random(int arr[]);
void BubbleSort(int * arr, int n); //����
void merge(int arr[],int left, int mid, int right);//�� �迭 ��ġ��
void MergeSort(int arr[], int left, int right);//�պ�
void RadixSort(int*arr, int n);//���
void sorted(int arr[]); //���
