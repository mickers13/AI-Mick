import java.util.HashMap;
import java.util.Random;

public class ChanceNode extends NodeAbstract {


    String code;
    boolean isendnode;
    public HashMap<String,NodeAbstract> connecties = new HashMap<>();
    private Random rand = new Random();

    String newCode;

    public ChanceNode() {
        // dit zijn nodes die hetzelfde werken als de AB nodes, maar maar met een 70% kans van toepassen van de letter ipv een andere.
        this.isendnode = isendnode;
    }   // deze code lijkt erg veel op de code van text node, maar ik weet niet hoe ik dit aan zou moeten passen, dat ik alleen kleine stukjes toevoeg. Tips zijn welkom
    public void useNode(String abcode) {
        int r = rand.nextInt(101);
        code = abcode;
        System.out.println("Cijfer is : "+ r);
        String letter = code.substring(0, 1);
        newCode = code.substring(1);
        System.out.println("Letter die we nodig hebben: "+ letter);

        if (letter.equals("a")) {
            if (connecties.containsKey("a")&&connecties.containsKey("b")&&connecties.containsKey("c")) {
                    if(r < 70){
                    System.out.println("a gevonden"+this+"we geven de resterende code door naar de volgende node.");
                    hoeveelheidVerplaatst++;
                    connecties.get(letter).useNode(newCode);

                    } else {
                        System.out.println("Andere keuze gemaakt dan aanbevolen, keuze c.");
                        hoeveelheidVerplaatst++;
                        connecties.get("c").useNode(newCode);

            }} else {
                if (connecties.containsKey("a")) {
                    System.out.println("a gevonden in "+this+" we geven de resterende code door naar de volgende node.");
                    hoeveelheidVerplaatst++;
                    connecties.get(letter).useNode(newCode);
                } else {
                    System.out.println("geen connecties gevoden. Einde programma");
                    System.out.println("Er zijn zoveel nodes gepasseerd: "+ (hoeveelheidVerplaatst+1));
                    System.exit(0);
                }
            }

        }
        if (letter.equals("b")) {
            if (connecties.containsKey("a")&&connecties.containsKey("b")&&connecties.containsKey("c")) {
                if(r < 70){
                    System.out.println("b gevonden"+this+"we geven de resterende code door naar de volgende node.");
                    hoeveelheidVerplaatst++;
                    connecties.get(letter).useNode(newCode);

                } else {
                    System.out.println("Andere keuze gemaakt dan aanbevolen, keuze a.");
                    hoeveelheidVerplaatst++;
                    connecties.get("a").useNode(newCode);

                }} else {
                if (connecties.containsKey("b")) {
                    System.out.println("b gevonden in "+this+" we geven de resterende code door naar de volgende node.");
                    hoeveelheidVerplaatst++;
                    connecties.get(letter).useNode(newCode);
                } else {
                    System.out.println("geen connecties gevoden. Einde programma");
                    System.out.println("Er zijn zoveel nodes gepasseerd: "+ (hoeveelheidVerplaatst+1));
                    System.exit(0);
                }
            }

        }else{
            if (connecties.containsKey("a")&&connecties.containsKey("b")&&connecties.containsKey("c")) {
                if(r < 70){
                    System.out.println("c gevonden"+this+"we geven de resterende code door naar de volgende node.");
                    hoeveelheidVerplaatst++;
                    connecties.get(letter).useNode(newCode);

                } else {
                    System.out.println("Andere keuze gemaakt dan aanbevolen, keuze b.");
                    hoeveelheidVerplaatst++;
                    connecties.get("b").useNode(newCode);

                }} else {
                if (connecties.containsKey("c")) {
                    System.out.println("c gevonden in "+this+" we geven de resterende code door naar de volgende node.");
                    hoeveelheidVerplaatst++;
                    connecties.get(letter).useNode(newCode);
                } else {
                    System.out.println("geen connecties gevoden. Einde programma");
                    System.out.println("Er zijn zoveel nodes gepasseerd: "+ (hoeveelheidVerplaatst+1));
                    System.exit(0);
                }
            }
        }
        System.out.println("end of sequince reached.");
        System.exit(0);
    }




    public void addConnectie(ChanceNode node,String letter) {
        connecties.put(letter,node);
    }
    public void addConnectie(TextNode textNode, String letter) {
        connecties.put(letter, textNode);
    }

}

