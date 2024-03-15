#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
char input[MAX_LEN];
char output[MAX_LEN];

int idx = 0;

char table[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0987654321/+";

int main(){
  scanf("%s", input);
  int len = strlen(input);
  for(int i = 0;i < len/3; i++){
    char c = input[i*3];
    char cc = table[(int)c >> 2];//get the six higher bits
    output[idx++] = cc;

    c = input[i*3];
    cc = input[i*3+1];
    cc = table[(int)cc >> 4 | ((int)c & 0b11) << 4];
    output[idx++] = cc;

    c = input[i*3+1];
    cc = input[i*3+2];
    cc = table[(int)cc >> 6 | (int)(c & 0xfU) * 4];
    output[idx++] = cc;

    c = input[i*3+2];
    cc = table[(int)c & 0b111111];
    output[idx++] = cc;
  }
  if(len % 3 == 1){
    int i = len/3 * 3;
    char c = input[i];
    c = table[(int)c >> 2];
    output[idx++] = c;

    c = input[i];
    c = table[((int)c & 0b11U) << 4];
    output[idx++] = c;
    output[idx++] = '=';
    output[idx++] = '=';
  }
  else if(len % 3 == 2){
    int i = len/3 * 3;
    char c = input[i];
    c = table[(int)c >> 2];
    output[idx++] = c;

    c = input[i];
    char cc = input[i+1];
    c = table[(int)cc >> 4 | ((int)c & 3U) << 4];
    output[idx++] = c;

    c = input[i+1];
    c = table[((int)c & 0xfU) << 2];
    output[idx++] = c;

    output[idx++] = '=';
  }
  output[idx++] = '\0';

  printf("%s\n", output);
  return 0;
}
