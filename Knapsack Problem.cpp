#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Fungsi untuk hitung total bobot
int hitungBobot(const vector<int>& subset, const int weights[]) {
    int total = 0;
    for (int idx : subset) {
        total += weights[idx];
    }
    return total;
}

// Fungsi untuk hitung total profit
int hitungProfit(const vector<int>& subset, const int profits[]) {
    int total = 0;
    for (int idx : subset) {
        total += profits[idx];
    }
    return total;
}

int main() {
    const int n = 8;
    int weights[n] = {2, 3, 5, 3, 3, 8, 11, 11};
    int profits[n] = {21, 35, 70, 42, 80, 20, 10, 5};
    int capacity = 15;

    int max_profit = 0;
    vector<int> best_subset;

    // Header program
    cout << "Program Knapsack Enumeration (Terurut)" << endl;
    cout << "Nama  : Amelya Novparwinka" << endl;
    cout << "Nim/Kelas : 23533800/4C" << endl;
    cout << "----------------------------------------------" << endl << endl;

    // Header tabel
    cout << left << setw(20) << "Solusi"
         << setw(15) << "Total bobot"
         << setw(15) << "Total profit"
         << "Keterangan" << endl;
    cout << string(60, '-') << endl;

    // Enumerasi subset per ukuran k (0..n)
    for (int k = 0; k <= n; k++) {
        vector<int> comb(k);

        // Inisialisasi indeks
        for (int i = 0; i < k; i++) {
            comb[i] = i;
        }

        while (true) {
            vector<int> subset = comb;

            int total_weight = hitungBobot(subset, weights);
            int total_profit = hitungProfit(subset, profits);

            string status = (total_weight <= capacity) ? "Layak" : "Tidak layak";

            // Cetak subset
            cout << "{";
            for (size_t i = 0; i < subset.size(); i++) {
                cout << (subset[i] + 1);
                if (i != subset.size() - 1) cout << ",";
            }
            cout << "}" << setw(20 - (2 + 2 * subset.size()))
                 << " " << setw(15)
                 << total_weight << setw(15)
                 << total_profit << status << endl;

            if (status == "Layak" && total_profit > max_profit) {
                max_profit = total_profit;
                best_subset = subset;
            }

            // Cari kombinasi selanjutnya
            int i;
            for (i = k - 1; i >= 0; i--) {
                if (comb[i] != i + n - k) {
                    break;
                }
            }

            if (i < 0) break; // Selesai

            comb[i]++;
            for (int j = i + 1; j < k; j++) {
                comb[j] = comb[j - 1] + 1;
            }
        }
    }

    // Tampilkan solusi terbaik
    cout << "\n----------------------------------------------" << endl;
    cout << "Solusi terbaik: {";
    for (size_t i = 0; i < best_subset.size(); i++) {
        cout << (best_subset[i] + 1);
        if (i != best_subset.size() - 1) cout << ",";
    }
    cout << "} dengan profit = " << max_profit << endl;

    // Footer
    cout << "\nProgram selesai dijalankan oleh: Amelya Novparwinka" << endl;

    return 0;
}
