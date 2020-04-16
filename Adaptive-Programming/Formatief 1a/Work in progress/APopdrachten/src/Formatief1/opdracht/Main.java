package Formatief1.opdracht;

public class Main {

    public static void main(String[] args) {
	// todo: mooi maken print statements!
        AutoHuur ah1 = new AutoHuur();
        System.out.println("Eerste autohuur: " + ah1.toString());

        Klant k = new Klant("Mijnheer de Vries");
        k.setKortingsPercentage(10.0);
        ah1.setHuurder(k.getNaam());
        System.out.println("Eerste autohuur:" + ah1.toString());
        Auto a1 = new Auto();
        String type = "Peugeot 207";
        a1.setType(type);
        int prijsPerDag = 50;
        a1.setPrijsPerDag(prijsPerDag);
        ah1.setGehuurdeAuto(type);
        ah1.setAantalDagen(4);

        double totaalPrijs = ((prijsPerDag*ah1.getAantalDagen())/100)*(100-k.getKortingsPercentage());
        System.out.println("Eerste autohuur:" + ah1.toString()+"Voor een totaal prijs van:"+totaalPrijs);

        AutoHuur ah2 = new AutoHuur();
        Auto a2 = new Auto();
        a2.setType("Ferrari");
        a2.setPrijsPerDag(3500);
        ah2.setGehuurdeAuto(a2.getType());
        ah2.setHuurder(k.getNaam());
        ah2.setAantalDagen(1);
        totaalPrijs = ((a2.getPrijsPerDag()*ah2.getAantalDagen())/100)*(100-k.getKortingsPercentage());
        System.out.println("Eerste autohuur:" + ah2.toString()+"Voor een totaal prijs van:"+totaalPrijs);

    }
}
