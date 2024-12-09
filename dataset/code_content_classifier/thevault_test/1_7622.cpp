Int func(int last, int now) {
	if (now < 0) {
		return 0LL;
	} else if (now == 0) {
		return 1LL;
	} else {
		Int& ans = dp[last][now];

		if (ans == -1LL) {
			ans = 0LL;
			for (int i = last + 1; i <= now; i++) {
				ans += func(i, now - i);
			}
		}
		return ans;
	}
}