package com.testRefreshJavaMick;

public class pan {
    private int antiaanbaklaag= 80;
    public int getAntiaanbaklaag(){
        return this.antiaanbaklaag;
    }
    private int schoon = 60;

    public int getSchoon() {
        return this.schoon;
    }

    public void maakSchoon() {
        this.schoon = this.schoon+10;
    }
}
