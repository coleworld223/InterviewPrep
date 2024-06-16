
/*
    Hints :
    1. Use sieve
*/

/*
    Solution : 
    use a sieve to find which integers are prime till (1e6)
    Run a brute force algorithm
*/

struct sieve {
    vector <int> is_prime;
    int sz;
    sieve (int n) {
        sz = n;
        is_prime.resize(n + 1, 1);
        is_prime[0] = is_prime[1] = 0;
        work ();
    }
    
    void work () {
        for (int i = 2; i <= sz; i += 1) {
            if (is_prime[i] == 0) continue;
            for (int j = i + i; j <= sz; j += i) {
                is_prime[j] = 0;
            }
        }
    }
};

sieve sv (1000001);

class Solution {
  public:
    vector<int> getPrimes(int n) {
        for (int x = 2; x <= n - 2; x += 1) {
            if (sv.is_prime[x]) {
                int y = n - x;
                if (sv.is_prime[y]) {
                    return {x, y};
                }
            }
        }
        return {-1, -1};
    }
};
