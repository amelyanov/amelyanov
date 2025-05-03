/*Nama : Amelya Novparwinka
Nim/Kelas : 23533800/4C
Mata Kuliah : Algoritma Strategi */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // untuk transform (case-insensitive)

using namespace std;

// Membangun prefix table (lps array)
vector<int> buildPrefixTable(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Fungsi KMP
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> matches;
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = buildPrefixTable(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            matches.push_back(i - j); // simpan indeks awal kemunculan
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return matches;
}

int main() {
    string text, pattern;

    cout << "Masukkan teks: ";
    getline(cin, text);
    cout << "Masukkan kata yang ingin dicari: ";
    getline(cin, pattern);

    // Ubah ke huruf kecil untuk pencocokan tidak sensitif kapital
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);

    vector<int> hasil = kmpSearch(text, pattern);

    cout << "\n=== HASIL PENCARIAN ===" << endl;
    cout << "Nama : Amelya Novparwinka" << endl;
    cout << "NIM  : 23533800" << endl;

    if (!hasil.empty()) {
        cout << "Kata '" << pattern << "' ditemukan pada indeks: ";
        for (int idx : hasil)
            cout << idx << " ";
        cout << "\nJumlah kemunculan: " << hasil.size() << endl;
    } else {
        cout << "Kata '" << pattern << "' tidak ditemukan dalam teks." << endl;
    }

    return 0;
}
