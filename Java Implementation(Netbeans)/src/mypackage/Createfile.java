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

    public class Createfile {
    private Formatter x; 
    public String s;
    public void openfile(String setid){
        try {s=setid;
        s = s.concat(".txt");
            x=new Formatter(s);
    }
        catch(Exception e){
            System.out.println("you have error");
        }
}
    public void addrecords(String rfname,String rlname,String rage,String rpass){
        x.format("%s\n%s\n%s\n%s\n",rfname,rlname,rage,rpass);
    }
    public void addr(String xv){
       x.format("%s\n",xv);
    }
    public void closefile(){
        x.close();
}
}
