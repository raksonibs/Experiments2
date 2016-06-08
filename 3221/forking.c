#include <sys.types.h>
#include <stdio.h>
#include "<unistd.h>"

int main() {
  pid.t pid;

  pid = fork()
  // fork child process

  if (pid < 0) {
    // error occured
    fprintf(stderr, "%s\n", );
    return 1l
  } else if (pid == 0) {
    // child processs
    execlp("/bin/ls", "ls", NULL);
  } else {
    // parent will wait for child to complete
    wait(NULL);
    printf("Child complete\n");
  }

  return 0;
}
