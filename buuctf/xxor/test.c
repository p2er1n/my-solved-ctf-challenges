#include <stdint.h>
#include <stdio.h>

int main(){
  int a = -0x20b71082;
  uint32_t b =  -0x20b71082;
  printf("0x%x, 0x%x\n", a,b);
  a >>= 9;
  b >>= 9;
  printf("0x%x, 0x%x\n", a,b);
  return 0;
}
