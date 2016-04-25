#include "bibtareas.h"
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

static struct RangoTiempo {
  RangoTiempo() : min(0),
		  max(0) { }
  RangoTiempo(int min, int max) : min(min),
				  max(max) { }
  int min;
  int max;
} at[3][2] { { RangoTiempo(1,5), RangoTiempo(3,10) },
             { RangoTiempo(20,30), RangoTiempo(15,40) },
	     { RangoTiempo(45,65), RangoTiempo(50,70) }};

static
void loadTareas(void) {
  char *filename = ::getenv("CFG_TAREAS");
  RangoTiempo atf[3][2];

  if (!filename) return;
  
  std::ifstream input(filename);
  
  if (!input) return;
  
  int j = 0;
  for (int i = 0, k = 0; i < 6; ++i) {
    
    input >> atf[i][k].min >> atf[i][k].max;
    
    if (!input) {
      input.close();
      return;
    }
    
    j += 2;
    k = (k + 1) % 2;
  }

  input.close();
    
  if (j != 12) return;

  for (int i = 0; i < 6; ++i) {
    
    at[i][0] = atf[i][0];
    at[i][1] = atf[i][1];
  }
    
  return;
}

void
ejecutarTarea(tarea_t tipo, terminacion_t valor) {

  loadTareas();
  
  int diff = at[tipo][valor].max - at[tipo][valor].min + 1;

  srand(time(0));
  sleep(rand() % diff + at[tipo][valor].min);
  
  exit(valor);
}
