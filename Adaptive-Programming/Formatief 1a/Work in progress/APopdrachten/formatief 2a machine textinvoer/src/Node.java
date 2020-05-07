import java.util.ArrayList;
import java.util.HashMap;

public class Node extends NodeAbstract {
    HashMap<String,Node> connecties = new HashMap<>();
    static String code;
    String letter;
    String newCode;
    @Override
    void useNode(String abcode) {
        code = abcode;

        letter = code.substring(0, 1);
        newCode = code.substring(1);
        System.out.println("Letter die we nodig hebben: "+ letter);

        if (letter.equals("a")) {
            if (connecties.containsKey("a")) {
                System.out.println("a gevonden"+this+"we geven de resterende code door naar de volgende node.");
                hoeveelheidVerplaatst++;
                connecties.get(letter).useNode(newCode);

            } else {
                System.out.println("geen a gevonden, einde programma.");
                System.out.println("Er zijn zoveel nodes gepasseerd: "+ (hoeveelheidVerplaatst+1));
                System.exit(0);
            }

        }
        if (letter.equals("b")) {
            if (connecties.containsKey("b")) {
                System.out.println("b gevonden in "+this+" we geven de resterende code door naar de volgende node.");
                hoeveelheidVerplaatst++;
                connecties.get(letter).useNode(newCode);
            } else {
                System.out.println("geen b gevonden, einde programma.");
                System.out.println("Er zijn zoveel nodes gepasseerd: "+ (hoeveelheidVerplaatst+1));
                System.exit(0);
            }
        }
        System.out.println("end of sequince reached.");
        System.exit(0);
    }
    @Override
    public void addConnectie(Node node,String letter) {
        connecties.put(letter,node);
    }
}
