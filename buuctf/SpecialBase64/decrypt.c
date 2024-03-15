#include <stdio.h>
#include <string.h>

char table[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0987654321/+";


int find(char t[], int l, char c){
  for(int i = 0;i < l;++i){
    if(t[i] == c){
      return i;
    }
  }
  return l;
}

unsigned char res[1000];

int tl;

//char s[100];

int main(){
  tl = strlen(table);
  char s[] = "mTyqm7wjODkrNLcWl0eqO8K8gc1BPk1GNLgUpI==";
  //scanf("%s", s);
  int len = strlen(s);
  for(int i = 0;i < len;i+=4){
    char c[4];
    for(int j=0;j < 4;++j){
      c[j] = s[i+j];
    }
    unsigned char b[4];
    for(int j = 0;j < 4;++j){
      int ret = find(table, tl, c[j]);
      if(ret == tl){
	ret = 0;
      }
      b[j] = (unsigned char)ret;
    }
    unsigned char rb1, rb2, rb3;
    rb1 = b[0]<<2 | b[1]>>4;
    rb2 = ((b[1]&0xf)<<4) | b[2]>>2;
    rb3 = b[3] | ((b[2]&0b11) << 6);
    printf("%c%c%c", rb1, rb2, rb3);
  }
}
