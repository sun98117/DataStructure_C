int sum(int n) {
	if (n < 1) return 0;
	else return n + sum(n - 1);
}