#include <iostream>
#include <mpi.h>
using namespace std;

int MPI_Init(int *argc, char ***argv);

int MPI_Finalize();

int main(int argc, char** argv) {
  // Initialisation
  MPI_Init(&argc, &argv);

  int size, rank;
  
  // Reading size and rank
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  // Printing
  cout << "Hello world, from process #" << rank << endl;
  
  // Finalisation
  MPI_Finalize();

  return 0;
}


