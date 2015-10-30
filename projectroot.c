#include <dirent.h>
#include <libgen.h>
#include <unistd.h>
#include <stdio.h>
#include <glob.h>
#include <string.h>

#define N_CANDIDATES 26

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
  "node_modules",
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
  char pattern[1024];
  glob_t res;
  size_t cdt_size = strlen(cdt);

  strcpy(pattern, cdt);
  strcat(pattern, "/");

  for(int i = 0; i < N_CANDIDATES; i++) {
    strcat(pattern, candidates[i]);
    if(glob(pattern, GLOB_NOSORT, NULL, &res) == 0) {
      return 1;
    }
    pattern[cdt_size + 1] = 0;
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
    fprintf(stderr, "Error: Couldn't get the current working directory\n");
    return 1;
  }

  char* root = find_project_root(cwd);

  if(root) {
    printf("%s\n", root);
    return 0;
  }

  fprintf(stderr, "Error: Couldn't find the project's root directory\n");
  return 2;
}
