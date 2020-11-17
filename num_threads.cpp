#include <stdio.h> //gehört zu der C Standart Bibliothek und vereinbart Ein-/Ausgabefunktionen, Typen und Makros
#include <omp.h>//bietet uns die OpenMP Funktionen (parallel programming)

int main(int argc, char* argv[]){
    int numThreads; //
    int threadID; //speichert die Nummer des jeweiligen Threads
    double start, end; //?

    start = omp_get_wtime(); //?

    /* ? */
    #pragma omp parallel num_threads(4)
    {
        threadID = omp_get_thread_num(); //?
        printf("Hello from thread %d\n", threadID);

        /* ? */
        if(threadID == 0){
            numThreads = omp_get_num_threads(); //?
            printf("Number of threads: %d\n", numThreads);
        }
    }
    end = omp_get_wtime(); //?
    printf("This task took %f seconds\n", end-start);

    return 0;
}