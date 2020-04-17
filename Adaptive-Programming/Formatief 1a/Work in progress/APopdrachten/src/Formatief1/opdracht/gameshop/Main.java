package Formatief1.opdracht.gameshop;

public class Main {
    int releaseJaar1 = 1; // 1 jaar geleden ( deze code werkt voor mij neit dus even aangepast.)
    int releaseJaar2 = 2; // 2 jaar geleden


    Game g1 = new Game("Just Cause 3", releaseJaar1, 49.98);
    Game g2 = new Game("Need for Speed: Rivals", releaseJaar2, 45.99);
    Game g3 = new Game("Need for Speed: Rivals", releaseJaar2, 45.99);


    Persoon p1 = new Persoon("Eric", 200);
    Persoon p2 = new Persoon("Hans", 55);
    Persoon p3 = new Persoon("Arno", 185);


    // Druk de volgende transacties af (pas de code aan)
    p1.koop(g1);
    p1.koop(g2);
    p1.koop(g3);
    p2.koop(g2);
    p2.koop(g1);
    p3.koop(g3);


    // Druk personen p1 p2 p3 nu af naar de console


    // Druk de volgende transacties af (pas de code aan)
    p1.verkoop(g1, p3);
    p2.verkoop(g2, p3);
    p2.verkoop(g1, p1);


    // Druk personen p1 p2 p3 nu af naar de console
}
