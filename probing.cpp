void probing_process(int &int_sum, float &float_sum) {
  MPI_Status status;
  
  // 1- Probe the incoming message
  MPI_Probe(status.MPI_SOURCE, status.MPI_TAG, MPI_COMM_WORLD, &status);
  
  // 2- Get the tag and the source
  int tag = status.MPI_TAG;
  int source = status.MPI_SOURCE;

  // Printing the message
  std::cout << "Received a message from process " << source << " with tag " << tag << std::endl;

  // 3- Add to int_sum or float_sum depending on the tag of the message
  if (tag == 0)
  {
    int int_receive;
    MPI_Recv(&int_receive, 1, MPI_INT, source, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    int_sum += int_receive;
  }
  else if (tag == 1)
  {
    float float_receive;
    MPI_Recv(&float_receive, 1, MPI_FLOAT, source, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    float_sum += float_receive;
  }
}
