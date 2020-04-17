package Formatief1.opdracht.gameshop;

public class Game {
    private String naam;
    private int releaseJaar;
    private double price;

    public Game(String naam,int releaseJaar,double budget){
        this.naam = naam;
        this.releaseJaar = releaseJaar;
        this.price = budget;
    }

    public int getRelease() {
        return releaseJaar;
    }

    public double getPrice() {
        return price;
    }

    public String getNaam() {
        return naam;
    }
}
