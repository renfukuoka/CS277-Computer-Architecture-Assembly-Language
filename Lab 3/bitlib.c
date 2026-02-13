#include <stdio.h>

/*
 * bitwise_nor  - implement ~(x | y) using only ~ and &.
 * Example biwise_nor(6, 5) = 0xFFFFFFF8
 * Max. # of operators: 8
 */
int bitwise_nor(int x, int y)
{
    return (~x & ~y);
}

/*
 * bitwise_xor - implement (x ^ y) using only ~ and &.
 * Example bitwise_xor(4, 5) = 0x1
 * Max. # of operators: 14
 */
int bitwise_xor(int x, int y)
{
    return (~(~(~x & y) & ~(x & ~y)));
}

/*
 * eval_not_equal - implement (x != y)
 * using only !, ~, &, |, ^, +, << and >>,
 * returns 0 if x == y, otherwise 1.
 * Examples: eval_not_equal(2, 2) = 0, eval_not_equal(3, 4) = 1
 * Max. # of operators: 6
 */
int eval_not_equal(int x, int y)
{
    return !!(x ^ y);
}

/*
 * get_byte - extract byte n from 32-bit integer x
 * using only !, ~, &, |, ^, +, << and >>,
 * do not use any constant values of more than 1 byte in size,
 * assume ordering as 0 = least significant byte, 3 = most significant byte.
 * Example: get_byte(0x12345678, 1) = 0x56
 * Max. # of operators: 6
 */
int get_byte(int x, int n)
{
    return (x >> (n << 3)) & 0xFF;
}

/*
 * copy_lsbit - set all bits of result value to the least significant bit of x
 * using only !, ~, &, |, ^, +, << and >>,
 * do not use any constant values of more than 1 byte in size. 0xFF
 * Examples: copy_lsbit(5) = 0xFFFFFFFF, copy_lsbit(8) = 0x0
 * Max. # of operators: 5
 */
int copy_lsbit(int x)
{
    return ~(x & 0x1) + 1;
}

/*
 * rightmost - return the rightmost bit set of x or 0 if x is equal to
 * 0 using only !, ~, &, |, ^, +, *, -, << and >>.
 * Examples: rightmost(0) = 0x0, righmost(1) = 0x1, rightmost(7) = 0x1,
 * rightmost(2) = 0x2, rightmost(16) = 0x10, rightmost(32) = 0x20
 * Max. # of operators: 5
 */
int rightmost(int x)
{
    return x & -x;
}

/*
 * bit_count - returns the # of bits in x that are 1
 * using only !, ~, &, |, ^, +, << and >>,
 * do not use any constant values of more than 1 byte in size.
 * Examples: bit_count(2) = 1, bit_count(10) = 2, bit_count(7) = 3
 * Max. # of operators: 40
 */
int bit_count(int x)
{
    int s1m16 = (0x55 << 8) | 0x55;
    int s1m32 = s1m16 | (s1m16 << 16);
    int s2m16 = (0x33 << 8) | 0x33;
    int s2m32 = s2m16 | (s2m16 << 16);
    int s3m16 = (0x0F << 8) | 0x0F;
    int s3m32 = s3m16 | (s3m16 << 16);
    int s4m16 = (0xFF << 8) | 0xFF;
    int s4m32 = s4m16 | (s4m16 << 16);
    int stage1 = (x & s1m32) + ((x >> 1) & s1m32);
    int stage2 = (stage1 & s2m32) + ((stage1 >> 2) & s2m32);
    int stage3 = (stage2 & s3m32) + ((stage2 >> 4) & s3m32);
    int stage4 = (stage3 & s4m32) + ((stage3 >> 8) & s4m32);
    int stage5 = (stage4 & s4m32) + ((stage4 >> 16) & s4m32);

    return stage5;
}
