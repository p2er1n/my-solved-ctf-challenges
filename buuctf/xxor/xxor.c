#include <stdio.h>
#include <stdint.h>

int enc[6] = {
  -0x20b71082,
  0x20caacf4,
  -520941611,
  1548802262,
  -1642340819,
  -0x7b0cfbe0,
};

uint32_t key[4] = {
  0x00000002,  
  0x00000002,  
  0x00000003,  
  0x00000004
};

void decrypt(int* i1, int* i2){
  uint32_t input1 = *i1; //have to be uint32_t !
  uint32_t input2 = *i2;
  uint32_t sum_ = 0x458bcd42 * 64;
  for(int i=63;i >= 0;i--){
    input2 -= (key[3] + (input1 >> 9) ^ input1 * 0x40 + key[2] ^ sum_ + input1 + 0x14 ^ 0x10);
    input1 -= (key[1] + (input2 >> 9) ^ input2 * 0x40 + key[0] ^ sum_ + input2 + 0xb ^ 0x20);
    sum_ -= 0x458bcd42;
  }
  *i1 = input1;
  *i2 = input2;
}

int main(){
  for(int i = 0;i < 6;i+=2){
    decrypt(&enc[i], &enc[i+1]);
  }
  for(int i = 0;i < 6;++i){
    for(int j = 3;j >= 0;--j){
      char c = ((char*)&enc[i])[j];
      printf("%c", c);
    }
  }
  
  return 0;
}
