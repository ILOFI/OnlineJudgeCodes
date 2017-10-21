#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long LL;

#define MODER 1000000007

LL sum(int r, int c)
{
	LL ans = 0LL;
	for (int i = 1; i <= r - 1; ++i)
		ans = (ans + i * (c - i) * (r - i)) % MODER;

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