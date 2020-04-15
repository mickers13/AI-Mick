package Formatief1.opdracht;

public class Main {

    public static void main(String[] args) {
	// todo: afmaken opdracht 1 , sorry ik heb iets teveel tijd gestopt in de test en het kijken van youtube video's om mijn java van 3 jaar geleden onder het stof vandaan te trekken
        AutoHuur ah1 = new AutoHuur();
        System.out.println("Eerste autohuur: " + ah1.toString())

        Klant k = new Klant();
        k.setNaam("Mijnheer de Vries");
        k.setKortingsPercentage(10.0);
        ah1.setHuurder(k.getNaam());
// Print: "Eerste autohuur: " + ah1.toString()

        Auto a1 = new Auto();
        a1.setType("Peugeot 207" 50);
        ah1.setGehuurdeAuto(a1.getType());
        ah1.setAantalDagen(4);
// Print "Eerste autohuur:" + ah1.toString()

        AutoHuur ah2 = new AutoHuur();
        Auto a2("Ferrari", 3500);
        ah2.setGehuurdeAuto(a2);
        ah2.setHuurder(k);
        ah2.setAantalDagen(1);
// Print "Tweede autohuur: " + ah2.toString()

// Print "Gehuurd: " + ah1.getGehuurdeAuto()
// Print "Gehuurd: " + ah2.getGehuurdeAuto()


    }
}
