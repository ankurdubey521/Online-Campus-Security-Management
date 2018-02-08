/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypackage;
import java.util.Formatter;
import java.io.*;
import java.lang.*;
/**
 *
 * @author vinay
 */
public class madefile {
    private Formatter x; 
    public String l;
    public void openfile(String setid){
        try {l=setid;
        l = l.concat(".txt");
            x=new Formatter(l);
    }
        catch(Exception e){
            System.out.println("you have error");
        }
}
    public void addrecords(String id){
        x.format("%s\n",id);
    }
    public void closefile(){
        x.close();
}
}


