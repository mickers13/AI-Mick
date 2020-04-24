package Summatief_1_deBanjo;


class Main {
    public static void main(String args[]){

        Bedrijf deBanjo = new Bedrijf();

        deBanjo.addMedewerkerToSysteem(new Directeur("Wim"));
        BoomPlanter Lucas = new BoomPlanter("Lucas");
        deBanjo.addMedewerkerToSysteem(Lucas);

        BoomPlanter Mick = new BoomPlanter("Mick");
        deBanjo.addMedewerkerToSysteem(Mick);

        Houthakker Henry = new Houthakker("Henry de Sterke.");
        deBanjo.addMedewerkerToSysteem(Henry);


        BosSector bossector1 = new BosSector();

        // een boom planten, zodat het geen nullpointer exception heeft, ik weet nog niet hoe je correct fouten afvangt in java.
        Lucas.plantBoom(new Wilg(),bossector1);
        Lucas.plantBoom(new Eik(),bossector1);
        Lucas.plantBoom(new Eik(),bossector1);
        System.out.println(bossector1.getBoom(-1));
        Lucas.plantBoom(new Berk(),bossector1);
        Mick.plantBoom(new Wilg(),bossector1);
        System.out.println(bossector1.getBoom(-1));
        Mick.plantBoom(new Wilg(),bossector1);
        Lucas.plantBoom(new Eik(),bossector1);
        Mick.plantBoom(new Wilg(),bossector1);
        System.out.println(bossector1.getBoom(1));
        System.out.println(bossector1.getBoom(-1));
        Henry.hak(1,bossector1);
    }
}