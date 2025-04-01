//Author: Harein Abeysekera
// 03/30/25

#include "bdc.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// No need for dynamic programming
// Convert a vector of integers to a formatted string
string vec_to_string(vector<int> v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); i++) {  
        s += to_string(v[i]);
        if (i < v.size() - 1) {
            s += ", ";  // Add a comma between numbers, but not at the end
        }
    }
    s += "]";
    return s;
}

// Finds the largest subset of numbers where each number is divisible by another in the set
// This uses a Dynamic Programming approach 
vector<int> biggest_divisible_conglomerate(vector<int> input) {
    if (input.empty()) return {};  // Edge case
    
    // Sorting the numbers in ascending order makes it easier to check divisibility
    sort(input.begin(), input.end());
    int n = input.size();
    
    // dp[i] keeps track of the longest valid subset ending at index i
    // prev_Approach[i] helps us reconstruct the subset later
    vector<int> dp(n, 1), prev_Approach(n, -1);
    int maxSize = 1, maxIndex = 0;  // Keep track of the best subset found

    // Iterate through the sorted list, checking each number against previous ones
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If input[i] is divisible by input[j], it can be added to the subset
            if (input[i] % input[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev_Approach[i] = j;  // This tracks where this element came from
            }
        }
        // Update the max subset size, and its endpoint
        if (dp[i] > maxSize) {
            maxSize = dp[i];
            maxIndex = i;
        }
    }
    
    // Rebuild the largest divisible subset by tracing back through prev_Approach[]
    vector<int> result;
    for (int i = maxIndex; i >= 0; i = prev_Approach[i]) {
        result.push_back(input[i]);
        if (prev_Approach[i] == -1) break;  // Stop once we reach the beginning
    }
    
    reverse(result.begin(), result.end());  // Restore the original order
    return result;
}
