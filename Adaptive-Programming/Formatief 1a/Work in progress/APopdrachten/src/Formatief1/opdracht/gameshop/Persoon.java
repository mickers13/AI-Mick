package Formatief1.opdracht.gameshop;

public class Persoon {
    private String naam;
    private double budget;

    public Persoon(String naam,double budget){
        this.naam = naam;
        this.budget = budget;
    }
    public void koop(Game game){
        String gameName = game.getNaam();
        double gamePrice = game.getPrice();
        int gameReleaseYear = game.getRelease();
        double totaalPrice = gamePrice / (100-(30*gameReleaseYear));
        if (budget >= totaalPrice){
            System.out.println(gameName+"gekocht. Voor "+totaalPrice+" Prijs zonder korting: "+gamePrice);
        }else {
            System.out.println("Game niet gekocht.");
        }

    }
}
