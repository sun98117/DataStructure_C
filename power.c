double power(double x, int n) {
	if (n == 0)
		return 1;
	else if (n % 2 == 0) {
		x *= x;
		return power(x, n / 2);
	}
	else {
		return x * (x*x, (n - 1) / 2);
	}
}
