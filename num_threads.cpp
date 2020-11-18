#include <stdio.h> //gehört zu der C Standart Bibliothek und vereinbart Ein-/Ausgabefunktionen, Typen und Makros
#include <omp.h>//bietet uns die OpenMP Funktionen (parallel programming)

int main(int argc, char* argv[]){
    int numThreads; //speichert die Anzahl der Threads(Integer)
    int threadID; //speichert die Nummer des jeweiligen Threads(Integer)
    double start, end; //speichert Start-und Endzeit (einen double-Wert)
    printf("start: %f\n",start);
    start = omp_get_wtime(); //start speichert verstrichene Uhrzeit in Sekunden
    printf("start: %f\n",start);
    /*
    parallel definiert Bereich im Code, der parallel von mehreren Threads ausgeführt wird
    num_threads legt Thread-Anzahl in einem Thread-Team fest
    Somit wird Anzahl an Threads festgelegt und paralleler Bereich definiert.
    https://docs.microsoft.com/de-de/cpp/parallel/openmp/reference/openmp-directives?view=msvc-160#parallel
     */
    #pragma omp parallel num_threads(4)
    {
        threadID = omp_get_thread_num(); //in threadID wird die Anzahl des jeweiligen threads gespeichert
        printf("Hello from thread %d\n", threadID);

        /*
        der if statement sorgt dafuer das die anzahl an threads nur ausgegeben wird, sobald der master thread es erreicht, somit
        wird dieser bereich des codes nur einmal insgesammt durchgefuehrt, und nicht einmal pro thread anders als der obrige teil*/
        if(threadID == 0){
            numThreads = omp_get_num_threads(); //speichert die insgesammtanzahl an Threads in die variable numThreads
            printf("Number of threads: %d\n", numThreads);
        }
    }
    end = omp_get_wtime(); //end speichert verstrichene Uhrzeit in Sekunden
    printf("start: %f\n",start);
    printf("end: %f\n",end);
    printf("This task took %f seconds\n", end-start);

    return 0;
}