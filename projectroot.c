#include <dirent.h>
#include <libgen.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define N_CANDIDATES 2

static const char* const candidates[] = {
  ".git",
  ".hg",
  ".fslckout",
  ".bzr",
  "_darcs",
  ".svn",
  "CVS",
  "rebar.config",
  "project.clj",
  "SConstruct",
  "pom.xml",
  "build.sbt",
  "build.gradle",
  "Gemfile",
  "requirements.txt",
  "tox.ini",
  "package.json",
  "gulpfile.js",
  "Gruntfile.js",
  "bower.json",
  "composer.json",
  "Cargo.toml",
  ".cabal-sandbox",
  "*.cabal",
  "mix.exs",
};

int is_project_root(char* cdt) {
  DIR *dir = opendir(cdt);
  struct dirent *ent;

  if(dir != NULL) {
    while((ent = readdir(dir))) {
      for(int i = 0; i < N_CANDIDATES; i++) {
        if(strcmp(ent->d_name, candidates[i]) == 0) return 1;
      }
    }
  }

  return 0;
}

char* find_project_root(char* cwd) {
  char* cdt = cwd;

  while(strcmp(cdt, "/") != 0) {
    if(is_project_root(cdt)) return cdt;
    cdt = dirname(cdt);
  }

  return NULL;
}

int main() {
  char cwd[1024];

  if(!getcwd(cwd, sizeof(cwd))) {
    printf("Error: Couldn't get the current working directory\n");
    return 1;
  }

  char* root = find_project_root(cwd);

  if(root) {
    printf("%s\n", root);
    return 0;
  }

  printf("Error: Couldn't find the project's root directory\n");
  return 2;
}
