#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv)) { 
	return -1;
	}
 else {
	chdir(argv[1]);
 	return 0;
	}
}

int do_pwd(int argc, char** argv) {
char pwd[8096];

  if (!validate_pwd_argv(argc, argv))
    return -1;
  else{
	getcwd(pwd, 8096);
	printf("%s\n", pwd);
}
  return 0;
}

int validate_cd_argv(int argc, char** argv) {//err=0,noterr=1
	 if(argc < 2) {//is err
		return 0;
	} else {
		return 1;
	}
}

int validate_pwd_argv(int argc, char** argv) {
	if(argc != 1) {//is err
		return 0;
	} else {
		return 1;
	}
}
