#include<stdio.h>
#include<time.h>
#include<math.h>

#include<dirent.h>

#include "raylib.h"

const char* musicPath = "./Music";

int main(void) {
  SetConfigFlags(FLAG_VSYNC_HINT);
  
  InitWindow(100, 100, "rlclock");

  InitAudioDevice();

  // Directory to open
  DIR* musicDir = opendir(musicPath);

  // Position in the directory
  struct dirent* dirPos;

  // List all files in directory until end
  while ((dirPos = readdir(musicDir)) != NULL) {
    printf("%s\n", dirPos->d_name);
  }

  /*while(!WindowShouldClose()) {

    
    }*/

  //Always close directory or we will segfault
  closedir(musicDir);
  return 0;
}
