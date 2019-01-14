int binomial_coefficient(int n, int k) {
	if (k == 0 || k == n) return 1;
	else return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}
int binomial_coefficient2(int n, int k) {
	int result = 1;
	for (int i = 0; i < k; i++) {
		result *= n;
		n--;
	}
	for (int j = k; j > 0; j--)
		result /= j;
	return result;
}