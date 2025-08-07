#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    vector<int> B(M);
    for (int &x : B) cin >> x;

    // Add virtual walls
    B.insert(B.begin(), 0);
    B.push_back(N);

    int K = M + 1; // Number of segments
    vector<int> cost(K, 0), merged(K - 1, 0);
    vector<int> freq(100001, 0);
    vector<int> mergedFreq(100001, 0);
    int totalCost = 0;

    // Step 1: Compute cost per segment + merged cost in one pass
    int segIndex = 0;
    int distinctSeg = 0, distinctMerged = 0;

    for (int i = 1; i <= N; i++) {
        // Update current segment frequency
        if (++freq[A[i]] == 1) distinctSeg++;

        // Update current merged pair frequency
        if (++mergedFreq[A[i]] == 1) distinctMerged++;

        // If we reached the end of a segment
        if (i == B[segIndex + 1]) {
            cost[segIndex] = distinctSeg;
            totalCost += distinctSeg;
            distinctSeg = 0;
            fill(freq.begin(), freq.end(), 0); // Reset for next segment
            segIndex++;
        }

        // If we reached the end of a merged pair
        if (segIndex < K && i == B[segIndex + 1]) {
            merged[segIndex - 1] = distinctMerged;
            // Reset merged frequencies for the next adjacent pair
            distinctMerged = 0;
            fill(mergedFreq.begin(), mergedFreq.end(), 0);
            // Add segment segIndex to merged freq for next wall
            for (int j = B[segIndex] + 1; j <= i; j++) {
                if (++mergedFreq[A[j]] == 1) distinctMerged++;
            }
        }
    }

    // Step 2: Compute the minimum cost after removing one wall
    int answer = totalCost;
    for (int w = 0; w < K - 1; w++) {
        int newCost = totalCost - cost[w] - cost[w + 1] + merged[w];
        answer = min(answer, newCost);
    }

    cout << answer << "\n";
    return 0;
}
