#include <locale.h>
#include <wchar.h>
#include "printf.h"

int main()
{
  setlocale(LC_ALL, "en_US.UTF-8");
  wchar_t i = L'Ы';
  printf("i = %C\n", i);

  int k = i;
  printf("k = %d\n", i);
  return(0);
}
