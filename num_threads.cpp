#include <stdio.h> //gehört zu der C Standart Bibliothek und vereinbart Ein-/Ausgabefunktionen, Typen und Makros
#include <omp.h>//bietet uns die OpenMP Funktionen (parallel programming)

int main(int argc, char* argv[]){
    int numThreads; //speichert die Anzahl der Threads(Integer)(funktioniert komischerweise nicht immer)
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
        threadID = omp_get_thread_num(); //in threadID wird die Anzahl der Threads insgesammt gespeichert
        printf("Hello from thread %d\n", threadID);

        /*
        if gibt and ob Schleife parallel oder seriell ausgeführt werden soll
        d.h. wenn unsere Threads-Nummer == 0 (also alle Threads durchgelaufen sind)
        soll die Anzahl der Threads ausgegeben werden
        https://docs.microsoft.com/de-de/cpp/parallel/openmp/reference/openmp-directives?view=msvc-160#parallel*/
        if(threadID == 0){
            numThreads = omp_get_num_threads(); //?
            printf("Number of threads: %d\n", numThreads);
        }
    }
    end = omp_get_wtime(); //end speichert verstrichene Uhrzeit in Sekunden
    printf("start: %f\n",start);
    printf("end: %f\n",end);
    printf("This task took %f seconds\n", end-start);

    return 0;
}