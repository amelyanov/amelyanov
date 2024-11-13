public public class Main {
    public static void main(String[] args) {
        // Membuat objek Muzaki
        Muzaki muzaki1 = new Muzaki("Ahmad", 500000.0);
        
        // Membuat objek Penerima
        Penerima penerima1 = new Penerima("Budi", "Fakir");

        // Menampilkan informasi Muzaki dan Penerima
        System.out.println("Informasi Muzaki:");
        System.out.println("Nama: " + muzaki1.getNama());
        System.out.println("Jumlah Zakat: Rp" + muzaki1.getJumlahZakat());

        System.out.println("\nInformasi Penerima:");
        System.out.println("Nama: " + penerima1.getNama());
        System.out.println("Kategori: " + penerima1.getKategori());
    }
} 
