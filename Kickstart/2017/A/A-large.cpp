#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long LL;

#define MODER 1000000007

LL mul(LL a, LL b) {
    LL ans = 0, step = a % MODER;
    while (b) {
        if (b & 1L) ans += step;
        if (ans >= MODER) ans %= MODER;
        step <<= 1L;
        if (step >= MODER) step %= MODER;
        b >>= 1L;
    }
    return ans % MODER;
}

LL sum(LL r, LL c)
{
	/*
	LL t0 = 1LL * mul(r, r-1) / 2;
	LL t1 = (0LL + c + r);
	LL t2 = 1LL * mul(c, r);
	LL ans = 1LL * (mul(t0, t0) - mul(mul(t1, t0), (2*r - 1)) / 3 + mul(t2, t0)) % MODER;
	*/
	//ans = ans < 0LL ? ans + MODER : ans;
	//printf("%lld %lld %lld\n", t0, t1, t2);
	LL ans = 0LL;
	for (int i = 1; i <= r - 1; ++i)
		ans = (ans + i * (c-i) % MODER * (r-i) % MODER) % MODER;

	return ans;
}

int main()
{
	int T;
	int r, c;
	LL ans;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d%d", &r, &c);
		if (r <= c) ans = sum(r, c);
		else ans = sum(c, r);
		printf("Case #%d: %lld\n", i, ans);
	}
	return 0;
}