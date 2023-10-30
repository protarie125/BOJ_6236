#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int n, m;
vi atm;

int simulate(int v) {
	auto ret = 0;
	auto now = 0;
	for (const auto& x : atm) {
		if (now < x) {
			now = v;
			++ret;
		}

		now -= x;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;

	atm = vi(n);
	auto maxX = 0;
	auto total = 0;
	for (auto&& x : atm) {
		cin >> x;
		maxX = max(maxX, x);
		total += x;
	}

	auto l = 0;
	auto r = total;
	auto ans = 0;
	while (l <= r) {
		auto mid = (l + r) / 2;

		if (mid < maxX) {
			l = mid + 1;
			continue;
		}

		const auto ret = simulate(mid);
		if (m < ret) {
			l = mid + 1;
		}
		else {
			ans = mid;
			r = mid - 1;
		}
	}

	cout << ans;

	return 0;
}