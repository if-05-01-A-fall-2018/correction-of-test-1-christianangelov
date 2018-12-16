#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char* args[4] = {"ls","df","ps","pwd"};
char* mod[2] = {" ", 0};


int main(int argc, char const *argv[]) {


  printf("Fork ls thread\n");
  pid_t pid_ls = fork();
  if(pid_ls == 0){
    mod[0] = args[0];

    execvp(args[0],mod);
  }

  printf("Fork df thread\n");
  pid_t pid_df = fork();
  if(pid_df == 0){
    mod[0] = args[1];
    execvp(args[1],mod);
  }


  printf("Fork ps thread\n");
  pid_t pid_ps = fork();
  if(pid_ps == 0){
    mod[0] = args[2];
    execvp(args[2],mod);
  }


  printf("Fork pwd thread\n");
  pid_t pid_pwd = fork();
  if(pid_pwd == 0){
    mod[0] = args[3];
    execvp(args[3],mod);
  }



  if(pid_ls != 0||pid_df != 0||pid_ps != 0||pid_pwd != 0){
    printf("Wait to finish!\n");
  }




  waitpid(-1,0,0);
  waitpid(-1,0,0);
  waitpid(-1,0,0);
  waitpid(-1,0,0);

  printf("Finished\n");

  return 0;
}
