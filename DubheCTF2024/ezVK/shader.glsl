#version 450
layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;

const uint _80[5] = uint[](1214346853u, 558265710u, 559376756u, 1747010677u, 1651008801u);

layout(binding = 0, std430) buffer V
{
    uint v[];
} _23;

void main()
{
    uint cnt = gl_GlobalInvocationID.x * 2u;
    uint sum = 0u;
    uint l = _23.v[cnt];
    uint r = _23.v[cnt + 1u];
    for (int i = 1; i <= 40; i++)
    {
        l += ((((((~(r << uint(3))) & (r >> uint(5))) | ((r << uint(3)) & (~(r >> uint(5))))) ^ (~r)) & ((r << uint(3)) ^ (r >> uint(5)))) ^ ((~((~(sum + _80[sum & 4u])) | (~((r >> uint(3)) & (r << uint(2)))))) & (l | (~l))));
        sum += 1932555628u;
        r += ((((((~(l << uint(3))) & (l >> uint(5))) | ((l << uint(3)) & (~(l >> uint(5))))) ^ (~l)) & ((l << uint(3)) ^ (l >> uint(5)))) ^ ((~((~(sum + _80[(sum >> uint(11)) & 4u])) | (~((l >> uint(3)) & (l << uint(2)))))) & (r | (~r))));
    }
    _23.v[cnt] = l;
    _23.v[cnt + 1u] = r;
}

