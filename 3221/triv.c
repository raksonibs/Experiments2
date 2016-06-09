// for (int i = 0; i < count; i++) {
  //   printf("*****NEW CHILD PROCESS *******\n");
  //   pid = fork();
  // }

  // fork child process

  // if (pid < 0) {
  //   // error occured
  //   perror("fork() error");
  //   exit(-1);
  // } else if (pid == 0) {
  //   // child processs
  //   printf("\n Hello I am the child process ");
  //   printf("\n My pid is %d \n",getpid());
  //   readFile = argv[internalCount];
  //   internalCount++;
  //   printf("I am going to read %s\n", readFile);
  //   fp = fopen(readFile, "r");
  //    if(fp == NULL) 
  //    {
  //       perror("Error opening file");
  //       return(-1);
  //    }
  //    if( fgets (str, sizeof(str), fp)!=NULL ) 
  //    {
  //       pch = strtok (str," ,.-");
  //       while (pch != NULL)
  //       {
  //         // printf ("%s\n",pch);
  //         current = atof(pch);
  //         if (current > max) {
  //           max = current;
  //         }

  //         if (current < min) {
  //           min = current;
  //         }
  //         pch = strtok (NULL, " ,.-");
  //       }

  //       diff = min - max;
  //       sum = min + max;

  //    }
  //     fclose(fp);
  //     printf("*****END CHILD PROCESS *******\n");
  //     snprintf(buffer, sizeof(buffer), "Filename: %s, sum: %f, diff: %f, max: %f, min: %f\n", readFile, diff, sum, max, min);
  //     // printf("Filename: %s, sum: %f, diff: %f, max: %f, min: %f\n", readFile, diff, sum, max, min);
  //     execl("/bin/echo", "echo", buffer, NULL);
  //   // execlp("/bin/ls", "ls", NULL);
  // } else {
  //   // parent will wait for child to complete
  //   wait(NULL);
  //   printf("YOOWHOOO Child complete\n");
  //   printf("\n Hello I am the parent process ");
  //   printf("\n My actual pid is %d \n ",getpid());
  //   printf("Total stuff here \n");
  // }

  // for (int i = 0; i < count; i++) {
  //   child(i, argv[i+1])
  // }
