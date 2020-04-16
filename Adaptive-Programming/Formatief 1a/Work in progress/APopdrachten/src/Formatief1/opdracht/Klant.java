package Formatief1.opdracht;

public class Klant {
    private String naam;
    private double kortingsPercentage;

    public Klant(String naam){
        this.naam = naam; //In java returnt dit null of niks
    }
    public double getKortingsPercentage() {
        return kortingsPercentage;
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
