#include <stdint.h>
#include <stdio.h>

#define uint uint32_t

int encrypt(int idx, uint32_t data[]) {
  uint32_t cnt, sum, l, r, i;

  // 初始化 sum 为 0
  sum = 0;

  // 读取 _.v[cnt] 到 l
  l = data[idx];

  // 读取 _.v[cnt + 1] 到 r
  r = data[idx + 1];

  // 初始化 i 为 1
  i = 1;
  const uint _80[5] = {1214346853u, 558265710u, 559376756u, 1747010677u, 1651008801u};   
  // 进入循环
  while (i <= 40) {
    l += ((((((~(r << (uint)(3))) & (r >> (uint)(5))) | ((r << (uint)(3)) & (~(r >> (uint)(5))))) ^ (~r)) & ((r << (uint)(3)) ^ (r >> (uint)(5)))) ^ ((~((~(sum + _80[sum & 4u])) | (~((r >> (uint)(3)) & (r << (uint)(2)))))) & (l | (~l))));
    sum += 1932555628u;
    r += ((((((~(l << (uint)(3))) & (l >> (uint)(5))) | ((l << (uint)(3)) & (~(l >> (uint)(5))))) ^ (~l)) & ((l << (uint)(3)) ^ (l >> (uint)(5)))) ^ ((~((~(sum + _80[(sum >> (uint)(11)) & 4u])) | (~((l >> (uint)(3)) & (l << (uint)(2)))))) & (r | (~r))));
    i++;
  }
  data[idx] = l;
  data[idx + 1] = r;  
}

int decrypt(int idx, uint32_t data[]) {
  
  uint32_t cnt, sum, l, r, i;

  // 初始化 sum 为 0
  sum = 1932555628 * 40;

  // 读取 _.v[cnt] 到 l
  l = data[idx];

  // 读取 _.v[cnt + 1] 到 r
  r = data[idx + 1];

  // 初始化 i 为 1
  i = 40;
  const uint _80[5] = {1214346853u, 558265710u, 559376756u, 1747010677u, 1651008801u};   
  // 进入循环
  while (i >= 1) {
    r -= ((((((~(l << (uint)(3))) & (l >> (uint)(5))) | ((l << (uint)(3)) & (~(l >> (uint)(5))))) ^ (~l)) & ((l << (uint)(3)) ^ (l >> (uint)(5)))) ^ ((~((~(sum + _80[(sum >> (uint)(11)) & 4u])) | (~((l >> (uint)(3)) & (l << (uint)(2)))))) & (r | (~r))));
    sum -= 1932555628u;
    l -= ((((((~(r << (uint)(3))) & (r >> (uint)(5))) | ((r << (uint)(3)) & (~(r >> (uint)(5))))) ^ (~r)) & ((r << (uint)(3)) ^ (r >> (uint)(5)))) ^ ((~((~(sum + _80[sum & 4u])) | (~((r >> (uint)(3)) & (r << (uint)(2)))))) & (l | (~l))));
    i--;
  }
  data[idx] = l;
  data[idx + 1] = r;
}

int main(){
  uint data[] =
    {
      0x185B72AF,
      0x0631D2C6,
      0xDE8B33CC,
      0x31EBCD9F,
      0x05DB8B33,
      0x0A8D77D0,
      0x865C6111,
      0xBF032335,
      0x722228A5,
      0xAD833A57,
      0xB7C3456F,
      0,
    };
  for(uint32_t k = 0;k<=0xffffffff;k++){
    for(uint32_t kk = 0;kk<=0xffffffff;kk++){
      //printf("0x%x 0x%x\n",k,kk);
      uint data2[] =
	{
	  0x185B72AF,
	  0x0631D2C6,
	  0xDE8B33CC,
	  0x31EBCD9F,
	  0x05DB8B33,
	  0x0A8D77D0,
	  0x865C6111,
	  0xBF032335,
	  0x722228A5,
	  0xAD833A57,
	  kk,
	  k,
	};
      encrypt(10, data2);
      if(data2[10] == 0xB7C3456F){
	data[11] = data2[11];
	goto brk;
      }
    }
  }
 brk:
  for(int i = 0;i < 12; i+=2){
    decrypt(i,data);
  }
  for(int i = 0;i < 12;i++){
    for(int j = 0;j < 4;++j){
      putchar((data[i] & (0xff << j * 8)) >> (j * 8));
    }
  }
  putchar('\n');
}

  
/* #version 450 */
/* layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in; */

/* const uint _80[5] = uint[](1214346853u, 558265710u, 559376756u, 1747010677u, 1651008801u); */

/* layout(binding = 0, std430) buffer V */
/* { */
/*     uint v[]; */
/* } _23; */

/* void main() */
/* { */
/*     uint cnt = gl_GlobalInvocationID.x * 2u; */
/*     uint sum = 0u; */
/*     uint l = _23.v[cnt]; */
/*     uint r = _23.v[cnt + 1u]; */
/*     for (int i = 1; i <= 40; i++) */
/*     { */
/*         l += ((((((~(r << uint(3))) & (r >> uint(5))) | ((r << uint(3)) & (~(r >> uint(5))))) ^ (~r)) & ((r << uint(3)) ^ (r >> uint(5)))) ^ ((~((~(sum + _80[sum & 4u])) | (~((r >> uint(3)) & (r << uint(2)))))) & (l | (~l)))); */
/*         sum += 1932555628u; */
/*         r += ((((((~(l << uint(3))) & (l >> uint(5))) | ((l << uint(3)) & (~(l >> uint(5))))) ^ (~l)) & ((l << uint(3)) ^ (l >> uint(5)))) ^ ((~((~(sum + _80[(sum >> uint(11)) & 4u])) | (~((l >> uint(3)) & (l << uint(2)))))) & (r | (~r)))); */
/*     } */
/*     _23.v[cnt] = l; */
/*     _23.v[cnt + 1u] = r; */
/* } */

