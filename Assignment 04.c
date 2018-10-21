#include <stdio.h>
#include <pthread.h> 
#define MAX 1000 
#define MAX_THREAD 10 

    int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220, 330, 390, 400, 512,12,121,121,21,3131,1314212,445,446,65 }; 
    int sum[10] = { 0 }; 
    int part = 0;
void* sum_array(void* arg) 
{ 
	int thread_part = part++; 
	for (int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++) 
		sum[thread_part] += a[i]; 
} 
int main() 
{ 
	pthread_t threads[MAX_THREAD]; 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 
    for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL); 
    
    int total_sum = 0; 
	
	for (int i = 0; i < MAX_THREAD; i++) 
		total_sum += sum[i]; 
		
	printf ("Sum is ");
	printf("%d\n", total_sum); 
	
	return 0; 
} 