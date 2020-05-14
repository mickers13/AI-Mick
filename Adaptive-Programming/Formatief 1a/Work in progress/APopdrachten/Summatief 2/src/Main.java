public class Main {
    public static void main(String args[]){

        // maak alle nodes
        TextNode textNode1 = new TextNode();
        TextNode textNode2 = new TextNode();
        ChanceNode chancenode1 = new ChanceNode();
        TextNode textNode0 = new TextNode();

        // maak alle connecties tussen de nodes.
        String a = "a";
        String b = "b";
        textNode1.addConnectie(textNode1,"a");
        textNode1.addConnectie(textNode2,"b");
        textNode2.addConnectie(chancenode1,"b");
        // in chance node als er een random cijfer word gekozen met een cijfer boven de 70 zal hij een afwijking maken van de standaard route van de ABcode
        chancenode1.addConnectie(chancenode1,"a");
        chancenode1.addConnectie(textNode0,"b");
        textNode0.addConnectie(textNode2,"a");
        textNode0.addConnectie(textNode1,"b");
        //dit is een public variable zodat ik het makkelijk in de "test" kan laten zien aan jullie. Ik weet dat ik dit eigenlijk met get/set methodes zou moeten oproepen.
        System.out.println("node0 heeft deze connecties:"+ textNode0.connecties.keySet() + textNode0.connecties.values());
        System.out.println("node2 heeft deze connectie:"+ textNode2.connecties.keySet() + textNode2.connecties.values());
        textNode0.useNode("abbbbaababababababbabxaaab");


    }
}
