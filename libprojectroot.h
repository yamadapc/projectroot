#include <dirent.h>
#include <glob.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N_CANDIDATES 26
#define BUFFER_SIZE 1024

extern int weight_mode_on;
extern int verbose_on;

int is_project_root(char* cdt);
char* find_project_root_weighted(char* cwd);
char* find_project_root(char* cwd);
