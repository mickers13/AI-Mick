package Formatief1.opdracht;

public class AutoHuur {
    private int aantalDagen;
    private String huurder;
    private String gehuurdeAuto;


    public void setHuurder(String huurder) {
        this.huurder = huurder;
    }
    public void setGehuurdeAuto(String gehuurtdeAuto) {
        this.gehuurdeAuto = gehuurtdeAuto;
    }
    public void setAantalDagen(int aantalDagen) {
        this.aantalDagen = aantalDagen;
    }

    @Override
    public String toString() {
        return "AutoHuur{" +
                "aantalDagen=" + aantalDagen +
                ", huurder='" + huurder + '\'' +
                ", gehuurdeAuto='" + gehuurdeAuto + '\'' +
                '}';
    }
}
