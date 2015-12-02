#include <dirent.h>
#include <glob.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "commander.h"
#include "libprojectroot.h"

static void weight_mode(command_t* self) {
  weight_mode_on = 1;
}

static void verbose(command_t* self) {
  verbose_on = 1;
}


int main(int argc, char** argv) {
  command_t cmd;
  command_init(&cmd, argv[0], "1.1.2");
  command_option(&cmd, "-t", "--top", "always prefer the topmost artifact", weight_mode);
  command_option(&cmd, "-v", "--verbose", "be chatty", verbose);
  command_parse(&cmd, argc, argv);

  char cwd[1024];

  if(!getcwd(cwd, sizeof(cwd))) {
    fprintf(stderr, "Error: Couldn't get the current working directory\n");
    return 1;
  }

  if(verbose_on) fprintf(stderr, "Finding: looking for root file in %s\n", cwd);

  char* root;

  if(weight_mode_on) {
    root = find_project_root_weighted(cwd);
  } else {
    root = find_project_root(cwd);
  }

  if(root) {
    printf("%s\n", root);
    return 0;
  }

  fprintf(stderr, "Error: Couldn't find the project's root directory\n");
  return 2;
}
