class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

        pq.push(1);

        long long int i = 1;
        while (i < n)
        {
            long long int temp = pq.top();
            pq.pop();
            while (!pq.empty() && temp == pq.top()) pq.pop();


            for (int j = 0; j < primes.size(); j++)
                pq.push(temp * primes[j]);

            i++;
        }
        return pq.top();

    }
};