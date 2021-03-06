//#include <iostream>
//#include <algorithm>
//#define ll long long
//using namespace std;
//int N, K, ans;
//
//int home[200001];
//
//bool check(ll mid) {
//	ll tmp = 1;
//	ll pre = home[0];
//	for (int i = 0; i < N; i++) {
//		if (home[i] - pre >= mid) {
//			pre = home[i];
//			tmp++;
//		}
//	}
//	if (tmp >= K) {
//		return true;
//	}
//	else return false;
//}
//
//void bs(ll start, ll end) {
//	while (end - start >= 0) {
//		ll mid = (end + start) / 2;
//		if (check(mid)) {
//			if (ans < mid) ans = mid;
//			start = mid + 1;
//		}
//		else {
//			end = mid - 1;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) cin >> home[i];
//	sort(home, home + N);
//	bs(1, home[N-1] - home[0]);
//	cout << ans;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int N, M, temp, maxi, mini;
vector <int> v;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp; v.push_back(temp);
	}
	maxi = *max_element(v.begin(), v.end());
	mini = *min_element(v.begin(), v.end());
}

bool check(int mid) {
	int cnt = 2;
	int base = v[0];
	for (auto& each : v) {
		if (each - base >= mid) {
			cnt++;
			base = each;
		}
	}
	return cnt >= M + 1;
}

int search() {
	int ans = 0;
	int left = 1;
	int right = maxi-mini;
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		bool res = check(mid);
		if (res) {
			ans = (ans < mid ? mid : ans);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}
int main() {
	input();
	sort(v.begin(), v.end());
	cout << search();
}