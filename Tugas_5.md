public class Mahasiswa {
    // Atribut/Properti Mahasiswa
    int nim;
    String nama;
    char kelas;
    double ipk;

    // Konstruktor tanpa parameter (default)
    public Mahasiswa() {
        // Inisialisasi nilai default (opsional)
        this.nim = 0;
        this.nama = "Tidak Diketahui";
        this.kelas = '-';
        this.ipk = 0.0;
    }

    // Konstruktor dengan parameter
    public Mahasiswa(int nim, String nama, char kelas, double ipk) {
        this.nim = nim;
        this.nama = nama;
        this.kelas = kelas;
        this.ipk = ipk;
    }

    // 1. Method Void: Menampilkan Informasi Mahasiswa
    public void tampilkanInfo() {
        System.out.println("NIM : " + nim);
        System.out.println("Nama : " + nama);
        System.out.println("Kelas : " + kelas);
        System.out.println("IPK : " + ipk);
        System.out.println(); // Tambahkan spasi antara output mahasiswa
    }

    // 2. Method Return: Mengembalikan Informasi Mahasiswa dalam Bentuk String
    public String getInfoMahasiswa() {
        return "NIM : " + nim + "\n" +
               "Nama : " + nama + "\n" +
               "Kelas : " + kelas + "\n" +
               "IPK : " + ipk + "\n";
    }

    // 3. Method Berparameter: Memperbarui IPK Mahasiswa
    public void updateIpk(double ipkBaru) {
        if (ipkBaru >= 0.0 && ipkBaru <= 4.0) {
            this.ipk = ipkBaru;
            System.out.println("IPK berhasil diperbarui menjadi: " + ipk);
        } else {
            System.out.println("Nilai IPK tidak valid. Harus antara 0.0 - 4.0");
        }
    }

    // 4. Method Berparameter: Mengganti Nama Mahasiswa
    public void gantiNama(String namaBaru) {
        this.nama = namaBaru;
        System.out.println("Nama berhasil diganti menjadi: " + nama);
    }

    // Main method untuk menjalankan program
    public static void main(String[] args) {
        // Membuat objek Mahasiswa menggunakan konstruktor dengan parameter
        Mahasiswa mhs1 = new Mahasiswa(12345678, "Budi", 'A', 3.41);
        Mahasiswa mhs2 = new Mahasiswa(23533800, "Amelya", 'C', 4.00);

        // Menampilkan informasi Mahasiswa 1 menggunakan method void
        System.out.println("Informasi Mahasiswa 1:");
        mhs1.tampilkanInfo();

        // Menampilkan informasi Mahasiswa 2 menggunakan method return
        System.out.println("Informasi Mahasiswa 2:");
        String infoMahasiswa2 = mhs2.getInfoMahasiswa();
        System.out.println(infoMahasiswa2);

        // Memperbarui IPK Mahasiswa 1 menggunakan method berparameter
        mhs1.updateIpk(3.75);

        // Mengganti nama Mahasiswa 2 menggunakan method berparameter
        mhs2.gantiNama("Amelya Novparwinka");

        // Menampilkan informasi terbaru
        System.out.println("Informasi Mahasiswa 1 (Setelah Update):");
        mhs1.tampilkanInfo();

        System.out.println("Informasi Mahasiswa 2 (Setelah Ganti Nama):");
        System.out.println(mhs2.getInfoMahasiswa());
    }
}
