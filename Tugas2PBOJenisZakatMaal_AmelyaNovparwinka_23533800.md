import java.util.Scanner;

public class ZakatMaalCalculator {

    // Nisab default
    static double nisabEmas = 85; // Nisab emas dalam gram
    static double nisabPerak = 595; // Nisab perak dalam gram
    static double nisabTabungan = 85; // Nisab uang setara emas
    static double nisabPerdagangan = 85; // Nisab setara emas
    static double nisabPertanianIrigasi = 653; // Nisab hasil pertanian irigasi (kg)
    static double nisabPertanianAlami = 520; // Nisab hasil pertanian alami (kg)

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean lanjut = true;

        // Perulangan untuk pengguna memilih ulang
        while (lanjut) {
            System.out.println("\n=== Kalkulator Zakat Maal ===");
            System.out.println("  1. Ubah Nisab");
            System.out.println("  2. Zakat Emas, Perak, dan Logam Mulia");
            System.out.println("  3. Zakat Uang dan Tabungan");
            System.out.println("  4. Zakat Perniagaan");
            System.out.println("  5. Zakat Pertanian");
            System.out.println("  6. Zakat Peternakan");
            System.out.println("  7. Zakat Hasil Tambang");
            System.out.println("  8. Zakat Investasi dan Saham");
            System.out.println("  9. Keluar");
            System.out.print("Masukkan pilihan Anda (1-9): ");

            int pilihan = scanner.nextInt();

            switch (pilihan) {
                case 1 -> ubahNisab(scanner); // Opsi untuk mengubah nisab
                case 2 -> hitungZakatEmas(scanner);
                case 3 -> hitungZakatTabungan(scanner);
                case 4 -> hitungZakatPerniagaan(scanner);
                case 5 -> hitungZakatPertanian(scanner);
                case 6 -> hitungZakatPeternakan(scanner);
                case 7 -> hitungZakatTambang(scanner);
                case 8 -> hitungZakatInvestasi(scanner);
                case 9 -> {
                    System.out.println("Terima kasih telah menggunakan kalkulator zakat. Program berakhir.");
                    lanjut = false; // Mengakhiri perulangan
                }
                default -> System.out.println("Pilihan tidak valid. Silakan coba lagi.");
            }
        }

        scanner.close();
    }

    // Fungsi untuk mengubah nisab
    static void ubahNisab(Scanner scanner) {
        System.out.println("\n=== Ubah Nisab ===");
        System.out.print("Masukkan nisab emas (gram): ");
        nisabEmas = scanner.nextDouble();

        System.out.print("Masukkan nisab perak (gram): ");
        nisabPerak = scanner.nextDouble();

        System.out.print("Masukkan nisab tabungan (setara dengan emas): ");
        nisabTabungan = scanner.nextDouble();

        System.out.print("Masukkan nisab perdagangan (setara dengan emas): ");
        nisabPerdagangan = scanner.nextDouble();

        System.out.print("Masukkan nisab pertanian dengan irigasi (kg): ");
        nisabPertanianIrigasi = scanner.nextDouble();

        System.out.print("Masukkan nisab pertanian alami (kg): ");
        nisabPertanianAlami = scanner.nextDouble();

        System.out.println("Nisab berhasil diubah!\n");
    }

    // Perhitungan zakat emas, perak, dan logam mulia
    static void hitungZakatEmas(Scanner scanner) {
        System.out.print("Masukkan jumlah emas/perak/logam mulia (gram): ");
        double emas = scanner.nextDouble();

        if (emas >= nisabEmas) {
            double zakat = emas * 0.025;
            System.out.printf("Zakat yang harus dikeluarkan: %.2f gram.%n", zakat);
        } else {
            System.out.println("Jumlah emas tidak mencapai nisab.");
        }
    }

    // Perhitungan zakat tabungan
    static void hitungZakatTabungan(Scanner scanner) {
        System.out.print("Masukkan jumlah tabungan (dalam satuan uang): ");
        double tabungan = scanner.nextDouble();

        if (tabungan >= nisabTabungan) {
            double zakat = tabungan * 0.025;
            System.out.printf("Zakat yang harus dikeluarkan: %.2f uang.%n", zakat);
        } else {
            System.out.println("Jumlah tabungan tidak mencapai nisab.");
        }
    }

    // Perhitungan zakat perniagaan
    static void hitungZakatPerniagaan(Scanner scanner) {
        System.out.print("Masukkan nilai barang dagangan (dalam satuan uang): ");
        double perdagangan = scanner.nextDouble();

        if (perdagangan >= nisabPerdagangan) {
            double zakat = perdagangan * 0.025;
            System.out.printf("Zakat yang harus dikeluarkan: %.2f uang.%n", zakat);
        } else {
            System.out.println("Nilai perdagangan tidak mencapai nisab.");
        }
    }

    // Perhitungan zakat pertanian
    static void hitungZakatPertanian(Scanner scanner) {
        System.out.println("Pilih metode pengairan:");
        System.out.println("  1. Irigasi (dengan biaya)");
        System.out.println("  2. Pengairan alami (air hujan)");

        int metode = scanner.nextInt();
        System.out.print("Masukkan jumlah hasil pertanian (kg): ");
        double hasil = scanner.nextDouble();

        if (metode == 1 && hasil >= nisabPertanianIrigasi) {
            double zakat = hasil * 0.05;
            System.out.printf("Zakat yang harus dikeluarkan: %.2f kg.%n", zakat);
        } else if (metode == 2 && hasil >= nisabPertanianAlami) {
            double zakat = hasil * 0.10;
            System.out.printf("Zakat yang harus dikeluarkan: %.2f kg.%n", zakat);
        } else {
            System.out.println("Hasil pertanian tidak mencapai nisab.");
        }
    }

    // Perhitungan zakat peternakan
    static void hitungZakatPeternakan(Scanner scanner) {
        System.out.print("Masukkan jumlah ternak (sapi/kambing/domba): ");
        int ternak = scanner.nextInt();

        if (ternak >= 40) { // Nisab kambing
            double zakat = ternak / 40.0; // Zakat kambing 1 ekor per 40 ekor
            System.out.printf("Zakat yang harus dikeluarkan: %d ekor.%n", (int) zakat);
        } else {
            System.out.println("Jumlah ternak tidak mencapai nisab.");
        }
    }

    // Perhitungan zakat hasil tambang
    static void hitungZakatTambang(Scanner scanner) {
        System.out.print("Masukkan nilai hasil tambang (dalam satuan uang): ");
        double tambang = scanner.nextDouble();

        double zakat = tambang * 0.025;
        System.out.printf("Zakat yang harus dikeluarkan: %.2f uang.%n", zakat);
    }

    // Perhitungan zakat investasi dan saham
    static void hitungZakatInvestasi(Scanner scanner) {
        System.out.print("Masukkan nilai investasi/saham (dalam satuan uang): ");
        double investasi = scanner.nextDouble();

        if (investasi >= nisabPerdagangan) {
            double zakat = investasi * 0.025;
            System.out.printf("Zakat yang harus dikeluarkan: %.2f uang.%n", zakat);
        } else {
            System.out.println("Nilai investasi tidak mencapai nisab.");
        }
    }
}
