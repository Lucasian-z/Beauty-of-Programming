#include <stdio.h>

#define HALF_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_LENGTH)
#define RMASK (FULLMASK >> HALF_LENGTH)
#define RSET(b, n) (b = ((LMASK & b) | n))
#define LSET(b, n) (b = ((RMASK & b) | (n << HALF_LENGTH)))
#define RGET(b) (RMASK & b)
#define LGET(b) ((LMASK & b) >> HALF_LENGTH)
#define ROW 3

int main()
{
    int i = 0;
    for (LSET(i, 1); LGET(i) <= ROW * ROW; LSET(i, (LGET(i) + 1))) {
        for (RSET(i, 1); RGET(i) <= ROW * ROW; RSET(i, (RGET(i) + 1))) {
            if (LGET(i) % ROW != RGET(i) % ROW) {
                printf("A = %d, B = %d\n", LGET(i), RGET(i));
            }
        }
    }
    return 0;
}
