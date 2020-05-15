import org.jetbrains.annotations.NotNull;

import java.util.HashMap;

public class TextNode extends NodeAbstract {
    HashMap<String, NodeAbstract> connecties = new HashMap<>();
    static String code;
    String letter;
    String newCode;
    String possibleLetters;
    @Override
    public void useNode(String abcode) {
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
        if (letter.equals("c")) {
            if (connecties.containsKey("c")) {
                System.out.println("c gevonden in "+this+" we geven de resterende code door naar de volgende node.");
                hoeveelheidVerplaatst++;
                connecties.get(letter).useNode(newCode);
            } else {
                System.out.println("geen c gevonden, einde programma.");
                System.out.println("Er zijn zoveel nodes gepasseerd: "+ (hoeveelheidVerplaatst+1));
                System.exit(0);
            }
        }
        System.out.println("end of sequence reached.");
        System.exit(0);
    }

    public void addConnectie(TextNode textNode, String letter) {
        connecties.put(letter, textNode);
    }

    public void addConnectie(ChanceNode chanceNode, String letter) {
        connecties.put(letter, chanceNode);
    }


    // ik heb deze functie gemaakt zodat het daadwerkelijk nut heeft om

    public String codeValidator(String abcode){
        for(int i = 0; i<abcode.length(); i++)
            //als er een letter in zit die er niet in zou moeten zitten,delete deze.
            if (!letters.contains(""+abcode.charAt(i))){
            abcode = new StringBuilder(abcode).deleteCharAt(i).toString();
            }
        return abcode;
    }

}
