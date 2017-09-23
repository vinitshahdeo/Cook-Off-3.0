
#include <bits/stdc++.h>
using namespace std;

int frequency[10004];
int price[10004];

int main() {
    int test, n, m, c_i, c_j;

    cin >> test;

    for (int t = 1; t <= test; t++) {
        
        memset(frequency, 0, sizeof(frequency));

        cin >> m >> n;
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &price[i]);
            frequency[price[i]]++;
        }
        
        int c_i_index;
        
        for (int i = 1; i <= n; i++) {
            
            c_i = price[i];
            
            // Decrease the frequency to avoid counting value twice
            frequency[c_i]--;  
            
            int tmp_c_j = m - price[i];
            
            if (frequency[tmp_c_j] > 0) {
                c_j = tmp_c_j;
                c_i_index = i;  
                printf("%d", i);
                break;
            }
        
            frequency[c_i]++;  //Restore original frequency
        }
      
        // Search for c_j in the rest of the array
        for (int i = c_i_index + 1; i <= n; i++) {
            if (price[i] == c_j) {
                printf(" %d\n", i);
                break;
            }
        }
    }
}