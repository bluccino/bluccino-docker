//==============================================================================
//  ec.c - echo with coloring
//
//  Created by Hugo Pristauz on 2023-03-04
//  Copyright © 2023 Bluenetics GmbH. All rights reserved.
//==============================================================================

  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>

//==============================================================================
// ANSI color sequences
//==============================================================================

  #define ANSI_R     "\x1b[31m"        // red
  #define ANSI_G     "\x1b[32m"        // green
  #define ANSI_Y     "\x1b[33m"        // yellow
  #define ANSI_B     "\x1b[34m"        // blue
  #define ANSI_M     "\x1b[35m"        // magenta
  #define ANSI_C     "\x1b[36m"        // cyan
  #define ANSI_0     "\x1b[0m"         // reset

//==============================================================================
// usage
//==============================================================================

  static void usage(const char *name)
  {
    int n = strlen(name);
    for (int i=n-1; i; i--)
    {
      if (name[i]=='/' || name[i] == '\\')
      {
        name = name + i+1;
      }
    }

    fprintf(stderr,"  usage: %s ...     # (uncolored) echo ...\n",name);
    fprintf(stderr,"         %s -r ...  # (red)\n",name);
    fprintf(stderr,"         %s -g ...  # (green)\n",name);
    fprintf(stderr,"         %s -y ...  # (yellow)\n",name);
    fprintf(stderr,"         %s -b ...  # (blue)\n",name);
    fprintf(stderr,"         %s -m ...  # (magenta)\n",name);
    fprintf(stderr,"         %s -c ...  # (cyan)\n",name);

    exit(1);
  }

//==============================================================================
// echo
//==============================================================================

  static void echo(int argc, char **argv, const char *col)
  {
    const char *sep = "";

    fprintf(stdout,"%s",col);
    for (int i=0; i < argc; i++,sep=" ")
       fprintf(stdout,"%s%s",sep,argv[i]);
    fprintf(stdout, *col ? ANSI_0 "\n" : "\n");
  }

//==============================================================================
// main function
//==============================================================================

  int main(int argc, char **argv)
  {
    if (argc <= 1)
    {
      fprintf(stdout,"\n");
      return 0;
    }

    const char *opt = argv[1];
    if (!strcmp(opt,"-r"))
      echo(argc-2,argv+2,ANSI_R);
    else if (!strcmp(opt,"-g"))
      echo(argc-2,argv+2,ANSI_G);
    else if (!strcmp(opt,"-y"))
      echo(argc-2,argv+2,ANSI_Y);
    else if (!strcmp(opt,"-b"))
      echo(argc-2,argv+2,ANSI_B);
    else if (!strcmp(opt,"-c"))
      echo(argc-2,argv+2,ANSI_C);
    else if (!strcmp(opt,"-m"))
      echo(argc-2,argv+2,ANSI_M);
    else if (opt[0] == '-')
      usage(argv[0]);
    else
      echo(argc-1,argv+1,"");

    return 0;
  }
