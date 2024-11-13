public class Muzaki {
    private String nama;
    private double jumlahZakat;

    // Konstruktor berparameter
    public Muzaki(String nama, double jumlahZakat) {
        this.nama = nama;
        this.jumlahZakat = jumlahZakat;
    }

    // Getter dan Setter
    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public double getJumlahZakat() {
        return jumlahZakat;
    }

    public void setJumlahZakat(double jumlahZakat) {
        this.jumlahZakat = jumlahZakat;
    }
}
