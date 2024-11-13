public class Penerima {
    private String nama;
    private String kategori;

    // Konstruktor berparameter
    public Penerima(String nama, String kategori) {
        this.nama = nama;
        this.kategori = kategori;
    }

    // Getter dan Setter
    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getKategori() {
        return kategori;
    }

    public void setKategori(String kategori) {
        this.kategori = kategori;
    }
} 
