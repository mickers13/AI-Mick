public class Main {
    public static void main(String args[]){

        // maak alle nodes
        TextNode textNode1 = new TextNode();
        TextNode textNode2 = new TextNode();
        ChanceNode chancenode1 = new ChanceNode();
        ChanceNode chancenode2 = new ChanceNode();
        NodeAbstract.addLetters("abc");
        // maak alle connecties tussen de nodes.
        String a = "a";
        String b = "b";
        textNode1.addConnectie(textNode1,"a");
        textNode1.addConnectie(textNode2,"b");
        textNode2.addConnectie(chancenode1,"b");
        // in chance node als er een random cijfer word gekozen met een cijfer boven de 70 zal hij een afwijking maken van de code en een c invoeren
        chancenode1.addConnectie(chancenode1,"a");
        chancenode1.addConnectie(chancenode2,"b");
        chancenode2.addConnectie(textNode2,"a");
        chancenode2.addConnectie(textNode1,"b");
        // je kan extra kans nodes toevoegen om de kansen aante passen, of de kans zelf verhogen.
        chancenode1.addConnectie(textNode1,"c");
        chancenode2.addConnectie(textNode1,"c");
        textNode1.addConnectie(textNode1,"c");
        textNode2.addConnectie(textNode1,"c");

        //dit is een public variable zodat ik het makkelijk kan laten zien, ik weet dat dit eigenlijk private zou moeten
        System.out.println("node0 heeft deze connecties:"+ chancenode2.connecties.keySet() + chancenode2.connecties.values());
        System.out.println("node2 heeft deze connectie:"+ textNode2.connecties.keySet() + textNode2.connecties.values());

        // voer je code hier in, dit is om te testen of de code OK is. goede characters zijn A B of C, maar ik controleer en corrigeer deze code indien nodig.
        String code = "abbbbbacbabaacbabaacYbaaaab";

        //nadat de code is gecontroleerd op foute character voer hem uit: ( code validator heb ik een test voor geschreven!)
        chancenode2.useNode(textNode1.codeValidator(code));


    }
}
