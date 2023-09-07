#include <iostream>
#include <bitset>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int merge_bottle(const int n, const int k) {
	int idx = 0;
	bitset<25> bs = bitset<25>(n);

	// 2의 제곱수의 개수(bitset에서 1로 마킹된 부분)가 
	// k개가 이하가 될 때까지 수를 증가시키며 1의 수를 줄인다.
	// ex) 만약 k가 1이라면, 10 1110 -> 11 0000 -> 100 0000
	while (bs.count() > k) {
		while (bs[idx]) { bs.flip(idx); idx++; } // 1 -> 0
		bs.flip(idx); // 0 -> 1
	}

	return bs.to_ulong() - n;
}

int main() {
	fastio;
	int n, k;
	cin >> n >> k;

	if (n <= k) cout << 0;
	else cout << merge_bottle(n, k);

	return 0;
}