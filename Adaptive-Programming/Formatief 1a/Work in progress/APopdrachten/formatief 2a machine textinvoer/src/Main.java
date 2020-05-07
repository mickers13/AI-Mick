public class Main {
    public static void main(String args[]){

        // maak alle nodes
        Node node1 = new Node();
        Node node2 = new Node();
        Node node3 = new Node();
        Node node0 = new Node();

        // maak alle connecties tussen de nodes.
        String a = "a";
        String b = "b";
        node1.addConnectie(node1,"a");
        node1.addConnectie(node2,"b");
        node2.addConnectie(node3,"b");
        node3.addConnectie(node3,"a");
        node3.addConnectie(node0,"b");
        node0.addConnectie(node2,"a");
        node0.addConnectie(node1,"b");
        //dit is een public variable zodat ik het makkelijk in de "test" kan laten zien aan jullie. Ik weet dat ik dit eigenlijk met get/set methodes zou moeten oproepen.
        System.out.println("node0 heeft deze connecties:"+ node0.connecties.keySet() + node0.connecties.values());
        System.out.println("node2 heeft deze connectie:"+ node2.connecties.keySet() + node2.connecties.values());
        node0.useNode("abbbbaababababababbabxaaab");

    }
}
