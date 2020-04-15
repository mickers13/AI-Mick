package Formatief1.opdracht;

public class Klant {
    private String naam;
    private double kortingsPercentage;

    public double getKortingsPercentage() {
        return kortingsPercentage;
    }

    public void setNaam(String naam) {
        this.naam = naam;
    }

    public void setKortingsPercentage(double kortingsPercentage) {
        this.kortingsPercentage = kortingsPercentage;
    }

    public String getNaam() {
        return naam;
    }

    @Override
    public String toString() {
        return "Klant{" +
                "naam='" + naam + '\'' +
                '}';
    }
}
